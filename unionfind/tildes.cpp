// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind

#include <iostream>
#include <vector>

using namespace std;

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
    int n, q;
    cin >> n >> q;

    UnionFind uf(n + 1);
    vector<int> groupSize(n + 1, 1);

    while (q--)
    {
        char op;
        cin >> op;
        if (op == 's')
        {
            int a;
            cin >> a;
            cout << groupSize[uf.find(a)] << '\n';
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int rootA = uf.find(a);
            int rootB = uf.find(b);

            if (rootA != rootB)
            {
                int combinedSize = groupSize[rootA] + groupSize[rootB];
                uf.merge(a, b);

                int newRoot = uf.find(a);
                groupSize[newRoot] = combinedSize;
            }
        }
    }
    return 0;
}