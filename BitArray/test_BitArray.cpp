#include <iostream>
#include <climits>
#include <cstdlib>
#include <new>
#include <assert.h>
#include <stdbool.h>

#include "BitArray.hpp"

using namespace std;

int main(void){

    //  try {
    /* all of your code goes here */

    cout << "Beginning Test of BitArray Library\n" << endl;

    cout << "Testing: BitArray constructors and destructors" << endl;
    {
        BitArray BA = BitArray();
        BitArray BA2 = BitArray(5);
        BitArray BA3 = BitArray(-1);
        long int var = 300;
        BitArray BA4 = BitArray(var);
        long long int var2 = 321;
        BitArray BA5 = BitArray(var2);
    }

    cout << "Testing: BitArray internal functions" << endl;
    {
        BitArray BA6 = BitArray(4);
        BA6.test_BitArrayInternal();
    }

    cout << "Testing: BitArray displayer" << endl;
    {
        BitArray BA7 = BitArray(12);
        BA7.print();
    }

    cout << "Testing: BitArray setElem" << endl;
    {
        BitArray BA8 = BitArray(17);
        int rv = BA8.setElem(17);
        assert(rv==-1);
        rv = BA8.setElem(-1);
        assert(rv==-1);
        rv = BA8.setElem(0);
        assert(rv==0);
        rv = BA8.setElem(16);
        assert(rv==0);
    }

    cout << "Testing: BitArray getElem" << endl;
    {
        BitArray BA9 = BitArray(18);
        int rv = BA9.getElem(-1);
        assert(rv==-1);
        rv = BA9.getElem(18);
        assert(rv==-1);
        rv = BA9.getElem(17);
        assert(rv==0);
        rv = BA9.getElem(0);
        assert(rv==0);
        rv = BA9.setElem(1);
        assert(rv==0);
        rv = BA9.getElem(1);
        assert(rv==1);
        rv = BA9.getElem(2);
        assert(rv==0);
        rv = BA9.setElem(17);
        assert(rv==0);
        rv = BA9.getElem(17);
        assert(rv==1);
        rv = BA9.getElem(16);
        assert(rv==0);
    }

    cout << "Testing: BitArray unsetElem" << endl;
    {
        BitArray BA10 = BitArray(21);
        int rv = BA10.unsetElem(-1);
        assert(rv==-1);
        rv = BA10.unsetElem(21);
        assert(rv==-1);
        for(long long int i=0;i<21;i++){
            BA10.setElem(i);
            rv = BA10.getElem(i);
            assert(rv==1);
        }
        for(long long int i=0;i<21;i++){
            rv = BA10.unsetElem(i);
            assert(rv==0);
            rv = BA10.getElem(i);
            cout << "i " << i << " rv " << rv << endl;
            assert(rv==0);
        }
    }

    cout << "Testing: BitArray operators ==" << endl;
    {
        BitArray BA11 = BitArray();
        bool ans = (BA11==BA11);
        assert(ans==true);
        BitArray BA12 = BitArray(21);
        ans = (BA11==BA12);
        assert(ans==false);
        BA11.setElem(4);
        ans = (BA11==BA11);
        assert(ans==true);
        BitArray BA13 = BitArray();
        BA13.setElem(5);
        ans = (BA11==BA13);
        assert(ans==false);
    }

    cout << "Testing: BitArray operators !=" << endl;
    {
        BitArray BA14 = BitArray();
        bool ans = (BA14!=BA14);
        assert(ans==false);
        BitArray BA15 = BitArray(21);
        ans = (BA14!=BA15);
        assert(ans==true);
        BA14.setElem(4);
        ans = (BA14!=BA14);
        assert(ans==false);
        BitArray BA16 = BitArray();
        BA16.setElem(5);
        ans = (BA14!=BA16);
        assert(ans==true);
    }

    cout << "Testing: BitArray append " << endl;
    {
        BitArray BA17 = BitArray(15);
        BitArray BA18 = BitArray(16);
        long long int i;
        for(i=0;i<16;i++){
            BA18.setElem(i);
        }
        BA17.append(BA18);
        for(i=0;i<15;i++){
            assert(BA17.getElem(i)==0);
        }
        for(;(i-15)<16;i++){
            assert(BA17.getElem(i)==1);
        }
    }

    cout << "Testing: BitArray [] = int" << endl;
    {
        BitArray BA19 = BitArray(12);
        (BA19[0]) = 1;
        assert(BA19.getElem(0)==1);
        assert(BA19[0]==1);
    }

    cout << "Testing: BitArray [] = BitArray []" << endl;
    {
        BitArray BA20 = BitArray(13);
        BA20[0] = 1;
        assert(BA20[0]==1);
        BA20[11] = BA20[0];
        assert(BA20[11]==1);
    }

    cout << "Testing: BitArray = BitArray" << endl;
    {
      BitArray BA21 = BitArray(10);
      BitArray BA22 = BitArray(10);
      BA21[4] = 1;
      assert(BA21[4]==1);
      BA22 = BA21;
      assert(BA22[4]==1);
      assert(BA22[3]==0);
      assert(BA22[5]==0);
    }
    //cout << "Registers\n" << endl;
    //cout << BA[0] << endl;
    //BA[1] = 1;
    //BA[2] = 1;
    //temp = 2;
    //BA[3] = temp;
    //cout << "PRINTING temp " << temp << endl;
    //BA->print();
    //BA->setElem(2);
    /*  BA[1];
        BA[0];
        temp = int(BA[2]);
        cout << "PRINTING temp " << temp << endl;
        BA->print();
        temp = BA[0];*/
    /*  for(i=0;i<8;i++){
        BA[i] = 1;
        }
        BA->print();
        for(i=0;i<12;i++){
        if(i<8){
        assert(BA[i]==1);
        }else{
        assert(BA[i]==0);
        }
        }*/
    //  delete BA;

    /*} catch (exception& e) {
      cerr << "error: " << e.what() << endl;
      return 1;
      } catch(...) {
      cerr << "error: unknown exceptions" << endl;
      return 1;
      }*/
    return 0;
}
