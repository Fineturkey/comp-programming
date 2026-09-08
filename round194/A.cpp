#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> problems(n);
        int totalZero = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> problems[i];

            if (problems[i] == 0)
                totalZero++;
        }

        int rotationsNeeded = 0;

        if (n == 2 && totalZero != 2)
        {
            cout << -1 << '\n';
            continue;
        }

        if (problems[0] == 1)
        {
            rotationsNeeded++;
            totalZero--;
        }

        if (problems[n - 1] == 1)
        {
            rotationsNeeded++;
            totalZero--;
        }

        if (totalZero < 0)
            cout << -1 << '\n';
        else
            cout << rotationsNeeded << '\n';
    }

    return 0;
}
