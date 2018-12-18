#pragma once
#include "Chess_Piece.h"

class Bishop : public Chess_Piece
{
public:
	Bishop(int teamNum, int pos, Chess_Piece* board[8][8]);
	~Bishop();
	void getValidMoves(Chess_Piece* board[8][8]);
};

