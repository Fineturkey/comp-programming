#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Okay, the first input is n = number of total ingredients
    // x is the total portions that will be made using n ingredients
    // y is the number of portions we want
    // each a of n is each respective ingredient
    // this is pretty simple, all we're going to do is do y / x in order to find the 'scale' of each ingredient
    // from there multiple each a by the "scale" and then output it back into a list
    // that should give us our answer

    int n;
    double x, y;

    // x and y need to be double due to the nature of the division operand.
    // Basically whats occuring is since x and y are ints even though the ing is a double it still gets assigned as an int

    cin >> n >> x >> y;
    vector <int> ing (n);
    for (int i = 0; i < n; i++) {cin >> ing[i];}

    // okay, we have the list of ingredients
    // do y / x 

    // realistically we don't even need the scale 

    for (int i = 0; i < n; i++) {ing[i] = ing[i] * y / x;}
    
    // lastly just output the vector and it should be correct...?

    for (int i = 0; i < n; i++) {cout << ing[i] << '\n';}
}