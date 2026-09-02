#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    int sum = 0;
    cin >> n;
    int m = n/2;
    vector<int> list(n);

    for (int i = 0; i < list.size(); i++) {
        cin >> list[i];
    }

    for(int i = m; i < list.size(); i++) {
        sum += list[i];
    }

    cout << sum;
    return 0;
}
