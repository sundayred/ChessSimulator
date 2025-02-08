#include <iostream>
#include <string>
#include "board.h"
#include "piece.h"
#include "knight.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
using namespace std;

board bobj;
knight knightCount[2];
pawn pawnCount[8];
rook rookCount[2];
bishop bishopCount[2];
king k;
queen q;

void setup()
{
    bobj.startBoard();

    for (int i = 0; i < 8; i++) {
        bobj.setupBoard[6][i] = "[" + pawnCount[i].getName()  + "]";
    }

    bobj.setupBoard[7][0] = "[" + rookCount[0].getName() + "]";
    bobj.setupBoard[7][7] = "[" + rookCount[1].getName() + "]";
    bobj.setupBoard[7][1] = "[" + knightCount[0].getName() + "]";
    bobj.setupBoard[7][6] = "[" + knightCount[1].getName() + "]";
    bobj.setupBoard[7][2] = "[" + bishopCount[0].getName() + "]";
    bobj.setupBoard[7][5] = "[" + bishopCount[1].getName() + "]";
    bobj.setupBoard[7][3] = "[" + k.getName() + "]";
    bobj.setupBoard[7][4] = "[" + q.getName() + "]";
    bobj.printGrid();
}

int numChecks(int nums, int min, int max) {
    bool Continue = true;
    while (Continue)
    {
        Continue = false;
        if (nums < min || nums > max)
        {
            cout << "Enter numerical in range (" << min << ", " << max << "): ";
            cin >> nums;
            Continue = true;
        }
    }
    return nums;
}

int main() {
    int row = 0;
    char col;
    int moveList[9][2];
    int option = 0;
    int numCol = 0;
    int usrOption = 0;
    knight obj1;
    knight obj2;
    knightCount[0] = obj1;
    knightCount[1] = obj2;

    for (int i = 0; i < 8; i++) {
        pawn p;
        pawnCount[i] = p;
    }

    pawn run;

    rook r1;
    rook r2;
    rookCount[0] = r1;
    rookCount[1] = r2;

    bishop b1;
    bishop b2;
    bishopCount[0] = b1;
    bishopCount[1] = b2;

    setup();

    while (usrOption != 7) {

        if (usrOption == 7) { break; }

        system("cls");
        cout << "       *** Welcome to Chess ***" << endl;
        cout << "\n";
        cout << "Enter choices from 1-7" << endl;

        cout << "1. Play Pawn" << endl;

        cout << "2. Play Knights" << endl;

        cout << "3. Play Rook" << endl;

        cout << "4. Play King" << endl;

        cout << "5. Play Queen" << endl;

        cout << "6. Play Bishop" << endl;

        cout << "7. Quit" << endl;

        cout << "\n\nChoice: ";



        cin >> usrOption;

        usrOption = numChecks(usrOption, 1, 7);

        int roomTypeNum;



		switch (usrOption)
		{
		case 1:
			system("cls");
			{
				run.movePawn(&bobj);
			}
			system("pause");
			break;

		case 2:

			system("cls");
			{
				obj1.knightMoves(&bobj);
			}
			system("pause");
			break;

		case 3:
			system("cls");
			{
				r1.moveRook(&bobj);
			}
			system("pause");
			break;

		case 4:
			system("cls");
			{
				k.kingMoves(&bobj);
			}
			system("pause");
            break;

		case 5:
			system("cls");
			q.queenMoves(&bobj);
			cout << "\n";
			system("pause");
            break;

        case 6:
            system("cls");
            b1.bishopMoves(&bobj);
            cout << "\n";
            system("pause");
            break;
		}
	}

}