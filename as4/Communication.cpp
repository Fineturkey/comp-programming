/****************************** 
The sensor scrables each byte x as follows
y = x  ^ (x << 1) given y and trying to recover x
XORing a bit with itself cancels itsself out a ^ a = 0 | a ^ 0 = a
Therefore you can perform the following
y7 = x7
y6 = x6 ^ x7
... 
y0 = x0 ^ x1
******************************/



#include <iostream>

int unscramble (int y) {
    int x = 0;
    for (int bit = 7; bit >= 0; bit--) {
        int sBit = ()
    }
}

using namespace std;

int main() {

    

    return 0;
}