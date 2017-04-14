#include <stdbool.h>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Byte{
    public:
        char val;
        int index;
        Byte& operator=(Byte byt);
};

static inline int _getBit(const char &val, const int index){
   switch(index){
     case 0:
       return val & 0x1;
     case 1:
       return (val&(0x1<<1))>>1 ;
     case 2:
       return (val&(0x1<<2))>>2;
     case 3:
       return (val&(0x1<<3))>>3;
     case 4:
       return (val&(0x1<<4))>>4;
     case 5:
       return (val&(0x1<<5))>>5;
     case 6:
       return (val&(0x1<<6))>>6;
     case 7:
       return (val&(0x1<<7))>>7;
     default:
       return -1;
   }
}

static inline void _setBit(char  &val, const int index){
  switch(index){
    case 0:{
      val = val | 1;
      break;
    }
    case 1:{
      val = val | (1<<1);
      break;
    }
    case 2:{
      val = val | (1<<2);
      break;
    }
    case 3:{
      val = val | (1<<3);
      break;
    }
    case 4:{
      val = val | (1<<4);
      break;
    }
    case 5:{
      val = val | (1<<5);
      break;
    }
    case 6:{
      val = val | (1<<6);
      break;
    }
    case 7:{
      val = val | (1<<7);
      break;
    }
  }
}


static inline void _unsetBit(char &val, const int index){
   switch(index){
     case 0:{
       val = val ^ 1;
       break;
     }
     case 1:{
       val = val ^ (1<<1);
       break;
     }
     case 2:{
       val = val ^ (1<<2);
       break;
     }
     case 3:{
       val = val ^ (1<<3);
       break;
     }
     case 4:{
       val = val ^ (1<<4);
       break;
     }
     case 5:{
       val = val ^ (1<<5);
       break;
     }
     case 6:{
       val = val ^ (1<<6);
       break;
     }
     case 7:{
       val = val ^ (1<<7);
       break;
     }
   }
}


Byte& Byte::operator=(Byte byt){
    // Step 1 determine if bit element is 0 or 1
    int temp = _getBit(byt.val,byt.index);
    if(temp){
        _setBit(this->val,this->index);
    }else{  
        _unsetBit(this->val,this->index);
    } 
    return *this;
}

class BitArray{
    private:
        char * temp;
        char * array;
        int size;
    public:
        BitArray(void);
        ~BitArray(void);
        void print(void);
        char& operator[](int index);
        BitArray& operator=(BitArray ba);
};

BitArray::BitArray(void){
    this->size = sizeof(char)*2;
    this->array = (char *) new char[2];
    this->array[0]=0;
    this->array[0]=0;
}

BitArray::~BitArray(void){
    delete [] this->array;
}

void BitArray::print(void){
    cout << "Size " << this->size << "\n" << endl;
    for(int i=0;i<(this->size)/sizeof(char);i++){
        char c = this->array[i];
        cout << i << " " << c  << endl;
    }
}

char& BitArray::operator[](int index){
    char * temp = &(this->array[index]);
    return (*temp);
}

int main(void){
    
    BitArray ba;
    
    ba.print();

    ba[0] = 100;
    ba[1] = 101;

    ba.print();
    return 0;
}
