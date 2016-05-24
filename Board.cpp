#include<iostream>
#include "Board.h"

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

	cout << "Player " << a << " write the row where you want to put your " << a << " : ";
	cin >> X;
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

	cout << "Player " << a << " write the column where you want to put your " << a << " : ";
	cin >> Y;
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
		DrawConsole();
	cout << "The case is already occupied. Play again " << endl << endl;
		
		PromptRowInput(a);
		PromptColumnInput(a);
	}
	board[X - 1][Y - 1] = a;
	cout << endl;
}
bool Board::HasWin(char a)
{
	if (board[0][0] == a && board[0][1] == a &&board[0][2] == a ||
		board[0][0] == a &&board[1][0] == a &&board[2][0] == a ||
		board[0][0] == a &&board[1][1] == a &&board[2][2] == a ||
		board[2][0] == a &&board[1][1] == a &&board[0][2] == a ||
		board[0][2] == a &&board[1][2] == a && board[2][2] == a ||
		board[0][1] == a && board[1][1] == a &&board[2][1] == a ||
		board[1][0] == a && board[1][1] == a &&board[1][2] == a ||
		board[3][1] == a&&board[3][2] == a&&board[3][3] == a ||
		board[0][1] == a &&board[1][1] == a&&board[2][1] == a)
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

