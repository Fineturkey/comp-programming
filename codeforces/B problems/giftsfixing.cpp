#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        vector<int> y(m);
        vector<int> x(m);

        int minY = numeric_limits<int>::max();
        int minX = numeric_limits<int>::max();

        for (int j = 0; j < m; j++)
        {
            cin >> y[j];
            minY = min(minY, y[j]);
        }

        for (int j = 0; j < m; j++)
        {
            cin >> x[j];
            minX = min(minX, x[j]);
        }

        long long count = 0;

        for (int j = 0; j < m; j++)
        {
            int yA = y[j] - minY;
            int xA = x[j] - minX;

            int mini = min(yA, xA);

            count += mini;

            yA -= mini;
            xA -= mini;

            count += yA + xA;
        }

        cout << count << '\n';
    }

    return 0;
}