#include "pawn.h"
#include <string>
using namespace std;
#include <iostream>
board pawnBoard;

int pawn::getCount()
{
	return count;
}

std::string pawn::getName()
{
	return name;
}

int pawn::movePawn(board* board)
{
    board->CopyTo(&pawnBoard);
    int moveList[8][2];
    int numPawn = 1;
    int currentRow;
    int currentCol;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pawnBoard.setupBoard[i][j] == "[P]") {
                pawnBoard.setupBoard[i][j] = "[" + to_string(numPawn) + "]";
                numPawn++;
            }
        }
    }
    pawnBoard.printGrid();

    std::cout << "Which Pawn to Move or press 0 to quit: ";
    int numChosen;
    cin >> numChosen;
    if (numChosen == 0)
    {
        exit(0);;
    }
    numChosen = pawnBoard.numChecks(numChosen, 1, numPawn-1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (pawnBoard.setupBoard[i][j] == "[" + to_string(numChosen) + "]") {
                currentCol = j;
                currentRow = i;
                break;
            }
        }
    }

    int moves = 1;

    int row, col;
    board->CopyTo(&pawnBoard);
    std::cout << "\nFor this position legal moves are:\n";

    // to move up
    row = currentRow - 1;
    col = currentCol;

    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        pawnBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;

        moves++;
    }

    // only runs if currentRow is at starting position
    row = currentRow-2;
    if ((currentRow == 6 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        pawnBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;

        moves++;
    }

    pawnBoard.printGrid();

    cout << "Enter choice to run, press 0 to quit: ";

    int option;
    cin >> option;
    if (option == 0)
    {
        exit(0);
    }

    option = pawnBoard.numChecks(option, 1, moves-1);

    if (option >= 1 && option <= moves)
    {
        row = moveList[option - 1][0];
        col = moveList[option - 1][1];

        board->setupBoard[row][col] = "[" + name + "]";
        board->setupBoard[currentRow][currentCol] = "[ ]";

    }

    board->printGrid();
    return moves - 1;

}