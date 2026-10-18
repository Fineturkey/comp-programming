#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, string> dictionary;
    string line;

    // Read dictionary entries until the blank line
    while (getline(cin, line))
    {
        if (line == "")
        {
            break;
        }

        string english, foreign;
        stringstream ss(line);
        ss >> english >> foreign;

        // Save the English translation under the foreign word
        dictionary[foreign] = english;
    }

    string word;

    // Keep reading words until the input ends
    while (cin >> word)
    {
        if (dictionary.count(word) > 0)
        {
            cout << dictionary[word] << '\n';
        }
        else
        {
            cout << "eh" << '\n';
        }
    }
}