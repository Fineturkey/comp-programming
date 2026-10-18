#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line, word;
    getline(cin, line);
    stringstream ss(line);

    // Get a count on how many words there are in total
    int k = 0;
    while (ss >> word)
        k++;

    int n;
    cin >> n;

    vector<string> kids(n), teams[2];
    for (auto &name : kids)
        cin >> name;

    int pos = 0, team = 0;

    while (n > 0)
    {
        // Find the kid who gets the last word
        pos = (pos + k - 1) % n;

        // Add the kid to the current team, then remove them
        teams[team].push_back(kids[pos]);
        kids.erase(kids.begin() + pos);
        n--;

        // Switch to the other team
        if (team == 0)
        {
            team = 1;
        }
        else
        {
            team = 0;
        }
    }

    // Print each team's size and names
    for (int i = 0; i < 2; i++)
    {
        cout << teams[i].size() << '\n';

        for (int j = 0; j < teams[i].size(); j++)
        {
            cout << teams[i][j] << '\n';
        }
    }
}