#include <stdbool.h>
#include <iostream>
#include <cstdlib>

#define BITS 8

class BitArray;

using namespace std;

struct Byte{
    public:
        BitArray * Mother;
        unsigned char val;
        int index;
        int char_ind;
        Byte& operator=(Byte byt);
        Byte& operator=(int num);
        operator int();
};


static inline int _getElemByte(const int bits){
 return bits/BITS;
}

// For a given number of bits determine the number of bytes that are needed
static inline int _getBytes(const int bits){
 return _getElemByte(bits)+1;
}

// For a given bit determine the index of the bit within the closest byte.
static inline int _getBitInd(const int bits){
 return bits%BITS;
}

static inline int _getBit(const unsigned char &val, const int index){
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

static inline void _setBit(unsigned char  &val, const int index){
   cout << "unset index " << index << endl;
  switch(index){
    case 0:{
      val = val | 1;
       cout << "case 0 " << (int)val << endl;
      break;
    }
    case 1:{
      val = val | (1<<1);
       cout << "case 1 " << (int)val << endl;
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


static inline void _unsetBit(unsigned char &val, const int index){
   cout << "unset index " << index << endl;
   switch(index){
     case 0:{
       val = val & !1;
       cout << "case 0 " << (int)val << endl;
       break;
     }
     case 1:{
       val = val & !(1<<1);
       cout << "case 1 " << (int)val << endl;
       break;
     }
     case 2:{
       val = val & !(1<<2);
       break;
     }
     case 3:{
       val = val & !(1<<3);
       break;
     }
     case 4:{
       val = val & !(1<<4);
       break;
     }
     case 5:{
       val = val & !(1<<5);
       break;
     }
     case 6:{
       val = val & !(1<<6);
       break;
     }
     case 7:{
       val = val & !(1<<7);
       break;
     }
   }
}


inline static int _getElem(const unsigned char * const array, const int elem_bit){
    /* Determine which byte in the array corresponds to elem_bit               */
    int elem_byte = _getElemByte(elem_bit);
    // We also need to know which bit, thus we will also calculate the modulus
    int index = _getBitInd(elem_bit);
    return _getBit(array[elem_byte],index);
}

inline static void _setElem(unsigned char * const array, const int elem_bit){
    /* Determine which byte in the array corresponds to elem_bit               */
    int elem_byte = _getElemByte(elem_bit);
    // We also need to know which bit, thus we will also calculate the modulus
    int index = _getBitInd(elem_bit);
    _setBit(array[elem_byte],index);
}

inline static void _unsetElem(unsigned char * const array, const int elem_bit){
    /* Determine which byte in the array corresponds to elem_bit               */
    int elem_byte = _getElemByte(elem_bit);
    // We also need to know which bit, thus we will also calculate the modulus
    int index = _getBitInd(elem_bit);
    _unsetBit(array[elem_byte],index);
}

class BitArray{
    private:
        Byte temp;
        int size;
    public:
        unsigned char * array;
        BitArray(void);
        ~BitArray(void);
        void print(void);
        Byte& operator[](int index);
        BitArray& operator=(BitArray ba);
        void append(BitArray &BitA);
};

Byte& Byte::operator=(Byte byt){
    // Step 1 determine if bit element is 0 or 1
    cout << "Byte equals Byte" << endl;
    int temp = _getBit(byt.val,byt.index);
    if(temp){
        _setBit(this->val,this->index);
    }else{  
        _unsetBit(this->val,this->index);
    }
    this->Mother->array[this->char_ind]=temp; 
    return *this;
}

Byte& Byte::operator=(int num){

    cout << "operator=(int) num " << num << endl;
    if(num!=0){
        _setBit(this->val,this->index);
    }else{  
        _unsetBit(this->val,this->index);
    }
    cout << "Bit " << _getBit(this->val,this->index) << endl; 
    this->Mother->array[this->char_ind]=this->val; 
    return *this;
}

Byte::operator int(){
    return _getBit(this->val,index);
}

BitArray::BitArray(void){
    this->size = BITS*2;
    this->array = (unsigned char *) new unsigned char[2];
    this->array[0]=0;
    this->array[0]=0;
}

BitArray::~BitArray(void){
    delete [] this->array;
}

void BitArray::print(void){
    cout << "Size " << this->size << "\n" << endl;
    int counter = 0;
    for(int i=0;i<(this->size)/BITS;i++){
        unsigned char c = this->array[i];
        for(int j=0;j<8;j++,counter++){
            if(counter>this->size) return;
            cout << counter << " " << _getBit(c,j)  << endl;
        }
    }
}

Byte& BitArray::operator[](int index){
    cout << "Bracket " << endl;
    int ind = index%BITS;
    int elem = index/BITS;
    this->temp.char_ind = elem;
    this->temp.val = (this->array[elem]);
    this->temp.index = ind;
    this->temp.Mother=this;
    return (this->temp);
}


void BitArray::append(BitArray &BitA){

    int num_bytes = (this->size+BitA.size)/BITS+1;
    unsigned char * array_new;
    try{
        array_new = (unsigned char *) new unsigned char [num_bytes];
    }catch(bad_alloc& ba){
        cerr << "ERROR could not allocate memory for array: " << ba.what() << endl;
    }
    
    num_bytes = (this->size)/BITS+1;
    
    int count;
    for( count = 0; count<num_bytes;count++){
        array_new[count] = this->array[count];
    }

    int bit_index = (count-1)*BITS+(this->size-(count-1)*BITS);
    delete [] this->array;
    this->array = array_new;
    this->size  = bit_index+BitA.size;
    
    for(int bit_index2 = 0;bit_index2<BitA.size;bit_index2++,bit_index){
        if(_getElem(BitA.array,bit_index2)){
            _setElem(this->array,bit_index);
        }else{
            _unsetElem(this->array,bit_index);
        }
    }

}


int main(void){
    
    BitArray ba;
    
    ba.print();

    ba[0] = 0;
    ba[1] = 1;
    ba[12] = 1;
    ba.print();
    BitArray ba2;
   
    ba.append(ba2);
    ba.print(); 

    int var = 0;
    var = int(ba[1]);
    cout << "var " << var << endl;
    return 0;
}
