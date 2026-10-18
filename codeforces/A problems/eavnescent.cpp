#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    int x = 0;
    int y = 0;
    int z = 0;

    cin >> n;

    int a[n][3];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                x += a[i][j];
            }
            else if (j == 1)
            {
                y += a[i][j];
            }
            else
            {
                z += a[i][j];
            }
        }
    }

    if (x == 0 && y == 0 && z == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}