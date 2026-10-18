#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree
{
    int n;
    vector<long long> tree;

    FenwickTree(int size)
    {
        n = size;
        tree.assign(n + 1, 0);
    }

    // Add delta to the element at index i.
    void add(int i, long long delta)
    {
        int p = i + 1;

        while (p <= n)
        {
            tree[p] += delta;
            p += p & -p;
        }
    }

    // Sum of the first count elements: indices 0 through count - 1.
    long long prefixSum(int count) const
    {
        long long sum = 0;
        int p = count;

        while (p > 0)
        {
            sum += tree[p];
            p -= p & -p;
        }

        return sum;
    }

    // Sum from index l through index r, including both.
    long long rangeSum(int l, int r) const
    {
        return prefixSum(r + 1) - prefixSum(l);
    }

    // Read the individual element at index i.
    long long get(int i) const
    {
        return rangeSum(i, i);
    }

    // Replace the element at index i with value.
    void set(int i, long long value)
    {
        long long current = get(i);
        add(i, value - current);
    }

    // Flip an element between 0 and 1.
    // Only use this when the element is a bit.
    void flip(int i)
    {
        if (get(i) == 0)
        {
            add(i, 1);
        }
        else
        {
            add(i, -1);
        }
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, numReq;
        cin >> m >> numReq;
        vector<int> position(m + 1);
        FenwickTree ft(m);

        for (int i = 1; i < m; i++)
        {
            position[i] = i;
            ft.add(i, 1);
        }
    }
    return 0;
}