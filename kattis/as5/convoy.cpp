/**
 * Create a priority queue in order to maintain the fastest time we arrive at our destination
 * Keep track of which driver is which and then recalculate how long it would take for them to go there and back
 * i.e. next_arrival = arrival + (2 * driving_time) driving_time is created seperatly and never changed
 * Continously pop out of the priority queue until n <= 0, the number at the top is the minimum amount of time
 * It will take to get everyone over.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

int64_t minimumTime(vector<long long> &speeds, int k)
{
    sort(speeds.begin(), speeds.end());

    int n = speeds.size();

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>>
        minHeap;

    // Keep track of the actual speed with the driver
    // So that when we increment the driver (i.e. the possiblity of the driver heading back) we can remember how fast
    // It takes him to get back and then go to the statium

    for (int i = 0; i < k && i < n; i++)
    {
        minHeap.push(make_pair(speeds[i], i));
    }

    while (!minHeap.empty())
    {
        long long arrival = minHeap.top().first;
        int driver = minHeap.top().second;
        minHeap.pop();

        if (arrival == speeds[driver])
        {
            n -= 5;
        }
        else
        {
            n -= 4;
        }
        if (n <= 0)
        {
            return arrival;
        }

        minHeap.push(make_pair(arrival + 2 * speeds[driver], driver));
    }

    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> speeds(n);

    for (int i = 0; i < n; i++)
    {
        cin >> speeds[i];
    }

    cout << minimumTime(speeds, k) << '\n';

    return 0;
}