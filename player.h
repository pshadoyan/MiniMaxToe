//
// Created by Patrick on 9/12/2019.
//

#ifndef TICTAC_PLAYER_H
#define TICTAC_PLAYER_H

#include "board.h"

struct Move {
    Move() {};
    Move(int s) : score(s) {}

    int x;
    int y;
    int score;
};

class player {
    Move optimal;
public:
    Move get_optimal(board &b, int player);
};


#endif //TICTAC_PLAYER_H
