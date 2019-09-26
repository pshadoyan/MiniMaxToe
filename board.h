//
// Created by Patrick on 9/11/2019.
//

#ifndef TICTAC_BOARD_H
#define TICTAC_BOARD_H

#include <vector>
#include <iostream>

using namespace std;

class board {

    vector<vector<int>> my_board;

public:
    /*
     * Initialize a 3x3 board, all set to 0
     */
    board();

    /*
     * Destruct
     */
    ~board();

    /*
     * Retrieve the board
     */
    vector<vector<int>> get_board();

    /*
    * Change at a specified position
    */
    void update_at(int x, int y, int player);

    /*
     * Print a board? Running out of ideas
     * to make this more complex
     */
    void print_board();

    /*
     * Wonder if someone won or not
     */
    void win();

};


#endif //TICTAC_BOARD_H
