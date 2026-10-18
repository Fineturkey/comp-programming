#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int L, n;
        cin >> L >> n;

        int earliest = 0;
        int latest = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            earliest = max(earliest, min(x, L - x));
            latest = max(latest, max(x, L - x));
        }

        cout << earliest << " " << latest << endl;
    }

    return 0;
}