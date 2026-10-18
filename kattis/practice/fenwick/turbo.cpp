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
    int n;
    cin >> n;

    vector<int> position(n + 1);
    FenwickTree ft(n);

    // Remember each number's original position.
    // Initially, every position is active.
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        position[value] = i;
        ft.add(i, 1);
    }

    int smallest = 1;
    int largest = n;

    for (int step = 0; step < n; step++)
    {
        if (step % 2 == 0)
        {
            int idx = position[smallest];

            // Count unfinished numbers strictly to the left.
            cout << ft.prefixSum(idx) << '\n';

            // This number is now finished.
            ft.add(idx, -1);
            smallest++;
        }
        else
        {
            int idx = position[largest];

            // Count unfinished numbers strictly to the right.
            cout << ft.prefixSum(n) - ft.prefixSum(idx + 1) << '\n';

            // This number is now finished.
            ft.add(idx, -1);
            largest--;
        }
    }

    return 0;
}