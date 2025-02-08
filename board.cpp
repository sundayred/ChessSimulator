#pragma once
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include "board.h"
#include "piece.h"

// Wooyong Yang

using namespace std;
static const int ROWS = 8;
static const int COLS = 8;

void board::startBoard()
{
    // Initialize array with empty spaces
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            setupBoard[r][c] = "[ ]";
        }
    }
}

void board::printGrid()
{
    // Show the current position on the board
    cout << "\n   1   2   3   4   5   6   7   8\n";
    for (int r = 0; r < ROWS; r++) {
        cout << r + 1;
        for (int c = 0; c < COLS; c++) {
            cout << setw(4) << setupBoard[r][c];
        }

        cout << endl;
    }
}

void board::CopyTo(board* newBoard) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            newBoard->setupBoard[j][i] = setupBoard[j][i];
        }
    }
}

int board::numChecks(int nums, int min, int max) {
    bool Continue = true;
    while (Continue)
    {
        Continue = false;
        if (nums == 0)
        {
            return 0;
        }

        if (nums < min || nums > max)
        {
            cout << "Enter numerical in range (" << min << ", " << max << "): ";
            cin >> nums;
            Continue = true;
        }
    }
    return nums;
}
