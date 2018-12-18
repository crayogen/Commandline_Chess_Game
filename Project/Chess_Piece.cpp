#include "pch.h"
#include "Chess_Piece.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"
#include "string"
#include <iostream>

using namespace std;

Chess_Piece::Chess_Piece(int teamNum, int pos) {
	this->teamNum = teamNum;
	position = pos;
}

Chess_Piece::~Chess_Piece() {}

bool Chess_Piece::isOutofBoard(int dest) {
	int row_dest = dest / 10; int col_dest = dest % 10;
	if (row_dest >= 8 || row_dest < 0 || col_dest >= 8 || col_dest < 0)
		return true;
	return false;
}

void Chess_Piece::setPosition(int position) {
	this->position = position;
}

int Chess_Piece::getPosition() {
	return position;
}

string Chess_Piece::getSymbol() {
	return symbol;
}

int Chess_Piece::getteamNum() {
	return teamNum;
}

bool Chess_Piece::isBlocked(int dest, Chess_Piece* board[8][8]) {
	int src = position;
	int row_src = src / 10; int col_src = src % 10;
	int row_dest = dest / 10; int col_dest = dest % 10;
	int stepSizeX = row_dest - row_src, stepSizeY = col_dest - col_src;

	//sets the step to be the sign of the stepSizes
	int stepDirectionX = (stepSizeX > 0) - (stepSizeX < 0); //if stepSizeX>0: 1, if <0: -1, if 0:0
	int stepDirectionY = (stepSizeY > 0) - (stepSizeY < 0);

	for (int stepSize = 1; ; stepSize++) {
		int rowIncriment = stepDirectionX * stepSize, columnIncriment = stepDirectionY * stepSize;
		if (rowIncriment && rowIncriment == stepSizeX) break;
		if (columnIncriment && columnIncriment == stepSizeY) break;
		Chess_Piece *peice = board[row_src + rowIncriment][col_src + columnIncriment];
		if (peice) return true; //idhar sahi karna
		
	}
	return false;
}

bool Chess_Piece::isValidMove(int dest, Chess_Piece* board[8][8])
{
	getValidMoves(board);
	int row_dest = dest / 10;
	int col_dest = dest % 10;

	for (int i = 0; i < numberOfValidMoves; i++) {
		if (dest == ValidMoves[i])
			return true;
	}

	return false;
}

int Chess_Piece::Check(Chess_Piece *board[8][8])
{
	for (int rowSrc = 0; rowSrc < 8; rowSrc++) {
		for (int colSrc = 0; colSrc < 8; colSrc++) {
			if (board[rowSrc][colSrc]) {
				int numberOfValidMoves = board[rowSrc][colSrc]->numberOfValidMoves;
				int *ValidMoves = board[rowSrc][colSrc]->ValidMoves;
				
				for (int move = 0; move < numberOfValidMoves; move++)
				{
					string symbolOfValidDest = " ";
					int playerAtSrc = board[rowSrc][colSrc]->getteamNum();
					int ValidDest = ValidMoves[move];
					int rowValidDest = ValidDest / 10;
					int colValidDest = ValidDest % 10;
					if (board[rowValidDest][colValidDest]==NULL)
						continue;
					symbolOfValidDest = board[rowValidDest][colValidDest]->getSymbol();
					
					if (board[rowSrc][colSrc]->isBlocked(ValidDest, board)) //if the peice i'm checking for was blocked after i calculated the valid moves
						continue;
					
					if (playerAtSrc == 2 && symbolOfValidDest == "K") { //player 1 is checked
						return ValidDest;
					}
					if (playerAtSrc == 1 && symbolOfValidDest == "k") { //player 2 is checked
						return ValidDest;
					}
				}
			}
		}
	}
	return -1;
}

bool Chess_Piece::Checkmate(Chess_Piece *board[8][8], int checkedKingPositon)
{
	int rowKingPosition = checkedKingPositon / 10;
	int colKingPosition = checkedKingPositon % 10;
	Chess_Piece *KingPeice =  board[rowKingPosition][colKingPosition];

	int numberOfValidMoves = KingPeice->numberOfValidMoves;
	int *ValidMoves = KingPeice->ValidMoves;

	for (int move = 0; move < numberOfValidMoves; move++) {
		int ValidDest = ValidMoves[move];
		int rowValidDest = ValidDest / 10;
		int colValidDest = ValidDest % 10;

		Chess_Piece *DestPeice = board[rowValidDest][colValidDest];
		DestPeice = new King(KingPeice->teamNum, ValidDest, board); // place a King here and see if it gives check
		if (!Check(board)) { // a place you can move to, that does not give a check
			DestPeice = NULL;
			return 0;
		}
		else
			DestPeice = NULL;
	}
	return 1;
}

int Chess_Piece::Move(int dest, Chess_Piece* board[8][8], int player) {
	int src = position;
	int row_src = src / 10; int col_src = src % 10;
	int row_dest = dest / 10; int col_dest = dest % 10;

	if (!isValidMove(dest, board)) return false;
	if (isBlocked(dest, board)) {
		cout << "0" << endl;
		return false;
	}

	//check to see ifit is blocked an then return false
	//contructors should be calling the getValidmoves

	if (board[row_src][col_src]) {
		if (player != teamNum) {
			cout << "The piece you selected is not your piece" << endl;
			return 0;//not your peice
		}

		if (isBlocked(dest, board)) {
			cout << "The piece is blocked." << endl;
			return 0;
		}
		if ((board[row_dest][col_dest] && board[row_dest][col_dest]->getteamNum() != teamNum)) { //knocking other peice out 
			board[row_dest][col_dest] = NULL;
			cout << "Opponent's piece knocked out!" << endl;
		}
	}
	
	setPosition(dest);
	board[row_dest][col_dest] = board[row_src][col_src];
	board[row_src][col_src] = NULL;

	// get the updated valid moves for this peice
	getValidMoves(board);

	int isCheck = Check(board); //contains kings dest if not -1, -1 represents that not checked

	if (isCheck != -1) {
		int rowKing = isCheck/10;
		int colKing = isCheck%10;
		int player = board[rowKing][colKing]->getteamNum() == 1 ? 1:2;
		if (Checkmate(board, isCheck)) {
			cout << "player " << player << " checkmate!" << endl;
			return -1; //game over
		}
		else cout << "player " << player << " check" << endl;
	}

	Chess_Piece *destPeice = board[row_dest][col_dest];
	string peiceSymbol = destPeice->getSymbol();

	if ( ((row_dest == 0) && (peiceSymbol == "p")) || ((row_dest == 7) && (peiceSymbol == "P")) )
	{
		bool change;
		string changedPeice;
		cout << "do you want to convert your pawn to another peice? 1 for yes, 0 for no." << endl;
		cin >> change;
		if (change) {
			int valid = 1;
			while(valid) {
				valid = 0;
				cout << "press k, p, b, n, q, r to convert to the chosen peice." << endl;
				cin >> changedPeice;
				int team;
				if (peiceSymbol == "p") team = 2;
				else if (peiceSymbol == "P") team = 1;
				else {
					cout << "inavlid input" << endl;
					valid = 1;
				}
				if (changedPeice == "k" || changedPeice == "K") destPeice = new King(team, dest, board);
				else if (changedPeice == "q" || changedPeice == "Q") destPeice = new Queen(team, dest, board);
				else if (changedPeice == "r" || changedPeice == "R") destPeice = new Rook(team, dest, board);
				else if (changedPeice == "b" || changedPeice == "B") destPeice = new Bishop(team, dest, board);
				else if (changedPeice == "p" || changedPeice == "P") destPeice = new Pawn(team, dest, board);
				else if (changedPeice == "n" || changedPeice == "N") destPeice = new Knight(team, dest, board);
				else {
					cout << "inavlid input" << endl;
					valid = 1;
				}
				board[row_dest][col_dest] = destPeice;
			}
		}
	}
	return 1;
}
