#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Okay, well obviously we should start by figuring out which list to sort.

// Given two different lists sync them together based on the order that they're in.
/*
4
10 67 68 28
55 73 10 6

so the output would be 6, 55, 73, 10

Do we even need to sort this? I don't think so

I could just create two copies of the vectors and then reorganizing them to their original state
*/

int main()
{
    int n;

    while (cin >> n && n != 0)
    {
        vector<int> list(n);
        vector<int> secondList(n);

        for (int i = 0; i < n; i++)
            cin >> list[i];

        for (int i = 0; i < n; i++)
            cin >> secondList[i];

        vector<int> listCopy = list;
        vector<int> secondCopy = secondList;

        sort(listCopy.begin(), listCopy.end());
        sort(secondCopy.begin(), secondCopy.end());

        map<int, int> m1;

        for (int i = 0; i < n; i++)
            m1[listCopy[i]] = secondCopy[i];

        for (int i = 0; i < n; i++)
            cout << m1[list[i]] << '\n';

        cout << '\n';
    }
}