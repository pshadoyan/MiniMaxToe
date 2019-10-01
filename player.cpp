//
// Created by Patrick on 9/12/2019.
//

#include "player.h"

Move player::get_optimal(board b, int player) {

    int check = b.win();
    if (check == 2) {
        Move(10);
    } else if (check == 1) {
        Move(-10);
    } else if (check == 0) {
        Move(0);
    }

    vector<Move> moves;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (b.get_board()[i][j] == 0) {
                Move temp;
                temp.x = i;
                temp.y = j;
                b.update_at(i, j, player);
                if (player == 2) {
                    temp.score = get_optimal(b, 1).score;
                } else {
                    temp.score = get_optimal(b, 2).score;
                }
                moves.push_back(temp);
                b.update_at(i, j, 0);
            }
        }
    }

    int bestMove = 0;
    if (player == 2) {
        int bestScore = -100000;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i].score > bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    } else {
        int bestScore = 100000;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i].score < bestScore) {
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }
    return moves[bestMove];
}

