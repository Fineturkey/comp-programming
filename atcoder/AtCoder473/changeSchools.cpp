#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    int ans = 0;

    cin >> n >> k;

    vector<int> list(k + 1);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list[x]++;
    }

    int maxE = *max_element(list.begin() + 1, list.end());

    for (int i = 1; i <= k; i++)
    {
        if (list[i] >= maxE - 1)
        {
            ans++;
        }
    }

    cout << ans;

    return 0;
}