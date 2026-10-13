#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, q;
    cin >> n >> q;

    vector<long long> m(n + 1, 0);

    while (q--)
    {
        char op;
        int i;
        cin >> op >> i;

        if (op == '+')
        {
            int p = i + 1;
            long long delta;
            cin >> delta;

            while (p <= n)
            {
                m[p] += delta;
                p += p & -p;
            }
        }
        else
        {
            long long sum = 0;
            int p = i;

            while (p > 0)
            {
                sum += m[p];
                p -= p & -p;
            }

            cout << sum << '\n';
        }
    }

    return 0;
}