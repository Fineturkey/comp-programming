
/*
 * Problem: Continuous Median
 *
 * Approach:
 * Maintain two priority queues.
 * The max-heap stores the lower half of the numbers.
 * The min-heap stores the upper half.
 * Rebalance after insertion and sum each median.
 *
 */

#include <bits/stdc++.h>
using namespace std;

void addNumber(
    int x,
    priority_queue<int>& lower,
    priority_queue<int, vector<int>, greater<int>>& upper
) {
    if (lower.empty() || x <= lower.top()) {
        lower.push(x);
    } else {
        upper.push(x);
    }

    if (lower.size() > upper.size() + 1) {
        upper.push(lower.top());
        lower.pop();
    }

    if (upper.size() > lower.size()) {
        lower.push(upper.top());
        upper.pop();
    }
}

long long solveCase(int n) {
    priority_queue<int> lower;

    priority_queue<int, vector<int>, greater<int>> upper;

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        addNumber(x, lower, upper);

        long long median;

        if (lower.size() > upper.size()) {
            median = lower.top();
        } else {
            median = ((long long)lower.top() + upper.top()) / 2;
        }

        sum += median;
    }

    return sum;
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << solveCase(n) << endl;
    }

    return 0;
}