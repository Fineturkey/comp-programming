#include <iostream>
#include <vector>

using namespace std;

bool foo(const vector<int> &vec, int x)
{
    for (int i = 0; i < x; i++)
    {
        if (vec[i] % 2 != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int x = 0;
    int count = 0;

    cin >> x;

    vector<int> myVec(x);

    for (int i = 0; i < x; i++)
    {
        cin >> myVec[i];
    }

    while (foo(myVec, x))
    {
        count++;

        for (int i = 0; i < x; i++)
        {
            myVec[i] /= 2;
        }
    }

    cout << count << endl;

    return 0;
}