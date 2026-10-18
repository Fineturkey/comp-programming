#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    vector<bool> dragons(d + 1, false);

    for (int i = 1; i <= d; i++)
    {
        if (i % k == 0 ||
            i % l == 0 ||
            i % m == 0 ||
            i % n == 0)
        {
            dragons[i] = true;
        }
    }

    int counter = 0;

    for (int i = 1; i <= d; i++)
    {
        if (dragons[i])
        {
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}