#include <iostream>

using namespace std;

int main() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;

    int temp = a + b + c;

    if (temp > (m * 2)) {
        cout << "impossible";
    }

    else {
        cout << "possible";
    }
}