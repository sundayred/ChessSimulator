#pragma once
#ifndef ROOK_H
#define ROOK_H
#include <string>
#include "board.h"
class rook
{
private:
	int count = 2;
	std::string name = "R";
public:
	int getCount();
	std::string getName();
	int moveRook(board*);
};
#endif 
