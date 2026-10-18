#include <iostream>

using namespace std;

int main()
{
    // Need to use data type of size 64 so use long or int_64
    long long x, y;
    while (cin >> x >> y)
    {
        cout << abs(x - y) << '\n';
    }
    return 0;
}