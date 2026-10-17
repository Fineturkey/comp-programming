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
using namespace std;

// Bitwise operator syntax reference:
// https://en.cppreference.com/w/cpp/language/operator_arithmetic

int unscramble(int y)
{
    int x = 0;
    int previousOriginalBit = 0;

    for (int bit = 0; bit < 8; bit++)
    {
        int scrambledBit = (y >> bit) & 1;
        int originalBit = scrambledBit ^ previousOriginalBit;

        x |= originalBit << bit;
        previousOriginalBit = originalBit;
    }

    return x;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int receivedByte;
        cin >> receivedByte;

        if (i > 0)
            cout << ' ';

        cout << unscramble(receivedByte);
    }

    cout << '\n';
    return 0;
}