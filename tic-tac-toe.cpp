#include <iostream>

using namespace std;

const int row = 3;
const int col = 3;

struct player 
{
	int move_1;
	int move_2;
	double turn = 1;
	string peice; 

};

double board[row][col];
double update_board(double board[row][col], player P);
int getmove_1(player P);
int getmove_2(player P);

void print_board(double board[row][col]);
void setmove_1(player &p);
void setmove_2(player &p);
void check_move(double board[row][col], player &p);
double condition_1(double board[row][col], player p);
double condition_2(double board[row][col], player p);
double condition_3(double board[row][col], player p);
double condition_4(double board[row][col], player p);
double check_winner(double board[row][col], player p);
double condition_tie(double board[row][col]);
void start_game();

int main()
{
	start_game();


}


void setmove_1(player &P)
{
	cout << "Enter the row" << endl;
	cin >> P.move_1;
	P.move_1--;
}

void setmove_2(player &P)
{
	cout << "Enter the colunm" << endl;
	cin >> P.move_2;
	P.move_2--;
}

int getmove_1(player P)
{
	return P.move_1;
}

int getmove_2(player P)
{
	return P.move_2;
}

double update_board(double board[row][col], player P)
{
	double ray;
	board[getmove_1(P)][getmove_2(P)] = {P.turn};
	ray = board[row][col];
	return ray;
}

void print_board(double board[row][col])
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (count < i)
			{
				count++;
				cout << endl;
			}
			if (board[i][j] == 1)
			{
				cout << "X";
			}
			if (board[i][j] == 2)
			{
				cout << "O";
			}
			if (board[i][j] == 0)
			{
				cout << "*";
			}
		}
	}
}

void check_move(double board[row][col], player &p)
{
	int pass = 0;
	while (pass == 0)
	{
		if (board[getmove_1(p)][getmove_2(p)] != 0)
		{
			cout << "That spot is taken try another" << endl;
			setmove_1(p);
			setmove_2(p);
		}
		if (board[getmove_1(p)][getmove_2(p)] == 0)
		{
			pass++;
		}

	}
}
void start_game()
{
	player one;
	player two;
	int A = check_winner(board, one);
	while (A == 0)
	{

		setmove_1(one);
		setmove_2(one);
		one.turn = 1;
		two.turn = 2;

		check_move(board, one);
		update_board(board, one);
		print_board(board);
		cout << endl;
		A= check_winner(board, one);

		if (A == 0)
		{

			setmove_1(two);
			setmove_2(two);

			check_move(board, two);
			update_board(board, two);
			print_board(board);
			cout << endl;
			A = check_winner(board, two);
			cout << endl;
		}
	}
	system("pause");

}


double condition_1(double board[row][col],player p)
{
	double win =0;
	for (int j = 0; j < col; j++)
	{
		int count = 0;
		for (int i = 0; i < row; i++)
		{
			if (board[i][j] == p.turn)
			{
				count++;
			}

		}
		if (count != 3)
		{
			count = 0;
		}



		if (count == 3)
		{
			cout << "WINNER: PLAYER " << p.turn << endl;
			win++;
		}
	}
	return win;
}


double condition_2(double board[row][col], player p)
{
	double win = 0;
	for (int j = 0; j < col; j++)
	{
		int count = 0;
		for (int i = 0; i < row; i++)
		{
			if (board[j][i] == p.turn)
			{
				count++;
			}

		}
		if (count != 3)
		{
			count = 0;
		}



		if (count == 3)
		{
			cout << "WINNER: PLAYER " << p.turn << endl;
			win++;
		}
	}
	return win;
}

double condition_3(double board[row][col],player p)
{
	double win = 0;
	int j = 0;
	int k = 0;
	if (board[j][k] == p.turn)
	{
		j++;
		k++;
		if (board[j][k] == p.turn)
		{
			j++;
			k++;
			if (board[j][k] == p.turn)
			{
				cout << "WINNER: PLAYER " << p.turn << endl;
				win++;
			}
		}
	}
	return win;



}

double condition_4(double board[row][col], player p)
{
	double win = 0;
	int j = 0;
	int k = 2;
	if (board[j][k] == p.turn)
	{
		j++;
		k--;
		if (board[j][k] == p.turn)
		{
			j++;
			k--;
			if (board[j][k] == p.turn)
			{
				cout << "WINNER: PLAYER " << p.turn << endl;
				win++;
			}
		}
	}
	return win;



}
double condition_tie(double board[row][col])
{
	double win = 0;
	int spots = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 0)
			{
				spots++;
			}
		}
	}

	if (spots == 0)
	{
		cout << "board is full, its a tie" << endl;
		win++;
	}
	return win;


}
double check_winner(double board[row][col], player p)
{
	double win =
		condition_1(board, p) +
		condition_2(board, p) +
		condition_3(board, p) +
		condition_4(board, p) +
		condition_tie(board);

	return win;
}

/*
Name: Antonio Ortega
Date: 9/20/19
Project : Tic-Tac-Toe
Enter the row
1
Enter the colunm
1
X**
***
***
Enter the row
1
Enter the colunm
3
X*O
***
***

Enter the row
2
Enter the colunm
2
X*O
*X*
***
Enter the row
3
Enter the colunm
3
X*O
*X*
**O

Enter the row
2
Enter the colunm
3
X*O
*XX
**O
Enter the row
2
Enter the colunm
1
X*O
OXX
**O

Enter the row
3
Enter the colunm
2
X*O
OXX
*XO
Enter the row
1
Enter the colunm
2
XOO
OXX
*XO

Enter the row
3
Enter the colunm
1
XOO
OXX
XXO
board is full, its a tie
Press any key to continue . . .
*/