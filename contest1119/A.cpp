#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string nhoj;

        cin >> nhoj;

        int total = 0;

        for (int i = 0; i < n; i += k)
        {
            int counter = 0;

            for (int j = i; j < i + k && j < n; j++)
            {
                if (nhoj[j] == '1')
                {
                    counter++;
                }
            }

            if (counter == k)
            {
                total++;
            }
        }

        cout << total << '\n';
    }

    return 0;
}