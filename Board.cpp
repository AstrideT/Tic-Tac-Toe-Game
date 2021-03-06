#include<iostream>
#include "Board.h"
#include <ctime>
#include<cstdlib>


using namespace std;

void Board::BlankOut(char a)
{
	for (X = 0; X < ROW_MAX; X++)
		for (Y = 0; Y < COL_MAX; Y++)
			board[X][Y] = a;
	cout << endl;
}


void Board::Winner(char a)
{
	if (HasWin(a) == true)
		cout << "Winner is Player " << a << endl;
}

void Board::DrawConsole()
{
	for (X = 0; X < ROW_MAX; X++)
	{
		{
			for (Y = 0; Y < COL_MAX; Y++)
				cout << board[X][Y];
		}
		cout << endl;
	}
}
bool Board::OutOfBound()
{
	return (X < 1 || X>3 || Y < 1 || Y>3);

}
void  Board::PromptRowInput(char a) {
	if (a == 'O'||a=='X')
	{
		cout << "Player " << a << " enter the row number where you want to put your " << a << " : ";
		cin >> X;
	}
	if (a == 'C')
	{
		
		srand(time(0));
		X = rand() % 3 + 1;
		while (HasAlreadyBeenInput()) {
			X = rand() % 3 + 1;
		}
		cout << "Computer plays row: "<< X<<endl;
	}

	
	while (OutOfBound() || cin.fail()) {
		if (cin.fail())
		{
			cout << "Row number must be an integer" << endl << endl;;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Player " << a << " write the row where you want to put your " << a << " : ";
			cin >> X;
		}

		else if (OutOfBound())
		{
			cout << "Number must be between 1 and 3" << endl << endl;
			cout << "Player " << a << " write the row where you want to put your " << a << " : ";
			cin >> X;

		}

	}
}
void  Board::PromptColumnInput(char a) {
	
	
	if (a == 'O'||a=='X')
	{
		cout << "Player " << a << " enter the column number where you want to put your " << a << " : ";
		cin >> Y;
	}
	if (a == 'C')
	{
	
		srand(time(0));
		Y = rand() % 3 + 1;
		while (HasAlreadyBeenInput()) {
			Y = rand() % 3 + 1;
		}
		cout << "Computer plays column: " << Y<<endl;
	}
	while (OutOfBound()||cin.fail())
	{
		if (cin.fail())
		{
			cout << "Column number must be an integer" << endl << endl;;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Player " << a << " write the column where you want to put your " << a << " : ";
			cin >> Y;
		}
		
		else if (OutOfBound())
		{
			cout << "Number must be between 1 and 3" << endl << endl;
			cout << "Player " << a << " write the column where you want to put your " << a << " : ";
			cin >> Y;

		}
		
	}
}

void Board::Player(char a)
{
	
		PromptRowInput(a);
		PromptColumnInput(a);
		while (HasAlreadyBeenInput())
		{
			cout << "That spot is already occupied. Play again " << endl << endl;

			PromptRowInput(a);
			PromptColumnInput(a);
		}
		board[X - 1][Y - 1] = a;
		cout << endl;
	
}
bool Board::HasWin(char a)
{//Wins if all 3 letters are in the:
	if (board[0][0] == a && board[0][1] == a &&board[0][2] == a ||//1st row
		board[1][0] == a && board[1][1] == a &&board[1][2] == a ||//2nd row
		board[2][0] == a && board[2][1] == a &&board[2][2] == a ||//3rd row
		board[0][0] == a &&board[1][0] == a &&board[2][0] == a ||//1st column
		board[0][1] == a && board[1][1] == a &&board[2][1] == a ||//2nd column
		board[0][2] == a &&board[1][2] == a && board[2][2] == a ||//3rd column
		board[0][0] == a &&board[1][1] == a &&board[2][2] == a ||//diagonal with negative slope
		board[2][0] == a &&board[1][1] == a &&board[0][2] == a //diagonal with positive slope
		)
		return true;
	else
		return false;
}

bool Board::HasTie(int trial)
{
	if (trial == 9)
		return true;

	else
		return false;
}

bool Board::HasAlreadyBeenInput()
{
	return board[X - 1][Y - 1] != '-';

}

