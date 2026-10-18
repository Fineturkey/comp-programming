#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<long long> lower;
        priority_queue<long long,
                       vector<long long>,
                       greater<long long>>
            upper;

        long long answer = 0;

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;

            // Put the number into the appropriate half.
            if (lower.empty() || x <= lower.top())
            {
                lower.push(x);
            }
            else
            {
                upper.push(x);
            }

            // Keep the halves equal in size, or lower one bigger.
            if (lower.size() > upper.size() + 1)
            {
                upper.push(lower.top());
                lower.pop();
            }
            else if (upper.size() > lower.size())
            {
                lower.push(upper.top());
                upper.pop();
            }

            // Add the current median to our answer.
            if (lower.size() == upper.size())
            {
                answer += (lower.top() + upper.top()) / 2;
            }
            else
            {
                answer += lower.top();
            }
        }

        cout << answer << '\n';
    }

    return 0;
}