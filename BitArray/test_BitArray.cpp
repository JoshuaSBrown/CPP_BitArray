#include <iostream>
#include <climits>
#include <cstdlib>
#include <new>

#include "BitArray.hpp"

using namespace std;

int main(void){

  try {
    /* all of your code goes here */

    cout << "Beginning Test of BitArray Library\n" << endl;

    cout << "Testing: BitArray constructors and destructors" << endl;
    BitArray * BA = new BitArray();
    delete BA;
    BitArray * BA2 = new BitArray(5);
    delete BA2;
    BitArray * BA3 = new BitArray(-1);
    delete BA3;

    cout << "Testing: BitArray displayer" << endl;
    //BitArray * BA4 = new BitArray(72036854775807);
    //delete BA4;

  } catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    return 1;
  } catch(...) {
    cerr << "error: unknown exceptions" << endl;
    return 1;
  }
  return 0;
}
