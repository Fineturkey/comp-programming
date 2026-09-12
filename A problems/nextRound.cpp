#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> scores(n);

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    int passingScore = scores[k - 1];
    int pass = 0;

    for (int x : scores)
    {
        if (x >= passingScore && x > 0)
        {
            pass++;
        }
    }

    cout << pass << '\n';

    return 0;
}