/******************************************************************************
 * Created: 28 March 2017                                                     *
 * Author:  Joshua S Brown                                                    *
 *                                                                            *
 * Purpose: This library was designed to enable easy manipulation of an array *
 *          of bits.                                                          *
 *                                                                            *
 * Conventions:                                                               *
 *  size -            Used to refer to the total size of the array in bits.   *
 *  elem -            Used to refer to an element in the bit array.           *
 ******************************************************************************/

#ifndef _BITARRAY_HPP_
#define _BITARRAY_HPP_

#include <stdbool.h>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef char byte;

/******************************************************************************
 * Class Functions:                                                           *
 * Constructors                                                               *
 * BitArray(void)                                                             *
 *    Default Constructor used to create a bit array of 8 bits                *
 * BitArray(long long int size)                                               *
 *    Used to create a bit array of length equalt to size                     *
 *                                                                            *
 * Destructors                                                                *
 * ~BitArray(void)                                                            *
 *    Deletes object                                                          *
 *                                                                            *
 * Displayer                                                                  *
 * void print(void)                                                           *
 *    Prints the size and the contents of the bit array object                *
 *                                                                            *
 * Setters                                                                    *
 * int setElem(long long int elem)                                            *                *
 *    Sets the element of the bit array to a 1                                *
 *    The return value is an int:                                             *
 *    -1 - indicates there was an error and the element is out of bounds      *
 *     0 - indicates success                                                  *
 *                                                                            *
 * int unsetElem(long long int elem)                                          *
 *    This function does the same thing as setElem but it sets the value to a *
 *    0 as opposed to a 1. The return value is an int:                        *
 *    -1 - indicates there was an error and the element is out of bounds      *
 *     0 - indicates success                                                  *
 *                                                                            *
 * Getters                                                                    *
 * int getElem(long long int elem)                                            *
 *    This function gets the value of the element at index given by elem. The *
 *    return value can be either of three values:                             *
 *    -1 - indicates failure the elem is out of bounds                        *
 *     0 - indicates the value was set to 0                                   *
 *     1 - indicates the vlaue was set to 1                                   *
 *                                                                            *
 * Testers                                                                    *
 * int test_BitArrayInternal(void)                                            *
 *    This function test the internal class functions and ensures that they   *
 *    are functioning correctly. Return value is given as:                    *
 *    -1 - indicates failure to pass a test                                   *
 *     0 - indicates success                                                  *
 ******************************************************************************/

/*typedef struct _TransitByte TransitByte;

struct _TransitByte{
  public:
    byte * byt;
    long long int index;
    int operator=(const int val);
    void operator=(TransitByte Tbyt);
    //void operator=(BitArray BitA);
    //void operator=(int &val, const TransitByte &Tbyt);
    //const TransitByte & operator [](const long long int i) const;
    //friend TransitByte & operator [](const long long int i);
};
*/

struct Byte;

class BitArray{
    private:
        Byte temp;
        int size;
    public:
        unsigned char * array;
        BitArray(void);
        void print(void);
        Byte& operator[](const long long int index);
        Byte& operator[](const long int index);
        Byte& operator[](const int index);
     
        BitArray& operator=(BitArray BitA);
        
        friend bool operator==(BitArray const &BitAL, BitArray const &BitAR);
        friend bool operator!=(BitArray const &BitAL, BitArray const &BitAR);
    
        void append(BitArray &BitA);

};


//class BitArray{
//  private:
  /*  byte * array;
    long long int int_index;
    int temp;*/
//  public:
  /*  static unsigned long registers[8];
    const unsigned long operator [](int i) const
       {
           return registers[i];
       }
       unsigned long& operator [](int i)
          {
              return registers[i];
          }
    byte * array;
    long long int int_index;
    int temp;
    long long int size;
    BitArray(void);
    BitArray(long long int size);
    ~BitArray(void);
    void print(void);
    int setElem(const long long int elem);
    int unsetElem(const long long int elem);
    int getElem(const long long int elem);
    void append(BitArray &BitA);

    int test_BitArrayInternal(void);
    friend bool operator==(BitArray const &BitAL, BitArray const &BitAR);
    friend bool operator!=(BitArray const &BitAL, BitArray const &BitAR);
   */ /*const int operator[](const long long int i) const{
      this->int_index = i;
      this->temp = _getElem(this->array,i);
      return this->temp;
    }*/
   /* operator int() const{
      return this->temp;
    }
    //int& operator [] (const int i);
    //int& operator [] (const long long int i);
    void operator =(const BitArray &BitA);
    void operator =(const int val);
    //friend void operator=(int &val, BitArray &BitAR);
};
*/

//void operator=(int &val, BitArray &BitAR);
//const TransitByte & operator [](const long long int i);
//TransitByte & operator [](const long long int i);

//void operator=(TransitByte &Tbyt, const int val);
//void operator=(int &val, const TransitByte &Tbyt);


 /******************************************************************************
 * Library Functions:                                                         *
 * Testers                                                                    *
 * int test_BitArrayInternal(void)                                            *
 *    Function is designed to test internal functions that are not accessible *
 *    to the user. Return values are:                                         *
 *     0 - indicates success                                                  *
 *    -1 - indicates failure                                                  *
 ******************************************************************************/

#endif
