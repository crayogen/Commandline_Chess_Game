#include "pch.h"
#include "Queen.h"
#include "iostream"
using namespace std;

Queen::Queen(int teamNum, int position, Chess_Piece* board[8][8]) : Chess_Piece(teamNum, position)
{
	if (teamNum == 2)
		symbol = "q";
	else symbol = "Q";
	getValidMoves(board);
}


Queen::~Queen()
{
}

void Queen::getValidMoves(Chess_Piece* board[8][8])
{
	//teenoun king, rook aur bishop ki moves possible 
	//Bishop moves:
	int src = position;
	int row_src = src / 10; int col_src = src % 10;
	numberOfValidMoves = 0;

	int offsetNegativeDiagonal = row_src - col_src;
	int offsetPositiveDiagonal = row_src + col_src - 7;

	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			bool isNull = (board[row][column] == NULL);
			int dest = row * 10 + column;
			if (isOutofBoard(dest))
				continue;
			if ((row == row_src) && (column == col_src)) //move on itself
				continue;
			if (!isNull && (board[row][column]->getteamNum() == teamNum)) //own team peice here
				continue;
			if (row == column + offsetNegativeDiagonal) //row and column are equal along the negative diagonal
				ValidMoves[numberOfValidMoves++] = (row * 10 + column);
			else if (row == 7 - column + offsetPositiveDiagonal) //y=-x+c
				ValidMoves[numberOfValidMoves++] = (row * 10 + column);
		}
	}

	//rook moves: 
	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
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