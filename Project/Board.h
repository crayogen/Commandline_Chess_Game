#pragma once
#include "string"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"
using namespace std;
class Board
{
private:
	//char b[8][8];
	//instantiating all 32 pieces
	King White_King;
	King Black_King;
	Queen White_Queen;
	Queen Black_Queen;
	Pawn White_Pawn_1;
	Pawn White_Pawn_2;
	Pawn White_Pawn_3;
	Pawn White_Pawn_4;
	Pawn White_Pawn_5;
	Pawn White_Pawn_6;
	Pawn White_Pawn_7;
	Pawn White_Pawn_8;
	Pawn Black_Pawn_1;
	Pawn Black_Pawn_2;
	Pawn Black_Pawn_3;
	Pawn Black_Pawn_4;
	Pawn Black_Pawn_5;
	Pawn Black_Pawn_6;
	Pawn Black_Pawn_7;
	Pawn Black_Pawn_8;
	Rook White_Rook_1, White_Rook_2, Black_Rook_1, Black_Rook_2;
	Knight White_Knight_1, White_Knight_2, Black_Knight_1, Black_Knight_2;
	Bishop White_Bishop_1, White_Bishop_2, Black_Bishop_1, Black_Bishop_2;
public:
	Board();
	~Board();
	void Display(); //iss mai side par coordinates daalne
	void set_board(int a, int b); //a is initial position of piece and b is final- checks isske andar hi ya bahir?
 };

