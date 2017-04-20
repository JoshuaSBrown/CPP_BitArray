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
#include <memory>
#include <vector>
using namespace std;

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
 * int setElem(long long int elem)                                            *
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

typedef struct _Byte Byte;

class BitArray{
    private:
        shared_ptr<Byte> temp;
        long long int size;
    public:
        shared_ptr<vector<unsigned char>> array;
        BitArray(void);
        BitArray(int size);
        BitArray(long int size);
        BitArray(long long int size);
        void print(void);
        int getElem(const long long int elem);
        int setElem(const long long int elem);
        int unsetElem(const long long int elem);
        Byte& operator[](const long long int elem);
        Byte& operator[](const long int elem);
        Byte& operator[](const int elem);
     
        void operator=(BitArray &BitA);

        friend bool operator==(BitArray const &BitAL, BitArray const &BitAR);
        friend bool operator!=(BitArray const &BitAL, BitArray const &BitAR);
    
        void append(BitArray &BitA);
        int test_BitArrayInternal(void);

};

//void operator=(int &val, BitArray &BitAR);
//const TransitByte & operator [](const long long int i);
//TransitByte & operator [](const long long int i);

//void operator=(TransitByte &Tbyt, const int val);
//void operator=(int &val, const TransitByte &Tbyt);


struct _Byte{
     public:
         shared_ptr<BitArray> Mother;
         long long int elem_byte;
         unsigned char * uchar;
         unsigned index;
         Byte& operator=(Byte &byt);
         Byte& operator=(int ind);

         operator int();
 };

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
