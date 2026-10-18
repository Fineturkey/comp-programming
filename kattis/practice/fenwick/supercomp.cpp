#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> m(n + 1, 0);
    vector<int> bits(n + 1, 0);

    while (k--)
    {
        char op;
        cin >> op;

        if (op == 'F')
        {
            int p;
            cin >> p;

            int delta;

            if (bits[p] == 0)
            {
                bits[p] = 1;
                delta = 1;
            }
            else
            {
                bits[p] = 0;
                delta = -1;
            }

            while (p <= n)
            {
                m[p] += delta;
                p += p & -p;
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int p = r;
            long long sum = 0;

            while (p > 0)
            {
                sum += m[p];
                p -= p & -p;
            }

            p = l - 1;

            while (p > 0)
            {
                sum -= m[p];
                p -= p & -p;
            }

            cout << sum << '\n';
        }
    }
    return 0;
}