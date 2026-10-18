#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int h, k, s;
    double v;
    int hori = 0;
    cin >> h >> k >> v >> s;

    while (h > 0)
    {
        v += s;

        v -= max(1 , (int)floor(v / 10.0));

        if (v >= k)
        {
            h++;
        }

        if (v > 0 && v < k)
        {
            h--;
            if (h == 0)
            {
                v = 0;
            }
        }

        if (v <= 0)
        {
            h = 0;
            v = 0;
        }

        hori += v;

        if (s > 0)
        {
            s--;
        }
    }
    cout << hori;
}

// I dunno, this problems pretty self explanatory

// You sort of just follow a set of instructions