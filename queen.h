#pragma once
#ifndef QUEEN_H
#define QUEEN_H
#include <string>
#include "board.h"
class queen {
private:
	int count = 1; // prev 8
	std::string name = "Q";
public:
	int getCount();
	std::string getName();
	int queenMoves(board*);
};
#endif


