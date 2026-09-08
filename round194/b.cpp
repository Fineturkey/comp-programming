#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        long long x = 0;
        long long y = 0;
        long long k = 0;

        cin >> x >> y >> k;

        long long totalWork = 0;
        long long d = y - x;

        long long i = 0;

        while (i < k && x + i <= d)
        {
            totalWork += d % (x + i);
            i++;
        }

        if (i < k)
        {
            totalWork += (k - i) * d;
        }

        cout << totalWork << '\n';
    }

    return 0;
}
