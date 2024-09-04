#include <iostream>
#include <conio.h>

using namespace std;

char grid[4][4] =
{ {' ', ' ', ' ', ' '},
{' ', ' ', ' ', ' '},
{' ', ' ', ' ', ' '},
{' ', ' ', ' ', ' '} };

void display()
{
	cout << "0 + 1 + 2 + 3" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << grid[i][j] << " ";
			if (j < 3)
				cout << "| ";
		}
		cout << '\n';
		if (i < 3)
			cout << "--+---+---+--\n";
	}
}

bool boardfull()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (grid[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

bool check(char player)
{
	for (int i = 0; i < 4; i++)
	{
		if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player
			&& grid[i][3] == player)
			return true;
		else if (grid[0][i] == player && grid[1][i] == player
			&& grid[2][i] == player && grid[3][i] == player)
			return true;
	}
	if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player
		&& grid[3][3] == player)
		return true;
	if (grid[0][3] == player && grid[1][2] == player && grid[2][1] == player
		&& grid[3][0] == player)
		return true;
	return false;
}

char player;

int main()
{
	cout << "Welcome to XO Game, Please enter x or o \n";
	cin >> player;
	while (true)
	{
		system("cls");
		display();
		int row, coulmn;
		bool validInput = false;
		do {
			cout << "Please player " << player <<
				" Choose a position to a row and a coulmn (0:3)\n";
			cin >> row >> coulmn;
			if (row > 3 || row < 0 || coulmn > 3 || coulmn < 0
				|| grid[row][coulmn] != ' ')
			{
				cout << "An invalid play , please try again\n";
				if (cin.fail()) {
					cin.clear();
					cin.ignore(512, '\n');
				}
				continue;
			}
			else
				validInput = true;
		} while (!validInput);
		grid[row][coulmn] = player;
		if (check(player))
		{
			system("cls");
			display();
			cout << "Congratulation player " << player << " ,you win !!\n";
			cout << "Do you want to play again?! yes/no \n?! ";
			string repeat;
			cin >> repeat;
			if (repeat == "yes")
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						grid[i][j] = ' ';
				cout << "Welcome to XO Game, Please enter x or o \n";
				cin >> player;
				continue;
			}
			break;
		}
		if (boardfull())
		{
			system("cls");
			display();
			cout << "It's a draw , let us try again\n";
			cout << "Do you want to play again?! yes/no \n?! ";
			string repeat;
			cin >> repeat;
			if (repeat == "yes")
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						grid[i][j] = ' ';
				cout << "Welcome to XO Game, Please enter x or o \n";
				cin >> player;
				continue;
			}
			break;
		}
		player = (player == 'x') ? 'o' : 'x';
	}
	return 0;
}
