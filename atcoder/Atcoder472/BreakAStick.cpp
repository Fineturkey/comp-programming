#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0;
    int totalSum = 0;
    cin >> n;

    vector<int> stick(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stick[i];
        totalSum += stick[i];
    }

    int minAns = totalSum;

    int group1 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        group1 += stick[i];

        int group2 = totalSum - group1;

        minAns = min(minAns, abs(group1 - group2));
    }

    cout << minAns;

    return 0;
}