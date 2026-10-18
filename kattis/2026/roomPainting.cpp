#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int totalWaste = 0;

    cin >> n >> m;

    vector<int> numShop(n);
    vector<int> numNeed(m);

    for (int i = 0; i < n; i++)
    {
        cin >> numShop[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> numNeed[i];
    }

    sort(numShop.begin(), numShop.end());

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (numNeed[i] <= numShop[j])
            {
                totalWaste += numShop[j] - numNeed[i];
                break;
            }
        }
    }
    cout << totalWaste << endl;

    return 0;
}