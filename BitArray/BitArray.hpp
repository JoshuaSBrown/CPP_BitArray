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
 ******************************************************************************/

class BitArray{
  private:
    byte * array;
  public:
    long long int size;
    BitArray(void);
    BitArray(long long int size);
    ~BitArray(void);
    void print(void);
    int setElem(const long long int elem);
    int unsetElem(const long long int elem);
    int getElem(const long long int elem);
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
int test_BitArrayInternal(void);
#endif
