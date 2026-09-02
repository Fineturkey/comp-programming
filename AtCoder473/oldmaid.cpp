#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int count[101];

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if(count[i] % 2 == 1)
        {
            ans += i;
        }
    }
    return 0;
}