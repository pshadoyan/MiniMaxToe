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
* Change at a specified position (if AI, player is always 2)
*/
void board::update_at(int x, int y){
    my_board[x][y] = 2;
}
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
            if(my_board[i][j] == 0)  //If an element is set to 0, there isn't a win on the horizontal
            {
                break;
            }
            number += my_board[i][j];
        }
        if (number == 6) {
            cout << "Winner is player 2" << endl;
            return 2;
        }
        if (number == 3) {
            cout << "Winner is player 1" << endl;
            return 1;
        }
    }
    /*
     * Check all verticals
     */
    for (int i = 0; i < 3; i++) {
        number = 0;
        for (int j = 0; j < 3; j++) {
            if(my_board[i][j] == 0)  //If an element is set to 0, there isn't a win on the vertical
            {
                break;
            }
            number += my_board[j][i];
        }
        if (number == 6) {
            cout << "Winner is player 2" << endl;
            return 2;
        }
        if (number == 3) {
            cout << "Winner is player 1" << endl;
            return 1;
        }
    }
    /*
     * Check all diagonals (y=x | reverse diags (2,0 & 0,2))
     */
    for (int i = 0; i < 3; i++) {
        if(my_board[i][i] == 0) //If an element is set to 0, there isn't a win on the diagonal
        {
            break;
        }
            number = 0;
            number += my_board[i][i];
        if (number == 6) {
            cout << "Winner is player 2" << endl;
            return 2;
        }
        if (number == 3 && i == 2) {
            cout << "Winner is player 1" << endl;
            return 1;
        }
    }
    /*
     * This is repulsive code
     */
    if(my_board[2][0] != 0 && my_board[2][0] != 0 && my_board[1][1] != 0)
    {
        if(my_board[2][0] != 1 && my_board[2][0] != 1 && my_board[1][1] != 1)
        {
            cout << "Winner is player 1" << endl;
            return 1;
        }
        if(my_board[2][0] != 2 && my_board[2][0] != 2 && my_board[1][1] != 2)
        {
            cout << "Winner is player 1" << endl;
            return 2;
        }
    }
    return 0;
}

