#pragma once
#include "Chess_Piece.h"
class Pawn : public Chess_Piece
{
public:
	Pawn(int teamNum, int position, Chess_Piece* board[8][8]);
	~Pawn();
	void getValidMoves(Chess_Piece* board[8][8]);
};
