#include <iostream>
#include <map>
#include <array>
#include <string>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        string song;
        cin >> song;

        map<char, array<int, 10>> mapArr;
        int fingers[10] = {};
        mapArr['c'] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 1};
        mapArr['d'] = {0, 1, 1, 1, 0, 0, 1, 1, 1, 0};
        mapArr['e'] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
        mapArr['f'] = {0, 1, 1, 1, 0, 0, 1, 1, 0, 0};
        mapArr['g'] = {0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
        mapArr['a'] = {0, 1, 1, 0, 0, 0, 0, 0, 0, 0};
        mapArr['b'] = {0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
        mapArr['C'] = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
        mapArr['D'] = {1, 1, 1, 1, 0, 0, 1, 1, 1, 0};
        mapArr['E'] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0};
        mapArr['F'] = {1, 1, 1, 1, 0, 0, 1, 0, 0, 0};
        mapArr['G'] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
        mapArr['A'] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
        mapArr['B'] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

        for (char note : song)
        {
            array<int, 10> currentFingers = mapArr[note];

            for (int i = 0; i < 10; i++)
            {
                if (currentFingers[i] == 0)
                {
                }
            }
        }

        for (int x : fingers)
        {
            cout << fingers[x];
        }

        cout << '\n';
    }

    return 0;
}