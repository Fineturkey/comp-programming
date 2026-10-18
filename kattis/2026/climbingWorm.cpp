#include <iostream>

using namespace std;

int main() {
    int a, b, h;
    cin >> a >> b >> h;

    int sum = 0;
    int steps = 0;

    while (sum < h) {
        steps++;
        sum += a;

        if (sum >= h) {
            break;
        }

        sum -= b;
    }

    cout << steps;
    return 0;
}