#pragma once
#ifndef KING_H
#define KING_H
#include <string>
#include "board.h"
class king
{
private:
	int count = 1;
	std::string name = "K";
public:
	int getCount();
	std::string getName();
	int kingMoves(board*);
};
#endif 

