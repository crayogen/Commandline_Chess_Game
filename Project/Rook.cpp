#include "pch.h"
#include "Rook.h"
#include "iostream"
using namespace std;

Rook::Rook(int teamNum, int pos, Chess_Piece* board[8][8]) : Chess_Piece(teamNum, pos)
{
	if (teamNum == 2)
		symbol = "r";
	else symbol = "R";
	getValidMoves(board);
}

Rook::~Rook() {}


void Rook::getValidMoves(Chess_Piece* board[8][8])
{
	int src = position;
	int row_src = src / 10;
	int col_src = src % 10;
	numberOfValidMoves = 0;

	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			int dest = row * 10 + column;
			if (isOutofBoard(dest))
				continue;
			bool isNull = (board[row][column] == NULL);
			if (((row == row_src) || (column == col_src))) {
				if (row == row_src && column == col_src)
					continue;
				else if (!isNull && (board[row][column]->getteamNum() == teamNum)) //own team peice here
					continue;
				else {
					ValidMoves[numberOfValidMoves] = ((row * 10) + column);
					numberOfValidMoves++;
				}
			}
		}
	}
}
