#include "bishop.h"
#include <string>
#include <iostream>
using namespace std;
board bishopBoard;

int bishop::getCount()
{
	return count;
}

std::string bishop::getName()
{
	return name;
}

int bishop::bishopMoves(board* board) {
    board->CopyTo(&bishopBoard);
    int moveList[100][2];
    int numBishops = 1;
    int currentRow;
    int currentCol;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (bishopBoard.setupBoard[i][j] == "[B]") {
                bishopBoard.setupBoard[i][j] = "[" + to_string(numBishops) + "]";
                numBishops++;
            }
        }
    }
    bishopBoard.printGrid();
    std::cout << "Which Bishop to Move or enter 0 to exit: ";
    int numChosen;
    cin >> numChosen;
    if (numChosen == 0)
    {
        return 0;
    }
    numChosen = bishopBoard.numChecks(numChosen, 1, numBishops - 1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (bishopBoard.setupBoard[i][j] == "[" + to_string(numChosen) + "]") {
                currentCol = j;
                currentRow = i;
                break;
            }
        }
    }

    int moves = 1;

    int row, col;
    board->CopyTo(&bishopBoard);
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
        if (CheckUpRight) {
            row = currentRow - i;
            col = currentCol + i;
            if ((col >= 8 || row < 0) || (board->setupBoard[row][col] != "[ ]")) {
                CheckUpRight = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                bishopBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
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
                bishopBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;
                moves++;
            }
        }
        if (CheckBotRight) {
            row = currentRow + i;
            col = currentCol + i;
            if ((col >= 8 || row >= 8) || (board->setupBoard[row][col] != "[ ]")) {
                CheckBotRight = false;
            }
            else {
                std::cout << std::to_string(moves) + ". ";
                std::cout << "board[" << row << "][" << col << "] or \n";
                bishopBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
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
                bishopBoard.setupBoard[row][col] = "[" + std::to_string(moves) + "]";
                moveList[moves - 1][0] = row;
                moveList[moves - 1][1] = col;
                moves++;
            }
        }

        //bishopBoard.printGrid();
    }
    // Show the board with all legal moves from the current position
    // Legal moves will be indicated as 'L'
    //Update Main Board based on movement on queenBoard
    bishopBoard.printGrid();


    cout << "Enter choice to run, press 0 to exit: ";
    int option;
    cin >> option;
    if (option == 0)
    {
        return 0;
    }
    option = bishopBoard.numChecks(option, 1, moves - 1);
    
    bool Continue = true;
    while (Continue)
    {
        if (option < 0 || option > moves)
        {
            cout << "Enter numerical in range (" << 1 << ", " << moves << "): ";
            cin >> option;
            Continue = true;
        }
        if (option > 0 && option <= moves)
        {
            Continue = false;
        }
    }

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