#include "queen.h"
#include <string>
#include <iostream>
using namespace std;
board queenBoard;

int queen::getCount()
{
	return count;
}

std::string queen::getName()
{
	return name;
}

int queen::queenMoves(board* board) {
    board->CopyTo(&queenBoard);
    int moveList[100][2];
    int numQueens = 1;
    int currentRow;
    int currentCol;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (queenBoard.setupBoard[i][j] == "[Q]") {
                queenBoard.setupBoard[i][j] = "[" + to_string(numQueens) + "]";
                numQueens++;
            }
        }
    }
    queenBoard.printGrid();
    std::cout << "Which Queen to Move or enter 0 to exit: ";
    int numChosen;
    //Error Checking
    cin >> numChosen;
    if (numChosen == 0)
    {
        return 0;
    }
    numChosen = queenBoard.numChecks(numChosen, 1, numQueens - 1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (queenBoard.setupBoard[i][j] == "[" + to_string(numChosen) + "]") {
                currentCol = j;
                currentRow = i;
                break;
            }
        }
    }

    int moves = 1;

    int row, col;
    board->CopyTo(&queenBoard);
    std::cout << "\nFor this position legal moves are:\n";

    bool CheckUp = true;
    bool CheckDown = true;
    bool CheckLeft = true;
    bool CheckRight = true;
    bool CheckUpRight = true;
    bool CheckUpLeft = true;
    bool CheckBotRight = true;
    bool CheckBotLeft = true;
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
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

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
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

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
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

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
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;

                moves++;

            }
        }
        if (CheckUpRight) {
            row = currentRow - i;
            col = currentCol + i;
            if ((col >= 8 || row < 0) || (board->setupBoard[row][col] != "[ ]")) {
                CheckUpRight = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;
                moves++;
            }
        }
        if (CheckUpLeft) {
            row = currentRow - i;
            col = currentCol - i;
            if ((col < 0 || row < 0) || (board->setupBoard[row][col] != "[ ]")) {
                CheckUpLeft = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;
                moves++;
            }
        }
        if (CheckBotRight) {
            row = currentRow + i;
            col = currentCol + i;
            if ((col >= 8  || row >= 8) || (board->setupBoard[row][col] != "[ ]")) {
                CheckBotRight = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;
                moves++;
            }
        }
        if (CheckBotLeft) {
            row = currentRow + i;
            col = currentCol - i;
            if ((col < 0 || row >= 8) || (board->setupBoard[row][col] != "[ ]")) {
                CheckBotLeft = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                queenBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;
                moves++;
            }
        }

        //queenBoard.printGrid();
    }
    // Show the board with all legal moves from the current position
    // Legal moves will be indicated as 'L'
    //Update Main Board based on movement on queenBoard
    queenBoard.printGrid();


    cout << "Enter choice to run, press 0 to exit: ";
    int option;
    cin >> option;
    if (option == 0)
    {
        return 0;
    }
    option = queenBoard.numChecks(option, 1, moves - 1);

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