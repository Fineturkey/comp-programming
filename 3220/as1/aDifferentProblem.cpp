#include <iostream>

using namespace std;

int main()
{
    long long x, y;
    while (cin >> x >> y)
    {
        cout << abs(x - y) << '\n';
    }
    return 0;
}