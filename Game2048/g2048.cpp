#include "g2048.h"

G2048::G2048()
{
	vector<int> field1(SIZE, FIELD_EMPTY);
	for (size_t i = 0; i < SIZE; i++)
	{
		field.push_back(field1);
	}
}

enum colors
{
	BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, GREY,
	LIGHTGREY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
	LIGHTPURPLE, LIGHTYELLOW, WHITE
};

void G2048::setConsoleColor(int textColor, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void G2048::display()
{
	system("cls");
	for (int i = 0, c = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout<< "----";
		cout << endl;
		if (i == 4)
			break;
		for (int j = 0; j < 5; j++, c++)
		{
			cout << "|";
			if (j == 4)
				break;
			if (field[i][j] == 0)
				cout << setw(4) << " ";
			else if (field[i][j] == 2)
			{
				setConsoleColor(LIGHTGREEN, BLUE);
				cout << setw(4) << field[i][j];
				setConsoleColor(GREY, BLACK);
			}
			else
			{
				setConsoleColor(LIGHTGREEN, YELLOW);
				cout << setw(4) << field[i][j];
				setConsoleColor(GREY, BLACK);
			}

		}
		cout << endl;
	}

}

void G2048::moverandomall()
{
	srand(time(NULL));
	while (true)
	{
		int x = rand() % SIZE;
		int y = rand() % SIZE;
		if (field[x][y] == FIELD_EMPTY)
		{
			int random = rand() % 3;
			if (random == 0)
			{
				field[x][y] = RAND2;
			}
			else
			{
				field[x][y] = RAND1;
			}
			return;
		}
	}
}

void G2048::move()
{
	_getch();
	int sumvol = _getch();
	switch (sumvol)
	{
	case 75:
	{
		moveLeft();
		break;
	}
	case 77:
	{
		moveRight();
		break;
	}
	case 72:
	{
		moveUp();
		break;
	}
	case 80:
	{
		moveDown();
		break;
	}
	default:
		break;
	}
}

void G2048::moveLeft()
{
	moveLeft1();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (field[i][j] == field[i][j + 1])
			{
				field[i][j] *= 2;
				field[i][j + 1] = FIELD_EMPTY;
			}
		}
	}
	moveLeft1();
}

void G2048::moveLeft1()
{
	for (int k = 0; k < SIZE - 1; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = SIZE - 1; j > 0; j--)
			{
				if (field[i][j - 1] == FIELD_EMPTY)
				{
					field[i][j - 1] = field[i][j];
					field[i][j] = FIELD_EMPTY;
				}
			}
		}
	}
}

void G2048::moveRight()
{
	moveRight1();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = SIZE - 1; j > 0; j--)
		{
			if (field[i][j] == field[i][j - 1])
			{
				field[i][j] *= 2;
				field[i][j - 1] = FIELD_EMPTY;
			}
		}
	}
	moveRight1();
}

void G2048::moveRight1()
{
	for (int k = 0; k < SIZE - 1; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE - 1; j++)
			{
				if (field[i][j + 1] == FIELD_EMPTY)
				{
					field[i][j + 1] = field[i][j];
					field[i][j] = FIELD_EMPTY;
				}
			}
		}
	}
}

void G2048::moveUp()
{
	moveUp1();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j <SIZE-1; j++)
		{
			if (field[j][i] == field[j+1][i])
			{
				field[j][i] *= 2;
				field[j+1][i] = FIELD_EMPTY;
			}
		}
	}
	moveUp1();
}

void G2048::moveUp1()
{
	for (int k = 0; k < SIZE - 1; k++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = SIZE - 1; j > 0; j--)
			{
				if (field[j - 1][i] == FIELD_EMPTY)
				{
					field[j - 1][i] = field[j][i];
					field[j][i] = FIELD_EMPTY;
				}
			}
		}
	}
}

void G2048::moveDown()
{
	moveDown1();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (field[j][i] == field[j + 1][i])
			{
				field[j][i] *= 2;
				field[j + 1][i] = FIELD_EMPTY;
			}
		}
	}
	moveDown1();
}

void G2048::moveDown1()
{
	for (int k = 0; k < SIZE - 1; k++)
	{
		for (int i = SIZE - 1; i > -1; i--)
		{
			for (int j = 0; j < SIZE - 1; j++)
			{
				if (field[j + 1][i] == FIELD_EMPTY)
				{
					field[j + 1][i] = field[j][i];
					field[j][i] = FIELD_EMPTY;
				}
			}
		}
	}
}

void G2048::play()
{
	moverandomall();
	moverandomall();
	do
	{
		display();
		move();
		moverandomall();
	} while (lose() != true);
}

bool G2048::lose()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (field[i][j] == FIELD_EMPTY)
			{
				return false;
			}

		}
	}
	return true;
}
