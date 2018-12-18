#pragma once
#include "Chess_Piece.h"
class Rook :public Chess_Piece
{
public:
	Rook(int teamNum, int pos, Chess_Piece* board[8][8]);
	~Rook();
	void getValidMoves(Chess_Piece* board[8][8]);
};
