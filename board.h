#pragma once
#ifndef Board_h
#define Board_h
#include <string>

class board {
private:
public:
    static const int ROWS = 8;
    static const int COLS = 8;
    std::string setupBoard[ROWS][COLS];
    void startBoard();
    void CopyTo(board* newBoard);
    void printGrid();
    int numChecks(int, int, int);
};
#endif
