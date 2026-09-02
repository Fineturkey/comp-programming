#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int n = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m = 0;
        double abv = 0.0;
        double x = 0.0;
        cin >> m;
        vector<int> students(m);

        for (int j = 0; j < m; j++)
        {
            cin >> students[j];
            x += students[j];
        }
        x = x / m;

        for (int j = 0; j < m; j++)
        {
            if (x < students[j])
            {
                abv++;
            }
        }
        abv = abv / m;

        abv *= 100;

        cout << fixed << setprecision(3) << abv << "%\n";
    }
}