#include "pch.h"
#include <iostream>
#include "Game.h"
#include "string"

using namespace std;

Game::Game()
{
	Player = 1;
	for (int row = 0; row < 2; row++) {
		for (int column = 0; column < 4; column++) {
			for (int partitionX = 0; partitionX < 2; partitionX++) {
				for (int partitionY = 0; partitionY < 2; partitionY++) {
					int absoluteRow = partitionX == 0 ? row : 7 - row;
					int absoluteColumn = partitionY == 0 ? column : 7 - column;
					int position = absoluteColumn + (10 * absoluteRow);
					int teamNum = !partitionX ? 1 : 2;
					if (row == 0)
					{
						Chess_Piece* peice = NULL;
						switch (column)
						{
						case 0: peice = new Rook(teamNum, position, board); break;
						case 1: peice = new Knight(teamNum, position, board); break;
						case 2: peice = new Bishop(teamNum, position, board); break;
						}
						board[absoluteRow][absoluteColumn] = peice;
					}
					if (row == 1)
					{
						board[absoluteRow][absoluteColumn] = new Pawn(teamNum, position, board);
					}
					if (row == 0 && column == 3)
					{
						if (!partitionY)
							board[absoluteRow][absoluteColumn] = new Queen(teamNum, position, board);
						if (partitionY)
							board[absoluteRow][absoluteColumn] = new King(teamNum, position, board);
					}
				}
			}
		}
	}
}

void Game::DisplayBoard()
{
	char columnLabels[8]; char columnLabel = 'A';
	int rowLabels[8]; int RowLabel = 1;

	for (int i = 0; i < 8; i++) {
		columnLabels[i] = columnLabel;
		rowLabels[i] = RowLabel;
		RowLabel++;
		columnLabel++;
	}

	cout << "*****************" << endl
		 << "******CHESS******" << endl
		 << "*****************" << endl << endl;
	
	cout << "# represents white box" << endl
		 << "  represents black box" << endl;
	cout << "Upper case pieces represent team 1" << endl 
		 << "Lower case pieces represent team 2" << endl << endl;

	for (int i = 0; i < 8; i++)
		cout << columnLabels[i] << " ";
	cout << endl;
	cout << "---------------" << endl;
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 9; col++) {
			if (col == 8) cout << "|" << rowLabels[row];
			else if (board[row][col]) cout << board[row][col]->getSymbol() << " ";
			else if ((row + col) % 2 == 0) cout << "#" << " ";
			else cout << " " << " ";
		}
		cout << endl;
	}
}


int Game::ConvertInput(string input) //assuming correct input
{
	char a= input[0];
	char b = input[1];
	while (input.length()!=2 || isalpha(input[0]) == 0 || isdigit(input[1]) == 0 ) {
		cout << "Incorrect input. Enter again." << endl;
		cin >> input;
		a = input[0];
		b = input[1];
	}

	string output = "";
	for (int i = 0; i < input.length(); i++) //lowercasing
		output += tolower(input[i]);
	char first = output[0]; char second = output[1];
	int x2 = (int)first - 97; //ascii of character - 97
	int x1 = (int)second - 49; //ascii - 48 - 1 for indexing 
	int x = (x1 * 10) + x2;
	return x;
}

void Game::play()
{
	string inputSrc, inputDest;
	int src, dest;
	DisplayBoard();
	cout << endl << "player " << Player << "'s turn:" << endl;
	cout << "Enter initial position (column row): ";
	cin >> inputSrc;
	src = ConvertInput(inputSrc);

	cout << endl << "Enter final position (column row): ";
	cin >> inputDest;
	dest = ConvertInput(inputDest);

	int row_src = src / 10; int col_src = src % 10;

	if (board[row_src][col_src]) {
		int move = (board[row_src][col_src]->Move(dest, board, Player));
		while (!move) {
			if (move == -1) {
				DisplayBoard();
				return;
			}
			cout << "Invalid! Try again." << endl;
			cout << "Enter initial position again." << endl;
			cin >> inputSrc;
			src = ConvertInput(inputSrc);
			int row_src = src / 10; int col_src = src % 10;

			cout << "Enter final position again." << endl;
			cin >> inputDest;

			dest = ConvertInput(inputDest);
			if (board[row_src][col_src])
				move = board[row_src][col_src]->Move(dest, board, Player);
			else {
				cout << "your source appears to be empty" << endl;
				move = 0;
			}
		}
		cout << "Moved selected piece from " << inputSrc << " to " << inputDest << endl;
		Player = (Player == 1) ? 2 : 1;
	}
	else cout << "your source appears to be empty" << endl;
	play();
}

Game::~Game()
{
}


