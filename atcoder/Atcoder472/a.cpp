#include <iostream>

using namespace std;

int main() {
    string S;

    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        if(S[i] != 'A' && S[i] != 'a') {
            S[i] = '.';
        }
    }

    cout << S;

    return 0;
}