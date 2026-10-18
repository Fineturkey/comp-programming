#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    string tickets;
    cin >> tickets;

    int i = 0;
    int j = tickets.size() - 1;
    int leftSum = 0;
    int rightSum = 0;

    while (i < tickets.size() / 2)
    {
        if (tickets[i] != '4' && tickets[i] != '7')
        {
            cout << "NO";
            return 0;
        }

        if (tickets[j] != '4' && tickets[j] != '7')
        {
            cout << "NO";
            return 0;
        }

        leftSum += tickets[i] - '0';
        rightSum += tickets[j] - '0';

        i++;
        j--;
    }

    if (leftSum == rightSum)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}