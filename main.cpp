#include "board.h"
#include "player.h"

int main() {

    board b;
    int in_x, in_y;
    bool gc = false;
    player AI;

    for (int i = 0; i < 9; i++) {
        while (!gc) {
            cout << "Pick a x:  ";
            cin >> in_x;
            cout << endl;
            cout << "Pick a y:  ";
            cin >> in_y;
            cout << endl;
            if (b.get_board()[in_x][in_y] != 0) {
                cout << "Nice try! Pick a different spot!  " << endl;
            } else {
                gc = true;
            }
        }
        if(i % 2 == 1)
        {
            AI.get_optimal(b, 2);
        }
        b.update_at(in_x, in_y, i % 2 + 1);
        b.print_board();
        gc = false;
        b.win();

    }


    return 0;
}