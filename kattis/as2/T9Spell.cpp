/*
Map each character to its keypad presses.
Read each message and add the presses for each character.
Add a space when two consecutive characters use the same keypad key.
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> makePresses() {
    unordered_map<char, string> presses = {
        {'a', "2"},    {'b', "22"},   {'c', "222"},
        {'d', "3"},    {'e', "33"},   {'f', "333"},
        {'g', "4"},    {'h', "44"},   {'i', "444"},
        {'j', "5"},    {'k', "55"},   {'l', "555"},
        {'m', "6"},    {'n', "66"},   {'o', "666"},
        {'p', "7"},    {'q', "77"},   {'r', "777"},  {'s', "7777"},
        {'t', "8"},    {'u', "88"},   {'v', "888"},
        {'w', "9"},    {'x', "99"},   {'y', "999"},  {'z', "9999"},
        {' ', "0"}
    };

    return presses;
}

string convertMessage(const string& message, unordered_map<char, string>& presses) {
    string converted;
    char previousKey = '\0';

    for (char character : message) {
        string keyPresses = presses[character];
        char currentKey = keyPresses[0];

        if (currentKey == previousKey) converted += ' ';

        converted += keyPresses;
        previousKey = currentKey;
    }

    return converted;
}

int main() {
    int cases;
    cin >> cases;
    cin.ignore();

    unordered_map<char, string> presses = makePresses();

    for (int caseNumber = 1; caseNumber <= cases; caseNumber++) {
        string message;
        getline(cin, message);

        cout << "Case #" << caseNumber << ": "
             << convertMessage(message, presses) << '\n';
    }

    return 0;
}