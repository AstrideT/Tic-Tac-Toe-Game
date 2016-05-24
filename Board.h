#pragma once
const  int ROW_MAX = 3;
const int COL_MAX = 3;

class Board {
public:

	void BlankOut(char m);

	void Player(char a);
	void PromptInput(char a);
	void Winner(char a);
	void DrawConsole();
	bool HasWin(char a);
	bool HasTie(int trial);
	bool HasAlreadyBeenInput();
	bool OutOfBound();

	void PromptRowInput(char a);

	void PromptColumnInput(char a);

	
private:

	char board[ROW_MAX][COL_MAX];                  //Array of characters
	int X, Y;                                     //Coordinates


};