#include "pch.h"
#include "King.h"
#include <iostream>

using namespace std;

King::King(int teamNum, int pos, Chess_Piece* board[8][8]) : Chess_Piece(teamNum, pos) {
	if (teamNum == 2)
		symbol = "k";
	else symbol = "K";
	getValidMoves(board);
}


King::~King() { }

void King::getValidMoves(Chess_Piece* board[8][8])//On board, correct positions, no blockage on the way
{	
	int src = position;
	int row_src = src / 10; int col_src = src % 10;
	numberOfValidMoves = 0;
	
	for (int row = 0; row < 8; row++)  {
		for (int column = 0; column <  8; column++) {
			int dest = row * 10 + column;
			if (isOutofBoard(dest))
				continue;
			if (board[row][column] == NULL || board[row][column]->getteamNum() != teamNum) {
				int rdif = abs(row_src - row);
				int cdif = abs(col_src - column);
				if (rdif == 0 && cdif == 0)
					continue;
				if ((rdif == 0 || rdif == 1) && (cdif == 1 || cdif == 0)) {
					ValidMoves[numberOfValidMoves] = (row * 10 + column);
					numberOfValidMoves++;
				}
			}
		}
	}
}