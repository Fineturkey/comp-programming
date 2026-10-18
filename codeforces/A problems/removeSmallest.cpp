#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int p;
        cin >> p;
        vector<int> arr(p);

        for (int i = 0; i < p; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < p; i++)
        {
            if (arr[i + 1] - arr[i] > 1)
            {
                cout << "NO" << endl;
                break;
            }
            if (i == arr.size() - 1)
            {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}