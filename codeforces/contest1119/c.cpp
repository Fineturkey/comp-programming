#include <iostream>
#include <vector>

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

        int i = 0;
        int j = x.size() - 1;

        bool front = false;
        bool back = false;

        while (i <= j && (!front || !back))
        {

            if (!front)
            {
                if (x[i] == 1 || x[i] == -1)
                {
                    front = true;
                    x[i] = 1;
                }
                else
                {
                    i++;
                }
            }

            if (!back && i <= j)
            {
                if (x[j] == 1 || x[j] == -1)
                {
                    if (i == j && front)
                    {
                        back = true;
                    }
                    else
                    {
                        back = true;
                        x[j] = 1;
                    }
                }
                else
                {
                    j--;
                }
            }
        }

        for (int k = 0; k < x.size(); k++)
        {
            if (x[k] == -1)
            {
                x[k] = 0;
            }
        }

        for (int k = 0; k < x.size(); k++)
        {
            cout << x[k] << " ";
        }

        cout << '\n';
    }

    return 0;
}