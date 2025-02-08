#pragma once
#ifndef pawn_h
#define pawn_h
#include <string>
#include "board.h"

class pawn {
private:
	int count = 8;
	std::string name = "P";
public:
	int getCount();
	std::string getName();
	int movePawn(board*);
};
#endif

