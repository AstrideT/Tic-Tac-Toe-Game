#include"Board.h"
#include<iostream>
using namespace std;

char promptUserInput();

int main()
{
	Board ticToe;

	ticToe.BlankOut('-');
	cout << "Welcome to the Tic-Tac-Toe-game" << endl;
	char a=promptUserInput();
	while (a != 'O' && a != 'C') {
		cout << "You neither entered O nor C" << endl << endl;
		a = promptUserInput();
	}
	cout<<endl<<"First to put 3 characters horizontally, vertically or diagonally wins"<<endl;
	cout << "Tic-tac-toe table looks as such:"<<endl;
	ticToe.DrawConsole();
	cout << "Rows are numbered from 1 to 3" << endl
		<< "Columns are numbered from 1 to 3" << endl<<endl;
	
	if (a == 'O')
		cout << "\"Player X vs Player O\"" << endl << endl ;
	else if (a == 'C')
		cout << "\"Player X vs Computer\"" << endl << endl;
	else
		cout << "You neither entered O nor C.";
	int move = 0;
	bool gameOver;
	
	do
	{

		ticToe.Player('X');

		move++;
		gameOver = ticToe.HasWin('X') || ticToe.HasTie(move);
		if (gameOver)
		{
			ticToe.Winner('X');
			ticToe.DrawConsole();
			continue;
		}
		ticToe.DrawConsole();
		ticToe.Player(a);
		ticToe.Winner(a);
		ticToe.DrawConsole();
		cout << endl;

		move++;
		gameOver = ticToe.HasWin(a);



	} while (!gameOver);
	if (ticToe.HasTie(move))
	{
		cout << "This is a tie" << endl;
	}
	return 0;
}


char promptUserInput() {
	cout<< "To play against someone, enter O or against computer, enter C: ";
	char a;
	cin >> a;
	if (a == 'o' || a == '0')//User might see letter O as o, or 0, hence exploring those possibilities
	    a = 'O';
	else if (a == 'c')
		a = 'C';
	return a;

}
