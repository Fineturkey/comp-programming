/*
As far as general approch goes create a map that has its dominant and non dominant value
Check to see the dominant value (B) and then go case by case adding up the points and then tracing how each card contributes 
to the total. Using a pair value you can take care of the dominant vs non-dominant feature. 
Otherwise just map each suit to its respective point value
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int hands;
    char dominantSuit;
    cin >> hands >> dominantSuit;
    int totalHands = hands * 4;
    unordered_map<char, pair<int, int>> points = {
        {'A', {11, 11}},{'K', { 4,  4}},{'Q', { 3,  3}},{'J', { 2, 20}},
        {'T', {10, 10}},{'9', { 0, 14}},{'8', { 0,  0}},{'7', { 0,  0}}
    };

    int total = 0;
    for (int i = 0; i < totalHands; i++) {
        string card;
        cin >> card;
        char rank = card[0];
        char suit = card[1];
        int dominant = (suit == dominantSuit);
        total += points[rank].first * (1 - dominant) + points[rank].second * dominant;
    }
    cout << total;
    return 0;
}