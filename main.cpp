#include "board.h"
#include "player.h"

int main() {

    board b;
    player AI;

    int game_type;
    int in_x = 0;
    int in_y = 0;

    bool input_loop;

    cout << "Would you like to play the AI? Type 1 for yes, 0 for no: ";
    cin >> game_type;
    cout << endl;
    if (game_type == 1) {
        for (int i = 0; i < 9; i++) {
            while (!input_loop && i%2 != 1) {
                cout << "Pick a x:  ";
                cin >> in_x;
                cout << endl;
                cout << "Pick a y:  ";
                cin >> in_y;
                cout << endl;
                if (b.get_board()[in_x][in_y] != 0) {
                    cout << "Nice try! Pick a different spot!:  " << endl;
                } else {
                    input_loop = true;
                }
            }
            if (i % 2 == 1) {
                b.update_at(AI.get_optimal(b,2).x, AI.get_optimal(b,2).y, 2);
                if(b.win() == 2)
                {
                    cout << "AI Player Wins" << endl;
                }
                b.print_board();
            } else {
                b.update_at(in_x, in_y, i % 2 + 1);
                if(b.win() == 2)
                {
                    cout << "Player 1 Wins" << endl;
                }
                b.print_board();
            }
            if(b.win() == 0)
            {
                cout << "Nobody Wins" << endl;
            }
            input_loop = false;
        }
    }

    return 0;
}