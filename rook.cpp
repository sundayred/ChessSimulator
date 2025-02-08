#include "rook.h"
#include <string>
#include <iostream>
using namespace std;
board rookBoard;

int rook::getCount()
{
	return count;
}

std::string rook::getName()
{
	return name;
}

int rook::moveRook(board* board)
{
    board->CopyTo(&rookBoard);
    int moveList[100][2];
    int numRook= 1;
    int currentRow;
    int currentCol;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (rookBoard.setupBoard[i][j] == "[R]") {
                rookBoard.setupBoard[i][j] = "[" + to_string(numRook) + "]";
                numRook++;
            }
        }
    }
    rookBoard.printGrid();
    std::cout << "Which Rook to Move or enter 0 to exit: ";
    int numChosen;
    cin >> numChosen;
    if (numChosen == 0)
    {
        return 0;
    }
    numChosen = rookBoard.numChecks(numChosen, 1, numRook - 1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (rookBoard.setupBoard[i][j] == "[" + to_string(numChosen) + "]") {
                currentCol = j;
                currentRow = i;
                break;
            }
        }
    }

    int moves = 1;

    int row, col;
    board->CopyTo(&rookBoard);
    std::cout << "\nFor this position legal moves are:\n";

    bool CheckUp = true;
    bool CheckDown = true;
    bool CheckLeft = true;
    bool CheckRight = true;

    for (int i = 1; i < 9; i++)
    {
        if (CheckDown) {
            row = currentRow + i;
            col = currentCol;
            if (row >= 8 || board->setupBoard[row][col] != "[ ]") {
                CheckDown = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                rookBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;

                moves++;

            }
        }
        if (CheckUp) {
            row = currentRow - i;
            col = currentCol;
            if (row < 0 || board->setupBoard[row][col] != "[ ]") {
                CheckUp = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                rookBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;

                moves++;

            }
        }
        if (CheckLeft) {
            row = currentRow;
            col = currentCol - i;
            if (col < 0 || board->setupBoard[row][col] != "[ ]") {
                CheckLeft = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                rookBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;

                moves++;

            }
        }
        if (CheckRight) {
            row = currentRow;
            col = currentCol + i;
            if (col >= 8 || board->setupBoard[row][col] != "[ ]") {
                CheckRight = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                rookBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;

                moves++;

            }
        }
    }

    rookBoard.printGrid();

    cout << "Enter choice to run, press 0 to exit: ";
    int option;
    cin >> option;
    if (option == 0)
    {
        return 0;
    }
    option = rookBoard.numChecks(option, 1, moves - 1);

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