/*********************
 * Binary search to figure out the first occurance when the weight works
 * Wait to pair each heavy pair and then continue on
 * if we get cause return false
 ********************/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool rowWorks(int limit, const vector<int> &row)
{
    int waiting = -1;

    for (int weight : row)
    {
        if (weight <= limit)
            continue; // We can lift this weight out of the way.
        if (waiting == -1)
        {
            waiting = weight; // Wait for this heavy weight's partner.
        }
        else if (weight == waiting)
        {
            waiting = -1; // The pair matches.
        }
        else
        {
            return false;
        }
    }

    return waiting == -1;
}

bool canLift(int limit, const vector<int> &row1, const vector<int> &row2)
{
    return rowWorks(limit, row1) && rowWorks(limit, row2);
}

int main()
{
    int n;
    cin >> n;

    vector<int> row1(n);
    vector<int> row2(n);
    int high = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> row1[i];
        high = max(high, row1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> row2[i];
        high = max(high, row2[i]);
    }

    int low = 0;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (canLift(mid, row1, row2))
        {
            high = mid; // This limit works; try a smaller one.
        }
        else
        {
            low = mid + 1; // This limit fails; try a larger one.
        }
    }

    cout << low << '\n';
    return 0;
}