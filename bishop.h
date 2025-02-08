#pragma once
#ifndef BISHOP_H
#define BISHOP_H
#include <string>
#include "board.h"

class bishop
{
private:
	int count = 2;
	std::string name = "B";
public: 
	int getCount();
	std::string getName();
	int bishopMoves(board*);
};
#endif 
