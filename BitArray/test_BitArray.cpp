#include <iostream>
#include <climits>
#include <cstdlib>
#include <new>
#include <assert.h>
#include <stdbool.h>

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

    cout << "Testing: BitArray internal functions" << endl;
    BA = new BitArray(4);
    BA->test_BitArrayInternal();
    delete BA;

    cout << "Testing: BitArray displayer" << endl;
    BA = new BitArray(12);
    BA->print();
    delete BA;

    cout << "Testing: BitArray setElem" << endl;
    BA = new BitArray(17);
    int rv = BA->setElem(17);
    assert(rv==-1);
    rv = BA->setElem(-1);
    assert(rv==-1);
    rv = BA->setElem(0);
    assert(rv==0);
    rv = BA->setElem(16);
    assert(rv==0);
    delete BA;

    cout << "Testing: BitArray getElem" << endl;
    BA = new BitArray(18);
    rv = BA->getElem(-1);
    assert(rv==-1);
    rv = BA->getElem(18);
    assert(rv==-1);
    rv = BA->getElem(17);
    assert(rv==0);
    rv = BA->getElem(0);
    assert(rv==0);
    rv = BA->setElem(1);
    assert(rv==0);
    rv = BA->getElem(1);
    assert(rv==1);
    rv = BA->getElem(2);
    assert(rv==0);
    rv = BA->setElem(17);
    assert(rv==0);
    rv = BA->getElem(17);
    assert(rv==1);
    rv = BA->getElem(16);
    assert(rv==0);
    delete BA;

    cout << "Testing: BitArray unsetElem" << endl;
    BA = new BitArray(21);
    rv = BA->unsetElem(-1);
    assert(rv==-1);
    rv = BA->unsetElem(21);
    assert(rv==-1);
    for(long long int i=0;i<21;i++){
      BA->setElem(i);
      rv = BA->getElem(i);
      assert(rv==1);
    }
    for(long long int i=0;i<21;i++){
      rv = BA->unsetElem(i);
      assert(rv==0);
      rv = BA->getElem(i);
      cout << "i " << i << " rv " << rv << endl;
      assert(rv==0);
    }
    delete BA;


    cout << "Testing: BitArray operators ==" << endl;
    BA = new BitArray();
    bool ans = (BA==BA);
    assert(ans==true);
    BA2 = new BitArray(21);
    ans = (BA==BA2);
    assert(ans==false);
    BA->setElem(4);
    ans = (BA==BA);
    assert(ans==true);
    BA3 = new BitArray();
    BA3->setElem(4);
    ans = (BA==BA3);
    assert(ans==false);
    delete BA;
    delete BA2;
    delete BA3;

    cout << "Testing: BitArray operators !=" << endl;
    BA = new BitArray();
    ans = (BA!=BA);
    assert(ans==false);
    BA2 = new BitArray(21);
    ans = (BA!=BA2);
    assert(ans==true);
    BA->setElem(4);
    ans = (BA!=BA);
    assert(ans==false);
    BA3 = new BitArray();
    BA3->setElem(4);
    ans = (BA!=BA3);
    assert(ans==true);
    delete BA;
    delete BA2;
    delete BA3;

  } catch (exception& e) {
    cerr << "error: " << e.what() << endl;
    return 1;
  } catch(...) {
    cerr << "error: unknown exceptions" << endl;
    return 1;
  }
  return 0;
}
