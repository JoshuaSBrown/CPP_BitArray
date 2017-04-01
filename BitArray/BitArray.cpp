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
 * o External Library Functions                                               *
 *    - Testers                                                               *                           *
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <exception>
#include <new>

#include "BitArray.hpp"

typedef long long int ind;

using namespace std;

// The number of bits in a single byte
#define BITS_BYTE 8

/******************************************************************************
 * Internal Library Functions                                                 *
 ******************************************************************************/
// For a given number of bits determine the index of the byte in the array
static inline ind _getElemByte(const ind bits){
 return bits/BITS_BYTE;
}

// For a given number of bits determine the number of bytes that are needed
static inline ind _getBytes(const ind bits){
 return _getElemByte(bits)+1;
}

// For a given bit determine the index of the bit within the closest byte.
static inline ind _getBitInd(const ind bits){
 return bits%BITS_BYTE;
}

// Given a byte and the index within the byte determine the value of the bit it
// should be either a 1 or a 0, index must be between 0 and 7 inclusive.
static inline unsigned int _getBit(const byte * byt, const ind index){
   switch(index){
     case 0:
       return *byt & 0x1;
     case 1:
       return (*byt&(0x1<<1))>>1 ;
     case 2:
       return (*byt&(0x1<<2))>>2;
     case 3:
       return (*byt&(0x1<<3))>>3;
     case 4:
       return (*byt&(0x1<<4))>>4;
     case 5:
       return (*byt&(0x1<<5))>>5;
     case 6:
       return (*byt&(0x1<<6))>>6;
     case 7:
       return (*byt&(0x1<<7))>>7;
     default:
       return -1;
   }
 }

// Given a byte and the index within the byte set the bit to a value of 1
// index must be between 0 and 7 inclusive.
static inline void _setBit(byte * byt, const ind index){
  switch(index){
    case 0:{
      *byt = *byt | 1;
      break;
    }
    case 1:{
      *byt = *byt | (1<<1);
      break;
    }
    case 2:{
      *byt = *byt | (1<<2);
      break;
    }
    case 3:{
      *byt = *byt | (1<<3);
      break;
    }
    case 4:{
      *byt = *byt | (1<<4);
      break;
    }
    case 5:{
      *byt = *byt | (1<<5);
      break;
    }
    case 6:{
      *byt = *byt | (1<<6);
      break;
    }
    case 7:{
      *byt = *byt | (1<<7);
      break;
    }
  }
}

// Given a byte and the index within the byte set the bit to a value of 0
// index must be between 0 and 7 inclusive.
static inline void _unsetBit(byte * byt, const ind index){
   switch(index){
     case 0:{
       *byt = *byt ^ 1;
       break;
     }
     case 1:{
       *byt = *byt ^ (1<<1);
       break;
     }
     case 2:{
       *byt = *byt ^ (1<<2);
       break;
     }
     case 3:{
       *byt = *byt ^ (1<<3);
       break;
     }
     case 4:{
       *byt = *byt ^ (1<<4);
       break;
     }
     case 5:{
       *byt = *byt ^ (1<<5);
       break;
     }
     case 6:{
       *byt = *byt ^ (1<<6);
       break;
     }
     case 7:{
       *byt = *byt ^ (1<<7);
       break;
     }
   }
 }

 inline static int _getElem(const byte * byt,const ind elem_bit){
   /* Determine which byte in the array corresponds to elem_bit               */
   ind elem_byte = _getElemByte(elem_bit);
   // We also need to know which bit, thus we will also calculate the modulus
   ind index = _getBitInd(elem_bit);
   return _getBit(&(byt[elem_byte]),index);
 }

 inline static void _setElem(byte * byt, const ind elem_bit){
   /* Determine which byte in the array corresponds to elem_bit               */
   ind elem_byte = _getElemByte(elem_bit);
   // We also need to know which bit, thus we will also calculate the modulus
   ind index = _getBitInd(elem_bit);
   _setBit(&(byt[elem_byte]),index);
 }

 inline static void _unsetElem(byte * byt, const ind elem_bit){
   /* Determine which byte in the array corresponds to elem_bit               */
   ind elem_byte = _getElemByte(elem_bit);
   // We also need to know which bit, thus we will also calculate the modulus
   ind index = _getBitInd(elem_bit);
   _unsetBit(&(byt[elem_byte]),index);
 }

/******************************************************************************
* Private Class Functions                                                     *
*******************************************************************************/



/******************************************************************************
 * Public Class Func tions                                                    *
 ******************************************************************************/
BitArray::BitArray(void){
  this->size = 8;
  // Determine how many bytes are in the array
  ind num_bytes = _getBytes(size);
  try{
    this->array = new byte [1];
  }catch(bad_alloc& ba){
    cerr << "ERROR could not allocate memory for array: " << ba.what() << endl;
    this->array = NULL;
    this->size  = 0;
    num_bytes = 0;
  }
  // Initialize elements of byte array to 0
  for(ind elem_byte=0;elem_byte<num_bytes;elem_byte++){
    this->array[elem_byte]=0;
  }
}

BitArray::BitArray(ind size){
  try{
    if(size<1) throw 1;
  }catch( int er){
    cerr << "ERROR size was less than 1 in BitArray constructor" << endl;
  }
  // Determine how many bytes are in the array
  ind num_bytes = _getBytes(size);
  // Allocated memory for bit array pointer
  try{
    this->array = (byte *) new byte [num_bytes];
    this->size = size;
  } catch(bad_alloc& ba){
    cerr << "ERROR could not allocate memory for array: " << ba.what() << endl;
    delete [] this->array;
    this->array = NULL;
    this->size  = 0;
    num_bytes = 0;
  }
  // Initialize elements of byte array to 0
  for(ind elem_byte=0;elem_byte<num_bytes;elem_byte++){
    this->array[elem_byte]=0;
  }

}

BitArray::~BitArray(void){
  if(this->array!=NULL){
    delete [] this->array;
  }
}

/* Displayer                                                                  */
void BitArray::print(void){
  cout << "Array size:     " << this->size << endl;
  cout << "Required bytes: " << _getBytes(this->size) << endl;
  cout << "Bits" << endl;
  ind BitsPerRow = 80;
  ind i=0;
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
int BitArray::setElem(const ind elem_bit){
  if(elem_bit>=this->size || elem_bit<0){
    cerr << "ERROR cannot access elem " << elem_bit << " out side of the scope "
            "of the bit_array, bit_array is of size " << this->size  << endl;
    return -1;
  }
  _setElem(this->array, elem_bit);
  return 0;
}

int BitArray::unsetElem(const ind elem_bit){
  if(elem_bit>=this->size || elem_bit<0){
    cerr << "ERROR cannot access elem " << elem_bit << " out side of the scope "
            "of the bit_array bit_array is of size " << this->size << endl;
    return -1;
  }

  _unsetElem(this->array, elem_bit);
  return 0;
}

/* Getters                                                                    */
int BitArray::getElem(const int elem_bit){
  if(elem_bit>=this->size || elem_bit<0){
    cerr << "ERROR cannot access elem" << elem_bit << " out side of the scope "
            "of the bit_array, bit_array is of size " << this->size << endl;
    return -1;
  }
  return _getElem(this->array, elem_bit);
}


/* Testers                                                                    */
// Meant for testing internal functions
int test_BitArrayInternal(void){
  // Ensure that the library will funtion correctly internally
  if(sizeof(char)!=1){
    fprintf(stderr,"ERROR This library was designed assuming that the number of"
                   "bytes in char is 1. However, on this machine it is %ld\n",
                   sizeof(char));
    return -1;
  }

  printf("Testing: _getElemByte\n");
  assert(_getElemByte(0)==0);
  assert(_getElemByte(7)==0);
  assert(_getElemByte(8)==1);
  assert(_getElemByte(16)==2);

  printf("Testing: _getBytes\n");
  assert(_getBytes(0)==1);
  assert(_getBytes(7)==1);
  assert(_getBytes(8)==2);
  assert(_getBytes(16)==3);

  printf("Testing: _getBitInd\n");
  assert(_getBitInd(0)==0);
  assert(_getBitInd(1)==1);
  assert(_getBitInd(7)==7);
  assert(_getBitInd(8)==0);
  assert(_getBitInd(9)==1);
  assert(_getBitInd(15)==7);
  assert(_getBitInd(16)==0);

  printf("Testing: _getBit\n");
  byte byt = 0;
  for(int i=0;i<8;i++) assert(_getBit(byt,0)==0);

  byt = 255;
  for(int i=0;i<8;i++) assert(_getBit(byt,i)==1);

  printf("Testing: _getElem\n");
  BitArray bit_array(16);
  assert(bit_array!=NULL);
  for(int i=0;i<16;i++) assert(_getElem(bit_array,i)==0);

  printf("Testing: _setBit\n");
  for(int i=0;i<8;i++) _setBit(&byt,i);
  for(int i=0;i<8;i++) assert(_getBit(byt,i)==1);

  printf("Testing: _setElem\n");
  for(int i=0;i<16;i++) _setElem(bit_array,i);
  for(int i=0;i<16;i++) assert(_getElem(bit_array,i)==1);

  printf("Testing: _unsetBit\n");
  for(int i=0;i<8;i++) _unsetBit(&byt,i);
  for(int i=0;i<8;i++) assert(_getBit(byt,i)==0);

  printf("Testing: _unsetElem\n");
  for(int i=0;i<16;i++) _unsetElem(bit_array,i);
  for(int i=0;i<16;i++) assert(_getElem(bit_array,i)==0);

  deleteBitArray(&bit_array);

  return 0;
}
