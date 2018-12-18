#include "pch.h"
#include "Knight.h"
#include <iostream>
using namespace std;

Knight::Knight() {}


Knight::Knight(int teamNum, int position, Chess_Piece* board[8][8]) : Chess_Piece(teamNum, position)
{
	if (teamNum == 2)
		symbol = "n";
	else symbol = "N";
	getValidMoves(board);
}


Knight::~Knight()
{
}

bool Knight::isBlocked(int dest, Chess_Piece* board[8][8]) {
	return true;
}

void Knight::getValidMoves(Chess_Piece* board[8][8])//On board, correct positions, no blockage on the way-blockage if same colour, opp colour tu kaat raha ho ga
{
	int src = position;
	int row_src = src / 10; int col_src = src % 10;
	numberOfValidMoves = 0;

	for (int row = 0; row < 8; row++) {
		for (int column = 0; column < 8; column++) {
			bool isNull = (board[row][column] == NULL);
			int dest = row * 10 + column;
			if (isBlocked(dest, board) || isOutofBoard(dest))
				continue;
			if ((row == row_src) && (column == col_src)) //move on itsef
				continue;
			if (board[row][column] == NULL || board[row][column]->getteamNum() != teamNum) {
				if (((row == row_src + 2) || (row == row_src - 2)) && ((column == col_src + 1) || (column == col_src - 1))) {
					ValidMoves[numberOfValidMoves] = (row * 10 + column);
					numberOfValidMoves++;
				}

				if (((row == row_src + 1) || (row == row_src - 1)) && ((column == col_src + 2) || (column == col_src - 2))) {
					ValidMoves[numberOfValidMoves] = (row * 10 + column);
					numberOfValidMoves++;
				}
			}
			if (!isNull && (board[row][column]->getteamNum() == teamNum)) //own team peice here
				continue;
		}
	}
}

