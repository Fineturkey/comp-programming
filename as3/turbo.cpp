
/*
 * Problem: Turbo
 *
 * Approach:
 * Store the original positions of the numbers.
 * Use a Fenwick tree to count how many numbers
 * are still left when moving each element.
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> bit;
int n;

void update(int i, int val) {
    while (i <= n) {
        bit[i] = bit[i] + val;
        int step = i & -i;
        i = i + step;
    }
}

int query(int i) {
    int sum = 0;

    while (i > 0) {
        sum += bit[i];
        i -= i & -i;
    }

    return sum;
}

int main() {
    cin >> n;

    bit.resize(n + 1, 0);

    vector<int> pos(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }

    for (int i = 1; i <= n; i++) {
        update(i, 1);
    }

    int left = 1;
    int right = n;

    for (int i = 0; i < n; i++) {
        int swaps = 0;

        if (i % 2 == 0) {
            swaps = query(pos[left] - 1);
            update(pos[left], -1);
            left++;
        } else {
            swaps = query(n) - query(pos[right]);
            update(pos[right], -1);
            right--;
        }

        cout << swaps << endl;
    }

    return 0;
}
