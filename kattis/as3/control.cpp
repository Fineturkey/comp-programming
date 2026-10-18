/*
 * Problem: Control
 *
 * Approach:
 * Use union find to keep track of ingredients
 * that have already been combined.
 * For each potion, check if all ingredients
 * from each existing group are included.
 * If valid, merge the groups and count the potion.
 *
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> parent(500001);
vector<int> sz(500001, 1);

int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void join(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 500001; i++)
    {
        parent[i] = i;
    }

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        vector<int> ingredients(k);

        for (int j = 0; j < k; j++)
        {
            cin >> ingredients[j];
        }

        map<int, int> groups;

        for (int j = 0; j < k; j++)
        {
            int root = findParent(ingredients[j]);
            groups[root]++;
        }

        bool valid = true;

        for (auto p : groups)
        {
            if (p.second != sz[p.first])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            answer++;

            for (int j = 1; j < k; j++)
            {
                join(ingredients[0], ingredients[j]);
            }
        }
    }

    cout << answer << endl;

    return 0;
}