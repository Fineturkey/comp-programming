#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        int y = 0;
        int z = 0;

        cin >> x >> y >> z;

        if ((x + y + z) >= 2)
        {
            ans++;
        }
    }

    cout << ans;
    return 0;
}