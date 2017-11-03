#include"Board.h"
#include<iostream>
using namespace std;

char promptUserInput();

int main()
{
	Board ticToe;

	ticToe.BlankOut('-');
	cout << "Welcome to the Tic-Tac-Toe-game" << endl;
	char player2OrComp=promptUserInput();//determines if user wants to play with someone else or computer 
	cout<<endl<<"First to put 3 characters horizontally, vertically or diagonally wins"<<endl;
	cout << "Tic-tac-toe table looks as such:"<<endl;
	ticToe.DrawConsole();//Outputs board to screen
	cout << "Rows are numbered from 1 to 3" << endl
		<< "Columns are numbered from 1 to 3" << endl<<endl;
	
	if (player2OrComp == 'O')
		cout << "\"Player X vs Player O\"" << endl << endl ;
	else
		cout << "\"Player X vs Computer\"" << endl << endl;
	
	int move = 0;//No letter has been placed here
	bool gameOver;
	
	do
	{

		ticToe.Player('X');//X plays

		move++;
		gameOver = ticToe.HasWin('X') || ticToe.HasTie(move);
		if (gameOver)
		{
			ticToe.Winner('X');//Checks if X has won and if yes, outputs it
			ticToe.DrawConsole();
			cout << endl;
			continue;
		}
		ticToe.DrawConsole();
		cout << endl;
		ticToe.Player(player2OrComp);//player 2 or computer plays
		ticToe.Winner(player2OrComp);//Checks if player 2 or computer has won and if yes, outputs it
		ticToe.DrawConsole();
		cout << endl;

		move++;
		gameOver = ticToe.HasWin(player2OrComp);



	} while (!gameOver);
	if (ticToe.HasTie(move)&& !ticToe.HasWin('X')&& !ticToe.HasWin(player2OrComp))//HasTie(move) means all 9 spots are filled
	{
		cout << "This is a tie" << endl;
	}
	return 0;
}


char promptUserInput() {
	char a;
	do {
		cout << "To play against someone, enter O or against computer, enter C: ";
		cin >> a;
		if (a == 'o' || a == '0')//User might see letter O as o, or 0, hence exploring those possibilities
			a = 'O';
		else if (a == 'c')
			a = 'C';
		if (cin.fail() || a != 'O' && a != 'C') {
			cout << "You neither entered O nor C" << endl<<endl;
			cin.clear();
			cin.ignore(100, '\n');//Handles the case where user enters non character types such as string	
		}
	} while (a != 'O' && a != 'C' || cin.fail());
	return a;

}
