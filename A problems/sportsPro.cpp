#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m = 0;
    int min = 0;
    int max = 0;
    int count = 0;

    cin >> m;
    cin >> min;
    max = min;
    for (int i = 0; i < m - 1; i++)
    {
        int x = 0;
        cin >> x;
        if (x < min)
        {
            min = x;
            count++;
        }
        else if (x > max)
        {
            max = x;
            count++;
        }
        else
        {
            continue;
        }
    }
    cout << count;
    return 0;
}