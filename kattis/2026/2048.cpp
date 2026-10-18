#include <iostream>

using namespace std;

int main() {
    /*
    2 2 0 0 
    4 2 0 64
    256 2 4 0
    512 2 2 0

    4 4 4 4 -> 16

    right shift

    0 0 8 8

    0 - 4
    */

    // if we go left, the firstly we want to check our left to see if their matching numbers
    // in the case where they are matching, add them together, check the number to the right of said position
    // and then add them together if theres a number to the right then that one slides over and so on and so forth!

    // once there is an addition, pause the execution and move to the next


    int board[4][4];
    int x = 0;
    int n, m = 0;

    //all this is doing is taking the input
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {

            cin >> board[i][j];
        }
    }

    cin >> x;

    /*
    The fifth line of input contains an integer 0, 1, 2, or 3 that denotes 
    a left, up, right, or down move executed by the player, respectively.
    */
    if(x == '0') {


        for(int i = 0; i < 4; i++) {
            for(int j = 3; j > -1; j--) {
                if(board[i][j] == '0') {
                    continue;
                }
                else {
                    board[i][j];
                    
                }
            }
        }
    }
    return 0;
}