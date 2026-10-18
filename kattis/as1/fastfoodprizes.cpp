#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        // Each prize has a list of sticker types it needs
        vector<vector<int>> prizes(n);
        vector<int> money(n);

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            for (int j = 0; j < k; j++) {
                int type;
                cin >> type;
                prizes[i].push_back(type);
            }

            cin >> money[i];
        }

        // Sticker types start at 1, so leave position 0 unused
        vector<int> stickers(m + 1);

        for (int i = 1; i <= m; i++) {
            cin >> stickers[i];
        }

        int total = 0;

        for (int i = 0; i < n; i++) {
            // Start with the count of the first required sticker
            int first = prizes[i][0];
            int times = stickers[first];

            // Find the sticker we have the fewest of
            for (int j = 1; j < prizes[i].size(); j++) {
                int type = prizes[i][j];

                if (stickers[type] < times) {
                    times = stickers[type];
                }
            }

            total += times * money[i];
        }

        cout << total << '\n';
    }
}