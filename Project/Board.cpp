#include "pch.h"
#include "Board.h"
#include "string"
using namespace std;

Board::Board(): White_King(1, 03), Black_King(2, 73), White_Queen(1, 04), Black_Queen (2, 74), White_Pawn_1(1, 10), White_Pawn_2(1, 11), White_Pawn_3(1, 12), White_Pawn_4(1, 13), White_Pawn_5(1, 14), White_Pawn_6(1, 15), White_Pawn_7(1, 16), White_Pawn_8(1, 17), Black_Pawn_1(2, 60), Black_Pawn_2(2, 61), Black_Pawn_3(2, 62), Black_Pawn_4(2, 63), Black_Pawn_5(2, 64), Black_Pawn_6(2, 65), Black_Pawn_7(2, 66), Black_Pawn_8(2, 67), White_Rook_1(1, 00), White_Rook_2 (1, 07), Black_Rook_1(2, 70), Black_Rook_2 (2, 77), White_Knight_1(1, 01), White_Knight_2 (1, 06), Black_Knight_1 (2, 71), Black_Knight_2 (2, 76), White_Bishop_1 (1, 02), White_Bishop_2 (1, 05), Black_Bishop_1 (2, 72), Black_Bishop_2(2, 75)
{
	/*b =   {{"||||", "|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |"},
		   {"|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |", "||||"},
		   {"||||", "|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |"},
		   {"|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |", "||||"},
		   {"||||", "|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |"},
		   {"|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |", "||||"},
		   {"||||", "|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |"},
		   {"|  |", "||||", "|  |", "||||", "|  |", "||||", "|  |", "||||"}};*/

}


Board::~Board()
{
}

void Board::Display() //iss mai side par coordinates daalne
{
	//cout<<""

}
void Board::set_board(int a, int b)
{


}//a is initial position of piece and b is final- checks isske andar hi ya bahir?