/*
Store each note's fingering in a 10-element vector.
Compare each note with the previous one and count fingers that change from released to pressed.
Have a previous and a current vector in order to keep track of which key is being pressed, or lifted.
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, vector<int>> makeFingerings()
{
    return {
        {'c', {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}},
        {'d', {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'e', {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'f', {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'g', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'a', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'b', {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
        {'C', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'D', {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
        {'E', {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
        {'F', {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
        {'G', {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
        {'A', {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {'B', {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}}};
}

vector<int> countPresses(const string &song, unordered_map<char, vector<int>> &fingerings)
{
    vector<int> pressCounts(10, 0);
    vector<int> previous(10, 0);

    for (char note : song)
    {
        vector<int> current = fingerings[note];

        for (int finger = 0; finger < 10; finger++)
        {
            pressCounts[finger] += (current[finger] == 1 && previous[finger] == 0);
        }
        previous = current;
    }

    return pressCounts;
}

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();

    unordered_map<char, vector<int>> fingerings = makeFingerings();

    for (int caseNumber = 0; caseNumber < cases; caseNumber++)
    {
        string song;
        getline(cin, song);

        vector<int> pressCounts = countPresses(song, fingerings);

        for (int finger = 0; finger < 10; finger++)
        {
            cout << pressCounts[finger] << (finger == 9 ? '\n' : ' ');
        }
    }

    return 0;
}