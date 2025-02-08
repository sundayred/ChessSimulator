#include "king.h"
#include <string>
#include <iostream>
using namespace std;
board kingBoard;

int king::getCount()
{
	return count;
}

std::string king::getName()
{
	return name;
}

int king::kingMoves(board* board) {
    board->CopyTo(&kingBoard);
    int moveList[8][2];
    int numKings = 1;
    int currentRow;
    int currentCol;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (kingBoard.setupBoard[i][j] == "[K]") {
                kingBoard.setupBoard[i][j] = "[" + to_string(numKings) + "]";
                numKings++;
            }
        }
    }
    kingBoard.printGrid();
    std::cout << "Which King to Move: ";
    int numChosen;
    //Error Checking
    cin >> numChosen;
    if (numChosen == 0)
    {
        return 0;
    }
    numChosen = kingBoard.numChecks(numChosen, 1, numKings - 1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (kingBoard.setupBoard[i][j] == "[" + to_string(numChosen) + "]") {
                currentCol = j;
                currentRow = i;
                break;
            }
        }
    }

    int moves = 1;

    int row, col;
    board->CopyTo(&kingBoard);
    std::cout << "\nFor this position legal moves are:\n";

    // to move up
    row = currentRow - 1;
    col = currentCol;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;

        moves++;
    }

    // to move right
    row = currentRow;
    col = currentCol + 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move down
    row = currentRow + 1;
    col = currentCol;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move left
    row = currentRow;
    col = currentCol - 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move diagnal up right
    row = currentRow - 1;
    col = currentCol + 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move diagnal up left
    row = currentRow - 1;
    col = currentCol - 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move diagnal down right
    row = currentRow + 1;
    col = currentCol + 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move diagnal down left
    row = currentRow + 1;
    col = currentCol - 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
        std::cout << std::to_string(moves) + ". ";
        std::cout << "board[" << row << "][" << col << "] or \n";
        kingBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }
    // Show the board with all legal moves from the current position
    // Legal moves will be indicated as 'L'
    //Update Main Board based on movement on kingBoard
    kingBoard.printGrid();


    cout << "Enter choice to run, press 0 to exit: ";
    int option;
    cin >> option;
    if (option == 0)
    {
        return 0;
    }
    option = kingBoard.numChecks(option, 1, moves - 1);

    if (option == 0)
    {
        return 0;
    }
    else if (option >= 1 && option <= moves)
    {
        row = moveList[option - 1][0];
        col = moveList[option - 1][1];

        board->setupBoard[row][col] = "[" + name + "]";
        board->setupBoard[currentRow][currentCol] = "[ ]";

    }
    else if (option == -7)
    {
        cout << "Your current position on the board (input first row, then column): ";
        //cin >> row >> col;
    }

    board->printGrid();
    return moves - 1;

}