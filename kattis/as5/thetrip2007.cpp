/**
 * Greedy approch
 * if one size appears 3 times, need at least 3 pieces
 * distributing the sorted bags in rotation across 3 pieces achieves that minimum
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// sort by piece number, than by bag size within
// each piece
bool comparePieces(const tuple<int, bool, int> &a,
                   const tuple<int, bool, int> &b)
{
    if (get<2>(a) != get<2>(b))
    {
        return get<2>(a) < get<2>(b);
    }

    return get<0>(a) < get<0>(b);
}

// Find the minimum number of pieces and distribute bags evenly
// Each piece should contain strictley increasing bag sizes

void packBags(vector<tuple<int, bool, int>> &bags)
{
    sort(bags.begin(), bags.end());

    int pieces = 1;
    int frequency = 1;
    int n = bags.size();

    for (int i = 1; i < n; i++)
    {
        if (get<0>(bags[i]) == get<0>(bags[i - 1]))
        {
            frequency++;
        }
        else
        {
            frequency = 1;
        }

        pieces = max(pieces, frequency);
    }

    for (int i = 0; i < n; i++)
    {
        get<1>(bags[i]) = (i < pieces);
        get<2>(bags[i]) = i % pieces;
    }

    sort(bags.begin(), bags.end(), comparePieces);

    cout << pieces;

    for (int i = 0; i < n; i++)
    {
        if (get<1>(bags[i]))
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }

        cout << get<0>(bags[i]);
    }

    cout << '\n';
}

int main()
{
    int n;
    bool firstCase = true;

    while (cin >> n && n != 0)
    {
        vector<tuple<int, bool, int>> bags;

        for (int i = 0; i < n; i++)
        {
            int size;
            cin >> size;
            bags.push_back(make_tuple(size, false, 0));
        }

        if (!firstCase)
        {
            cout << '\n';
        }

        packBags(bags);
        firstCase = false;
    }

    return 0;
}