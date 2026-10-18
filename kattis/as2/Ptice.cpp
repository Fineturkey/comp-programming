/*
This feels pretty self explanatory, create a vector of each of the three boys iterate through the pattern to see how many matches there are.
In the case where there is a match add to their score, loop through their pattern using % and then keep going until you reach the end of the string.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numLetters;
    string answer;
    string adrian = "ABC";
    string bruno = "BABC";
    string goran = "CCAABB";

    cin >> numLetters >> answer;

    int adrianScore = 0;
    int brunoScore = 0;
    int goranScore = 0;

    for (int i = 0; i < numLetters; i++)
    {
        char correct = answer[i];
        adrianScore += (adrian[i % adrian.size()] == correct);
        brunoScore += (bruno[i % bruno.size()] == correct);
        goranScore += (goran[i % goran.size()] == correct);
    }
    int highest = max({adrianScore, brunoScore, goranScore});
    if (adrianScore == highest) cout << "Adrian\n";
    if (brunoScore == highest) cout << "Bruno\n";
    if (goranScore == highest) cout << "Goran\n";
    return 0;
}