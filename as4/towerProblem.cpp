/****************************
 * Just try all 6! permuations and see if they're equal to each other
 ****************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> boxes(6, 0);
    int tower1;
    int tower2;

    for (int i = 0; i < 6; i++)
    {
        cin >> boxes[i];
    }

    sort(boxes.begin(), boxes.end());
    cin >> tower1 >> tower2;

    do
    {
        int totalBoxes = boxes[0] + boxes[1] + boxes[2];
        if (totalBoxes == tower1)
        {
            break;
        }
    } while (next_permutation(boxes.begin(), boxes.end()));

    sort(boxes.begin(), boxes.begin() + 3, greater<int>());
    sort(boxes.begin() + 3, boxes.end(), greater<int>());

    for (int i = 0; i < 6; i++)
    {
        cout << boxes[i] << ' ';
    }
    return 0;
}