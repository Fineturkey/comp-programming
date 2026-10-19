/******************************
 * Just hard code the if else statement, theres only 4 possibilities
 * therefore you only need to do 4 checks to see if the D is adjacent to the A
 * otherwise return false
 *****************************/

#include <iostream>

using namespace std;

int main()
{
    char arr[2][2];
    cin >> arr[0][0] >> arr[1][0] >> arr[0][1] >> arr[1][1];

    if (arr[0][0] == 'A')
    {
        if (arr[1][0] == 'D' || arr[0][1] == 'D')
        {
            cout << "Yes";
            return 0;
        }
    }
    else if (arr[0][1] == 'A')
    {
        if (arr[0][0] == 'D' || arr[1][1] == 'D')
        {
            cout << "Yes";
            return 0;
        }
    }
    else if (arr[1][0] == 'A')
    {
        if (arr[0][0] == 'D' || arr[1][1] == 'D')
        {
            cout << "Yes";
            return 0;
        }
    }
    else if (arr[1][1] == 'A')
    {
        if (arr[0][1] == 'D' || arr[1][0] == 'D')
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    // I think I'm just gonig to hard code it LOL
    return 0;
}
