#pragma once
#include "Chess_Piece.h"
class Queen :public Chess_Piece
{
public:
	Queen(int teamNum, int position, Chess_Piece* board[8][8]);
	~Queen();
	void getValidMoves(Chess_Piece* board[8][8]);
};


/*#pragma once
#include "Chess_Piece.h"
class Queen:public Chess_Piece
{
public:
	Queen(int a, int b);
	~Queen();
	void Movement(int b);
	int Check(int a, bool b);
};*/

