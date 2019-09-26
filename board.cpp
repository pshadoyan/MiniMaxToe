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
 * Destruct
 */
board::~board() {
    cout << "The End" << endl;
}

/*
 * Retrieve the board
 */
vector<vector<int>> board::get_board() {
    return my_board;
}

/*
* Change at a specified position
*/
void board::update_at(int x, int y, int player) {
    my_board[x][y] = player;
}

/*
 * Print a board? Running out of ideas
 * to make this more complex
 */
void board::print_board() {
    for (int i = 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            cout << my_board[j][i] << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

/*
 * Wonder if someone won or not
 */
void board::win() {
    /*
     * Tie?
     */
    int number = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            number += my_board[i][j];
        }
    }
    cout << number << endl;
    if (number > 14 || number < 13) { //logic only works in the case of a full board
        cout << "Tie" << endl;
    }
    /*
     * Check all horizontals
     */
    for (int i = 0; i < 3; i++) {
        number = 0;
        for (int j = 0; j < 3; j++) {
            number += my_board[i][j];
        }
        if (number == 6) {
            cout << "Winner is player 2" << endl;
        }
    }
    /*
     * Check all verticals
     */
    for (int i = 0; i < 3; i++) {
        number = 0;
        for (int j = 0; j < 3; j++) {
            number += my_board[j][i];
        }
        if (number == 6) {
            cout << "Winner is player 2" << endl;
        }
    }
        /*
     * Check all diagonals (y=x | reverse diags (2,0 & 0,2))
     */
    for (int i = 0; i < 3; i++) {
        number = 0;
            number += my_board[i][i];
        if (number == 6) {
            cout << "Winner is player 2" << endl;
    }

    }
}

