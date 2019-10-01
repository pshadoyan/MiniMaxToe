//
// Created by Patrick on 9/11/2019.
//
#include "board.h"

/*
 * Initialize a 3x3 board, all set to 0
 */
board::board() {
    my_board = {{0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};
}

/*
 * Retrieve the board
 */
vector<vector<int> > board::get_board() {
    return my_board;
}

/*
* Change at a specified position (if AI, player is always 2)
*/
void board::update_at(int x, int y, int player) {
    if (my_board[x][y] == 0) {
        my_board[x][y] = player;
    }
}

/*
 * Print a board? Running out of ideas
 * to make this more complex
 */
void board::print_board() {
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            cout << my_board[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
 * Wonder if someone won or not
 * Pattern matching could be used to reduce time complexity
 * However, pattern matching is an isolated solution for set
 * size. If board size were increased, additional patterns
 * have to be generated (either manually or algorithmically).
 */
int board::win() {
    int number;
    /*
     * Check all horizontals
     */
    for (int i = 0; i < 3; i++) {
        number = 0;
        for (int j = 0; j < 3; j++) {
            number += my_board[i][j];
            if (number == 3 && j != 2) {
                break;
            } else if (number == 3) {
                return 1;
            }
        }
        if (number == 6) {
            return 2;
        }
    }
    /*
     * Check all verticals
     */
    for (int i = 0; i < 3; i++) {
        number = 0;
        for (int j = 0; j < 3; j++) {
            number += my_board[j][i];
            if (number == 3 && j != 2) {
                break;
            } else if (number == 3) {
                return 1;
            }
        }
        if (number == 6) {
            return 2;
        }
    }
    /*
     * Check all diagonals (y=x | reverse diags (2,0 & 0,2))
     */
    number = 0;
    for (int i = 0; i < 3; i++) {
        number += my_board[i][i];
        if (number == 6) {
            return 2;
        }
        if (number == 3 && i != 2) {
            break;
        } else if (number == 3) {
            return 1;
        }
    }
    /*
     * This is repulsive code, if the board were big enough
     * it would warrant using something like slope for the anti-diag
     */
    if (my_board[2][0] != 0 && my_board[0][2] != 0 && my_board[1][1] != 0) {
        if (my_board[2][0] == 1 && my_board[0][2] == 1 && my_board[1][1] == 1) {
            return 1;
        }
        if (my_board[2][0] == 2 && my_board[0][2] == 2 && my_board[1][1] == 2) {
            return 2;
        }
    }
    /*
     * Explicit tie definition
     */
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            number += my_board[i][j];
        }
    }
    if (number == 0) {
        return 0;
    }
    return 3;
}

