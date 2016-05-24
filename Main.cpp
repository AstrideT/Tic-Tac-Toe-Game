#include"Board.h"
#include<iostream>
using namespace std;

int main()
{
	Board ticToe;

	ticToe.BlankOut('-');
	cout << "This is a tic toe game with markers O and X" << endl;
	cout << "Two players X and Y can fill the 3*3 table below" << endl;
	ticToe.DrawConsole();
	cout << "The player who succeeds putting 3 successive characters" << endl
		<< "Horizonatlly, Vertically or Diagonally Wins"<<endl;
	cout<<"Let the game begin "<< endl << endl;
	
	
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
		ticToe.Player('O');
		ticToe.Winner('O');
		ticToe.DrawConsole();
		cout << endl;

		move++;
		gameOver = ticToe.HasWin('O');



	} while (!gameOver);
	if (ticToe.HasTie(move))
	{
		cout << "This is a tie" << endl;
	}
	return 0;
}

























































































































































































































