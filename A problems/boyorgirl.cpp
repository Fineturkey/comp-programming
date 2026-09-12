#include <string>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    string n;
    cin >> n;
    set<char> dis;

    for (int i = 0; i < n.size(); i++)
    {
        dis.insert(n[i]);
    }

    if (dis.size() % 2 != 0)
    {
        cout << "IGNORE HIM!";
    }
    else
    {
        cout << "CHAT WITH HER!";
    }
    return 0;
}
