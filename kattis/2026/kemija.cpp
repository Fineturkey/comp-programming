#include <iostream>
#include <string>

using namespace std;

int main()
{
    string m;
    getline(cin, m);
    for (int i : m)
    {
        if (m[i] == 'p')
        {
            m.erase(m[i], m[i + 1]);
        }
    }

    cout << m;
    return 0;
}