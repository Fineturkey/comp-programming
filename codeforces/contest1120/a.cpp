#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;

    cin >> t;

    while (t--)
    {
        int n = 0;
        cin >> n;

        vector<int> x(n);

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        while (x.size() > 1)
        {
            vector<int> next;

            for (int i = 0; i < x.size() / 2; i++)
            {
                if (i % 2 == 0)
                {
                    next.push_back(min(x[2 * i], x[2 * i + 1]));
                }
                else
                {
                    next.push_back(max(x[2 * i], x[2 * i + 1]));
                }
            }

            x = next;
        }

        cout << x[0] << '\n';
    }

    return 0;
}