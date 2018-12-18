#pragma once
#include "Chess_Piece.h"
class King :public Chess_Piece
{
public:
	King(int teamNum, int position, Chess_Piece* board[8][8]);
	~King();
	void getValidMoves(Chess_Piece* board[8][8]);
};
