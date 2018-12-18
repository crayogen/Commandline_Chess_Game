#pragma once
#include "Chess_Piece.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "string"

class Game
{
	//change to private
public:
	int Player;
	Chess_Piece *board[8][8] = { NULL };
public:
	Game();
	int ConvertInput(string input);
	void DisplayBoard();
	void play();
	~Game();
};