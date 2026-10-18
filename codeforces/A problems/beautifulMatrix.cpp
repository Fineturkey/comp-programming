#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[5][5];
    int x = 0;
    int y = 0;
    int totalSteps = 0;

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
            if(a[i][j] != 0) {
                x = i;
                y = j;
            }
        }
    }
    x = abs(x - 2);
    y = abs(y - 2);

    totalSteps += x;
    totalSteps += y;

    cout << totalSteps;
}