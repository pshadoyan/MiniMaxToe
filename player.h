//
// Created by Patrick on 9/12/2019.
//

#ifndef TICTAC_PLAYER_H
#define TICTAC_PLAYER_H

#include "board.h"

struct Move {
    int x;
    int y;
};

class player {
    Move optimal;
public:
    Move get_optimal(board& b);
};


#endif //TICTAC_PLAYER_H
