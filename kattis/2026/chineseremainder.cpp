#include <iostream>
#include <numeric>

using namespace std;

bool check(int a, int n, int b, int m) {
    int temp = gcd(n, m);
    int p, q = 0;

    p = a % temp;
    q = b % temp;

    if (p == q) {
        return true;
    }

    return false;
}

int main() {
    int numCase;

    cin >> numCase;

    for(int i = 0; i < numCase; i++) {
        int a, n, b, m;
        int k = 0;
        int x = 0;
        int y = 1;
        cin >> a >> n >> b >> m;

        k = lcm(n, m);

        if(check(a, n, b, m)) {
            while(x != y) {
                x = a % n;
                y = b % m;

                if(x == y) {
                    break;
                }
                a += n;
                b += m;
            }
            cout << k << x << endl;
        }
        else {
            cout << "no solution";
            continue;
        }
    }
}

//  a - b = tm - sn

// I suck at math and dunno how to do it with the Linear Diophantine Equations and extended Euclidian theorm