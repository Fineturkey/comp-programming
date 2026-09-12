#include <iostream>
#include <set>

using namespace std;

int main()
{
    int y = 0;
    int count = 0;
    set<int> arr;

    for (int i = 0; i < 4; i++)
    {
        int x = 0;
        cin >> x;
        arr.insert(x);
    }

    y = arr.size();
    count = 4 - y;

    cout << count;
}