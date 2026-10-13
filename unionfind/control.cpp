#include <iostream>
#include <vector>

using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind

class UnionFind
{
    struct UF
    {
        int p;
        int rank;
    };

public:
    UnionFind(int n)
    { // constructor
        howMany = n;
        uf = new UF[howMany];
        for (int i = 0; i < howMany; i++)
        {
            uf[i].p = i;
            uf[i].rank = 0;
        }
    }

    ~UnionFind()
    {
        delete[] uf;
    }

    int find(int x) { return find(uf, x); } // for client use

    bool merge(int x, int y)
    {
        int res1, res2;
        res1 = find(uf, x);
        res2 = find(uf, y);
        if (res1 != res2)
        {
            if (uf[res1].rank > uf[res2].rank)
            {
                uf[res2].p = res1;
            }
            else
            {
                uf[res1].p = res2;
                if (uf[res1].rank == uf[res2].rank)
                {
                    uf[res2].rank++;
                }
            }
            return true;
        }
        return false;
    }

private:
    int howMany;
    UF *uf;

    int find(UF uf[], int x)
    { // recursive funcion for internal use
        if (uf[x].p != x)
        {
            uf[x].p = find(uf, uf[x].p);
        }
        return uf[x].p;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    UnionFind uf(500001);
    vector<int> groupSize(500001, 1);
    vector<int> used(500001, 0);

    int answer = 0;

    while (n--)
    {
        int m;
        cin >> m;

        vector<int> ingredients(m);
        vector<int> roots;

        // Read ingredients and count how many come from each group.
        for (int i = 0; i < m; i++)
        {
            cin >> ingredients[i];

            int root = uf.find(ingredients[i]);

            if (used[root] == 0)
            {
                roots.push_back(root);
            }

            used[root]++;
        }

        // We must use every ingredient from each touched group.
        bool possible = true;

        for (int root : roots)
        {
            if (used[root] != groupSize[root])
            {
                possible = false;
            }
        }

        for (int root : roots)
        {
            used[root] = 0;
        }

        if (possible)
        {
            for (int i = 1; i < m; i++)
            {
                uf.merge(ingredients[0], ingredients[i]);
            }

            int root = uf.find(ingredients[0]);
            groupSize[root] = m;

            answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}