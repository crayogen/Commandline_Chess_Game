#include "pch.h"
#include "Pawn.h"
#include "iostream"
using namespace std;

Pawn::Pawn(int teamNum, int pos, Chess_Piece* board[8][8]) : Chess_Piece(teamNum, pos) {
	if (teamNum == 2)
		symbol = "p";
	else symbol = "P";
	getValidMoves(board);
}


Pawn::~Pawn()
{
}

void Pawn::getValidMoves(Chess_Piece* board[8][8])//On board, correct positions, no blockage on the way-blockage if same colour, opp colour tu kaat raha ho ga
{
	int src = position;
	int row_src = src / 10; int col_src = src % 10;
	numberOfValidMoves = 0;

	int row;
	for (int i = 1; i < 3; i++) {
		if (teamNum == 1) row = row_src + i;
		else if (teamNum == 2) row = row_src - i;
		for (int column = col_src - 1; column < col_src + 2; column++) {
			int dest = row * 10 + column;
			if (isOutofBoard(dest))
				continue;
			if (teamNum == 1 && row_src != 1) { //if in initial row, allow double moves
				if (row == row_src + 2)
					continue;
			}
			if (teamNum == 2 && row_src != 6) { //if in initial row,  allow double moves
				if (row == row_src - 2)
					continue;
			}
			if ((row == row_src) && (column == col_src))  //move on itself
				continue;
			if ((column == col_src - 1) || (column == col_src + 1)) {
				if (board[row][column] == NULL)
					continue;
				if (board[row][column]->getteamNum() != teamNum) {//other team peice here diagonals
					ValidMoves[numberOfValidMoves++] = (row * 10 + column);
					continue;
				}
			}
			if (board[row][column] == NULL) {
				ValidMoves[numberOfValidMoves++] = (row * 10 + column);
				continue;

			}
			if (board[row][column]->getteamNum() == teamNum) { //own team peice here
				continue;
			}
		}
	}
}
