#pragma once
#include "Chess_Piece.h"
class Knight : public Chess_Piece
{
public:
	Knight();
	Knight(int teamNum, int position, Chess_Piece* board[8][8]);
	~Knight();
	void getValidMoves(Chess_Piece* board[8][8]);
	bool isBlocked(int dest, Chess_Piece* board[8][8]);
};

