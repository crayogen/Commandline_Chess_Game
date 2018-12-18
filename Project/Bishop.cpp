#include "pch.h"
#include "Bishop.h"
#include "iostream"
#include "string"

using namespace std;

Bishop::Bishop(int teamNum, int pos, Chess_Piece* board[8][8]) : Chess_Piece(teamNum, pos) {
	if (teamNum == 2)
		symbol = "b";
	else symbol = "B";
	getValidMoves(board);
}


Bishop::~Bishop() { }

void Bishop::getValidMoves(Chess_Piece* board[8][8]) {
	int src = position;
	int row_src = src / 10; int col_src = src % 10;

	int offsetNegativeDiagonal = row_src - col_src;
	int offsetPositiveDiagonal = row_src + col_src - 7;
	numberOfValidMoves = 0;

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
}
