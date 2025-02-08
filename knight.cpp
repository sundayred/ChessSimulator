#include "knight.h"
#include <string>
#include <iostream>
using namespace std;
board KnightBoard;

int knight::getCount()
{
	return count;
}

std::string knight::getName()
{
	return name;
}

int knight::knightMoves(board* board) {
    board->CopyTo(&KnightBoard);
    int moveList[8][2];
    int numKnights = 1;
    int currentRow;
    int currentCol;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (KnightBoard.setupBoard[i][j] == "[N]") {
                KnightBoard.setupBoard[i][j] = "[" + to_string(numKnights) + "]";
                numKnights++;
            }
        }
    }
    KnightBoard.printGrid();
    std::cout << "Which Knight to Move or press 0 to exit: ";
    int numChosen;
    cin >> numChosen;
    if (numChosen == 0)
    {
        return 0;
    }
    numChosen = KnightBoard.numChecks(numChosen, 1, numKnights - 1);


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (KnightBoard.setupBoard[i][j] == "[" + to_string(numChosen) + "]") {
                currentCol = j;
                currentRow = i;
                break;
            }
        }
    }

    int moves = 1;

    int row, col;
    board->CopyTo(&KnightBoard);
   std::cout << "\nFor this position legal moves are:\n";

    // to move up
    row = currentRow - 2;
    col = currentCol + 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
        KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";

        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;

        moves++;
    }

    row = currentRow - 1;
    col = currentCol + 2;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
       KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move right
    row = currentRow + 1;
    col = currentCol + 2;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
       KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    row = currentRow + 2;
    col = currentCol + 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
       KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move down
    row = currentRow + 2;
    col = currentCol - 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
       KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    row = currentRow + 1;
    col = currentCol - 2;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
       KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // to move left
    row = currentRow - 1;
    col = currentCol - 2;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
       KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    row = currentRow - 2;
    col = currentCol - 1;
    if ((row >= 0 && row < 8 && col >= 0 && col < 8) && board->setupBoard[row][col] == "[ ]") {
       std::cout << std::to_string(moves) + ". ";
       std::cout << "board[" << row << "][" << col << "] or \n";
        KnightBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
        moveList[moves - 1][0] = row;
        moveList[moves - 1][1] = col;
        moves++;
    }

    // Show the board with all legal moves from the current position
    // Legal moves will be indicated as 'L'
    //Update Main Board based on movement on KnightBoard
    KnightBoard.printGrid();


    cout << "Enter choice to run, press 0 to exit: ";
    int option;
    cin >> option;
    if (option == 0)
    {
        return 0;
    }
    option = KnightBoard.numChecks(option, 1, moves - 1);
    
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