#include <iostream>

using namespace std;

int main()
{

    int t = 0;
    cin >> t;

    while (t--)
    {
        int n = 0;
        cin >> n;

        int odd = 0;
        int even = 0;
        int even1 = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x % 2 == 1)
            {
                odd++;
            }
            else if (x % 4 == 0)
            {
                even++;
            }
            else
            {
                even1++;
            }
        }
        cout << max(odd, max(even, even1)) << endl;
    }

    return 0;
}