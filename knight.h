#pragma once
#ifndef KNIGHT_H
#define KNIGHT_H
#include <string>
#include "board.h"
class knight
{
private:
	int count = 2;
	std::string name = "N";
public:
	int getCount();
	std::string getName();
	int knightMoves(board*);
};
#endif 
