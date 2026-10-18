#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int friends = 0;
    int bottles = 0;
    int mili = 0;
    int limes = 0;
    int slices = 0;
    int salt = 0;
    int totalNeeded = 0;
    int totalNeededSalt = 0;

    cin >> friends >> bottles >> mili >> limes >> slices >> salt >> totalNeeded >> totalNeededSalt;

    limes = limes * slices;
    bottles = bottles * mili;
    bottles = bottles / totalNeeded;
    salt = salt / totalNeededSalt;

    limes = limes / friends;
    bottles = bottles / friends;
    salt = salt / friends;

    int minimum = min(limes, min(bottles, salt));

    cout << minimum;

    return 0;
}