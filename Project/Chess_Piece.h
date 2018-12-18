#pragma once
#include "string"
/*#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"*/
using namespace std;

class Chess_Piece
{
protected:
	string symbol;
	int teamNum;
	int position;
	int ValidMoves[100];
	int numberOfValidMoves=0;

public:
	Chess_Piece() { teamNum = 0; };
	Chess_Piece(int teamNum, int position);
	~Chess_Piece();
	void setPosition(int position);
	int getPosition();
	string getSymbol();
	int getteamNum();

	bool isOutofBoard(int dest);
	bool isValidMove(int dest, Chess_Piece* board[8][8]);
	int Check(Chess_Piece *board[8][8]);
	bool Checkmate(Chess_Piece *board[8][8], int checkedKingPositon);
	int Move(int dest, Chess_Piece *board[8][8], int player);
	
	virtual bool isBlocked(int dest, Chess_Piece *board[8][8]); //horse will have to overwrite this
	virtual void getValidMoves(Chess_Piece* board[8][8]) {}; //every peice has a seperate move
};