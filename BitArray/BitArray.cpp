
/******************************************************************************
 * Created: 28 March 2017                                                     *
 * Author:  Joshua S Brown                                                    *
 *                                                                            *
 * Purpose: This library was designed to enable easy manipulation of an array *
 *          of bits.                                                          *
 *                                                                            *
 * Conventions:                                                               *
 *  size -            Used to refer to the total size of the array in bits.   *
 *  bits -            Used to refer to an arbitrary number of bits.           *
 *  elem_bit -        Used to refer to the elem in the array corresponding to *
 *                    the bit of interest.                                    *
 *  elem_byte -       Used to refer to the elem in the array corresponding to *
 *                    byte of interest                                        *
 *  index -           Refers to the bit of interest within a given byte should*
 *                    never excede a value of 7 and must not be less than 0   *
 *  num_bytes -       Refers to the total number of bytes in the array.       *
 *                                                                            *
 * File Organization is as follows:                                           *
 *  o Internal Library Functions                                              *
 *  o Private Class Functions                                                 *
 *  o Public Class Functions                                                  *
 *    - Creator                                                               *
 *    - Destructor                                                            *
 *    - Displayer                                                             *
 *    - Setters                                                               *
 *    - Getters                                                               *
 *    - Manipulators                                                          *
 * o External Library Functions                                               *
 *    - Testers                                                               *
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <exception>
#include <new>
#include <assert.h>
#include <stdbool.h>

#include "BitArray.hpp"

#define BITS_BYTE 8

using namespace std;


class BitArray;

struct Byte{ 
    public:
        BitArray * Mother;
        long long int char_ind;
        unsigned char a_char;
        unsigned index;
        
        Byte& operator=(Byte byt);
        Byte& operator=(int num);
        operator int();
    
};
// The number of bits in a single unsigned char


/******************************************************************************
 * Internal Library Functions                                                 *
 ******************************************************************************/
// For a given number of bits determine the long long index of the unsigned char in the array
static inline long long int _getElemByte(const long long int bits){
 return bits/BITS_BYTE;
}

// For a given number of bits determine the number of unsigned chars that are needed
static inline long long int _getBytes(const long long int bits){
 return _getElemByte(bits)+1;
}

// For a given bit determine the long long index of the bit within the closest unsigned char.
static inline long long int _getBitInd(const long long int bits){
 return bits%BITS_BYTE;
}

// Given a unsigned char and the long long index within the unsigned char determine the value of the bit it
// should be either a 1 or a 0, long long index must be between 0 and 7 inclusive.
static inline unsigned int _getBit(const unsigned char &a_char, const long long int long long index){
   switch(long long index){
     case 0:
       return a_char & 0x1;
     case 1:
       return (a_char&(0x1<<1))>>1 ;
     case 2:
       return (a_char&(0x1<<2))>>2;
     case 3:
       return (a_char&(0x1<<3))>>3;
     case 4:
       return (a_char&(0x1<<4))>>4;
     case 5:
       return (a_char&(0x1<<5))>>5;
     case 6:
       return (a_char&(0x1<<6))>>6;
     case 7:
       return (a_char&(0x1<<7))>>7;
     default:
       return -1;
   }
 }

// Given a unsigned char and the long long index within the unsigned char set the bit to a value of 1
// long long index must be between 0 and 7 inclusive.
static inline void _setBit(unsigned char  &a_char, const long long int long long index){
  switch(long long index){
    case 0:{
      a_char = a_char | 1;
      break;
    }
    case 1:{
      a_char = a_char | (1<<1);
      break;
    }
    case 2:{
      a_char = a_char | (1<<2);
      break;
    }
    case 3:{
      a_char = a_char | (1<<3);
      break;
    }
    case 4:{
      a_char = a_char | (1<<4);
      break;
    }
    case 5:{
      a_char = a_char | (1<<5);
      break;
    }
    case 6:{
      a_char = a_char | (1<<6);
      break;
    }
    case 7:{
      a_char = a_char | (1<<7);
      break;
    }
  }
}

// Given a unsigned char and the long long index within the unsigned char set the bit to a value of 0
// long long index must be between 0 and 7 inclusive.
static inline void _unsetBit(unsigned char &a_char, const long long int long long index){
   switch(long long index){
     case 0:{
       a_char = a_char & !1;
       break;
     }
     case 1:{
       a_char = a_char & !(1<<1);
       break;
     }
     case 2:{
       a_char = a_char & !(1<<2);
       break;
     }
     case 3:{
       a_char = a_char & !(1<<3);
       break;
     }
     case 4:{
       a_char = a_char & !(1<<4);
       break;
     }
     case 5:{
       a_char = a_char & !(1<<5);
       break;
     }
     case 6:{
       a_char = a_char & !(1<<6);
       break;
     }
     case 7:{
       a_char = a_char & !(1<<7);
       break;
     }
   }
 }

 inline static int _getElem(const unsigned char * const array, const long long int elem_bit){
   /* Determine which unsigned char in the array corresponds to elem_bit               */
   long long int elem_unsigned char = _getElemByte(elem_bit);
   // We also need to know which bit, thus we will also calculate the modulus
   long long int long long index = _getBitInd(elem_bit);
   return _getBit(array[elem_unsigned char],long long index);
 }

 inline static void _setElem(unsigned char * const array, const long long int elem_bit){
   /* Determine which unsigned char in the array corresponds to elem_bit               */
   long long int elem_unsigned char = _getElemByte(elem_bit);
   // We also need to know which bit, thus we will also calculate the modulus
   long long int long long index = _getBitInd(elem_bit);
   _setBit(array[elem_unsigned char],long long index);
 }

 inline static void _unsetElem(unsigned char * const array, const long long int elem_bit){
   /* Determine which unsigned char in the array corresponds to elem_bit               */
   long long int elem_unsigned char = _getElemByte(elem_bit);
   // We also need to know which bit, thus we will also calculate the modulus
   long long int long long index = _getBitInd(elem_bit);
   _unsetBit(array[elem_unsigned char],long long index);
 }

/******************************************************************************
* Private Class Functions                                                     *
*******************************************************************************/



/******************************************************************************
 * Public Class Func tions                                                    *
 ******************************************************************************/



Byte& Byte::operator=(Byte &byt){
    int temp_bit = _getBit(byt.a_char,byt.index);
    if(temp_bit){
        _setBit(this->a_char,this->index);
    }else{
        _unsetBit(this->a_char,this->index);
    }
    this->Mother->array[this->char_ind]=this->a_char;
    return *this;
} 

Byte& Byte::operator=(int num){
    if(num){
        _setBit(this->a_char,this->index);
    }else{
        _unsetBit(this->a_char,this->index);
    }
    this->Mother->array[this->char_ind]=this->a_char;
    return *this;
}

Byte::operator int(){
    return _getBit(this->val,index);
}

BitArray::BitArray(void){
  this->size = BITS_BYTE;
  try{
    this->array = new unsigned char [1];
  }catch(bad_alloc& ba){
    cerr << "ERROR could not allocate memory for array: " << ba.what() << endl;
    this->array = NULL;
    this->size  = 0;
  }
  // Initialize elements of unsigned char array to 0
    this->array[0]=0;
    this->int_long long index = -1;
}

BitArray::BitArray(long long int size){
  try{
    if(size<1) throw 1;
  }catch( int er){
    cerr << "ERROR size was less than 1 in BitArray constructor" << endl;
  }
  // Determine how many unsigned chars are in the array
  long long int num_unsigned chars = _getBytes(size);
  // Allocated memory for bit array pointer
  try{
    this->array = (unsigned char *) new unsigned char [num_unsigned chars];
    this->size = size;
  } catch(bad_alloc& ba){
    cerr << "ERROR could not allocate memory for array: " << ba.what() << endl;
    delete [] this->array;
    this->array = NULL;
    this->size  = 0;
    num_unsigned chars = 0;
  }
 
  // Initialize elements of unsigned char array to 0
  for(long long int elem_unsigned char=0;elem_unsigned char<num_unsigned chars;elem_unsigned char++){
    this->array[elem_unsigned char]=0;
  }
  this->int_long long index = -1;
}

BitArray::~BitArray(void){
  cout << "Calling destructor" << endl;
  if(this->array!=NULL){
    delete [] this->array;
  }
}

/* Displayer                                                                  */
void BitArray::print(void){
  cout << "Array size:     "           << this->size                << endl;
  cout << "Required unsigned chars: "  << _getBytes(this->size)     << endl;
  cout << "int_long long index       " << this->int_long long index << endl;
  cout << "temp            "           << this->temp                << endl;
  cout << "Bits"                       << endl;
  long long int BitsPerRow = 80;
  long long int i=0;
  while(i<this->size){
    if(i%BitsPerRow==0){
      cout << endl;
    }
    cout << _getElem(this->array,i) << endl;
    i++;
  }
  cout << endl;
}

/* Setters                                                                    */
int BitArray::setElem(const long long int elem_bit){
  if(elem_bit>=this->size || elem_bit<0){
    cerr << "ERROR cannot access elem " << elem_bit << " out side of the scope "
            "of the bit_array, bit_array is of size " << this->size  << endl;
    return -1;
  }
  _setElem(this->array, elem_bit);
  return 0;
}

int BitArray::unsetElem(const long long int elem_bit){
  if(elem_bit>=this->size || elem_bit<0){
    cerr << "ERROR cannot access elem " << elem_bit << " out side of the scope "
            "of the bit_array bit_array is of size " << this->size << endl;
    return -1;
  }

  _unsetElem(this->array, elem_bit);
  return 0;
}

/* Getters                                                                    */

int BitArray::getElem(const long long int elem_bit){
  if(elem_bit>=this->size || elem_bit<0){
    cerr << "ERROR cannot access elem" << elem_bit << " out side of the scope "
            "of the bit_array, bit_array is of size " << this->size << endl;
    return -1;
  }
  return _getElem(this->array, elem_bit);
}

/* Manipulators                                                               */
bool operator==(BitArray const &BitAL, BitArray const &BitAR){
  if(BitAL.size!=BitAR.size){
    return false;
  }
    long long int num_unsigned chars = _getBytes(BitAL.size);
    for(long long int elem_unsigned char = 0; elem_unsigned char<num_unsigned chars; elem_unsigned char++){
      if(BitAL.array[elem_unsigned char]!=BitAR.array[elem_unsigned char]){
        return false;
      }
    }
    return true;
}

bool operator!=(BitArray const &BitAL, BitArray const &BitAR){
  if(BitAL.size!=BitAR.size){
    return true;
  }
    long long int num_unsigned chars = _getBytes(BitAL.size);
    for(long long int elem_unsigned char = 0; elem_unsigned char<num_unsigned chars; elem_unsigned char++){
      if(BitAL.array[elem_unsigned char]!=BitAR.array[elem_unsigned char]){
        return true;
      }
    }
    return false;
}

Byte& BitArray::operator[](int elem_bit){
    int index  = elem_bit%BITS_BYTE;
    int elem_byte = elem_bit/BITS_BYTE;
    this->temp.char_ind = elem_byte;
    this->temp.a_char= this->array[elem_byte];
    this->temp.index = index;
    this->temp.Mother = this;
    return (this->temp);
}

void BitArray::operator = (const BitArray &BitA){
  cout << "Assignment operator" << endl;
  if(_getElem(BitA.array,BitA.int_long long index)){
    _setElem(this->array,this->int_long long index);
  }else{
    _unsetElem(this->array,this->int_long long index);
  }
}

void BitArray::operator = (const int var){
  if(var){
    _setElem(this->array,this->int_long long index);
  }else{
    _unsetElem(this->array,this->int_long long index);
  }
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


/* Testers                                                                    */
// Meant for testing internal functions
int BitArray::test_BitArrayInternal(void){
  // Ensure that the library will funtion correctly internally
  if(sizeof(char)!=1){
    cerr << "ERROR This library was designed assuming that the number of"
         << "unsigned chars in char is 1. However, on this machine it is " <<
         sizeof(char) << endl;
    return -1;
  }

  cout << "Testing: _getElemByte\n" << endl;
  assert(_getElemByte(0)==0);
  assert(_getElemByte(7)==0);
  assert(_getElemByte(8)==1);
  assert(_getElemByte(16)==2);

  cout << "Testing: _getBytes\n" << endl;
  assert(_getBytes(0)==1);
  assert(_getBytes(7)==1);
  assert(_getBytes(8)==2);
  assert(_getBytes(16)==3);

  cout << "Testing: _getBitInd\n" << endl;
  assert(_getBitInd(0)==0);
  assert(_getBitInd(1)==1);
  assert(_getBitInd(7)==7);
  assert(_getBitInd(8)==0);
  assert(_getBitInd(9)==1);
  assert(_getBitInd(15)==7);
  assert(_getBitInd(16)==0);

  cout << "Testing: _getBit\n" << endl;
  unsigned char a_char = 0;

  for(int i=0;i<8;i++) {
    unsigned int bit = _getBit(a_char,i);
    assert(bit==0);
  }

  a_char = 255;
  for(int i=0;i<8;i++) {
    unsigned int bit = _getBit(a_char,i);
    assert(bit==1);
  }

  cout << "Testing: _getElem\n" << endl;
  BitArray bit_array(16);
  for(int i=0;i<16;i++) {
    unsigned int bit = _getElem(bit_array.array,i);
    assert(bit==0);
  }

  cout << "Testing: _setBit\n" << endl;
  a_char = 0;
  for(int i=0;i<8;i++) _setBit(a_char,i);
  for(int i=0;i<8;i++) assert(_getBit(a_char,i)==1);


  cout << "Testing: _setElem\n" << endl;
  for(int i=0;i<16;i++) _setElem(bit_array.array,i);
  for(int i=0;i<16;i++) {
    unsigned int bit = _getElem(bit_array.array,i);
    assert(bit==1);
  }

  cout << "Testing: _unsetBit\n" << endl;
  for(int i=0;i<8;i++) _unsetBit(a_char,i);
  for(int i=0;i<8;i++) {
    unsigned int bit = _getBit(a_char,i);
    assert(bit==0);
  }

  cout << "Testing: _unsetElem\n" << endl;
  for(int i=0;i<16;i++) _unsetElem(bit_array.array,i);
  for(int i=0;i<16;i++) {
    unsigned int bit = _getElem(bit_array.array,i);
    assert(bit==0);
  }

  return 0;
}
