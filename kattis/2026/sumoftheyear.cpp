#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x;
    int q;
    int p;
    cout << "Enter num "; 
    cin >> x;

    for (int i = 1; i < x; i++) 
    {
        for(int j = 1; j < i; j++) {
            p += j;
            p = pow(p, 2);
        }
        q += pow(i , 3);
        if (p == q) {
            continue;
            p = 0;
        }

        else {
            cout << i;
            break;
        }
    }
    cout << 0;
}