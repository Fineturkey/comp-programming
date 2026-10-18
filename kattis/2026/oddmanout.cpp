#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x;
    cin >> x;

    for (int i = 0; i < x; i++) {
        int y;
        cin >> y;

        vector<int> guestlist(y);

        for (int j = 0; j < y; j++) {
            cin >> guestlist[j];
        }

        sort(guestlist.begin(), guestlist.end());

        int oddOne = guestlist.back();   // Assume the last one is odd

        for (int j = 0; j < y - 1; j += 2) {
            if (guestlist[j] != guestlist[j + 1]) {
                oddOne = guestlist[j];
                break;
            }
        }

        cout << "Case #" << i + 1 << ": " << oddOne << '\n';
    }
    return 0;
}
/*
You are hosting a party with guests and notice that there is an odd number of guests! When planning the party you deliberately invited only couples and gave each couple a unique number on their invitation. You would like to single out whoever came alone by asking all of the guests for their invitation numbers.
Input

The first line of input gives the number of cases, . test cases follow. For each test case there will be:

    One line containing the value the number of guests.

    One line containing a space-separated list of integers. Each integer indicates the invitation code of a guest.

You may assume that .
Output

For each test case, output one line containing “Case #: ” followed by the number of the guest who is alone.
Sample Input 1 	Sample Output 1

3
3
1 2147483647 2147483647
5
3 4 7 4 3
5
2 10 2 10 5

	

Case #1: 1
Case #2: 7
Case #3: 5

*/

// we just sort a vector of size n and then check if the next element matches with the current one
// in the case where they aren't amtching then we can simply print out that specifc element