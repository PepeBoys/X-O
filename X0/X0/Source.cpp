#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <tuple>

std::tuple<int, int> get_chose(char chose, int y, int x)
{
	if (chose == 'w')
	{
		y++;
	}
	else if (chose == 's')
	{
		y--;
	}
	else if (chose == 'a')
	{
		x--;
	}
	else if (chose == 'd')
	{
		x++;
	}

	return std::make_tuple(y, x);
}

using namespace std;

void print_array(string* first)
{
	int i = 0;
	while (i < 3)
	{
		std::cout << first[i];
		i++;
	}
	std::cout << endl;
}

void field(string* first,string* second, string* third)
{
	print_array(first);
	print_array(second);
	print_array(third);
}

char check_win_X(string* first, string* second, string* third)
{
	if (first[0] == "X " and first[1] == "X " and first[2] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else if (second[0] == "X " and second[1] == "X " and second[2] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else if (third[0] == "X " and third[1] == "X " and third[2] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else if (first[0] == "X " and second[1] == "X " and third[2] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else if (third[0] == "X " and second[1] == "X " and first[2] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else if (third[0] == "X " and second[0] == "X " and first[0] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else if (third[1] == "X " and second[1] == "X " and first[1] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else if (third[2] == "X " and second[2] == "X " and first[2] == "X ")
	{
		std::cout << "|X| WIN" << endl;
		system("pause");
		return 'X';
	}
	else
	{
		return 'q';
	}
}

char check_win_O(string* first, string* second, string* third)
{
	if (first[0] == "O " and first[1] == "O " and first[2] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else if (second[0] == "O " and second[1] == "O " and second[2] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else if (third[0] == "O " and third[1] == "O " and third[2] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else if (first[0] == "O " and second[1] == "O " and third[2] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else if (third[0] == "O " and second[1] == "O " and first[2] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else if (third[2] == "O " and second[2] == "O " and first[2] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else if (third[1] == "O " and second[1] == "O " and first[1] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else if (third[0] == "O " and second[0] == "O " and first[0] == "O ")
	{
		std::cout << "|O| WIN" << endl;
		system("pause");
		return 'O';
	}
	else
	{
		return 'q';
	}
}

char check_draw(string* first, string* second, string* third, char win)
{
	if (first[0] != ". " and first[1] != ". " and first[2] != ". " and second[0] != ". " and second[1] != ". " and second[2] != ". " and third[0] != ". " and third[1] != ". " and third[2] != ". ")
	{
	    std:cout << "DRAW" << endl; system("pause"); return 'd';
	}
	else
	{
		return win;
	}
}


int main()
{

	for (;;)
	{
		system("cls");

		// Ебучее меню
		std::cout << ">>1.XO   V2.0 With NEW GUI WOW!!!" << endl << "  2.Exit";

		int ch = 1;

		for (char menu = 'q' ;ch > -1;)
		{
			menu = _getch();
			system("cls");
			if (menu == 'w')
			{
				ch = 1;
				std::cout << ">>1.XO   V2.0 With NEW GUI WOW!!!" << endl << "  2.Exit";
			}
			else if (menu == 's')
			{
				ch = 2;
				std::cout << "  1.XO   V2.0 With NEW GUI WOW!!!" << endl << ">>2.Exit";
			}
			else if (menu == 'd')
			{
				if (ch == 1)
				{
					ch = -1;
				}
				else if (ch == 2)
				{
					return 0;
				}
			}
		}

		std::cout << ". " << ". " << ". " << endl;
		std::cout << ". " << "X " << ". " << endl;
		std::cout << ". " << ". " << ". " << endl;

		char chose = 'q', win = 'q';
		string remember;
		int x = 0, y = 0, exit = 0;
		string first[3]
		{
			". ",". ",". "
		};
		string second[3]
		{
			". ",". ",". "
		};
		string third[3]
		{
			". ",". ",". "
		};

		for (;win == 'q';)
		{

			//Ход X

			for (;exit == 0;)
			{
				chose = _getch();
				tie(y, x) = get_chose(chose, y, x);

				if (x <= -1 and y >= 1 and first[0] != "O " and chose != 'f')
				{
					system("cls");
					remember = first[0];
					first[0] = "X ";
					field(first, second, third);
					first[0] = remember;
					x = -1;
					y = 1;
				}
				else if (x == 0 and y >= 1 and first[1] != "O " and chose != 'f')
				{
					system("cls");
					remember = first[1];
					first[1] = "X ";
					field(first, second, third);
					first[1] = remember;
					y = 1;
				}
				else if (x >= 1 and y >= 1 and first[2] != "O " and chose != 'f')
				{
					system("cls");
					remember = first[2];
					first[2] = "X ";
					field(first, second, third);
					first[2] = remember;
					y = 1;
					x = 1;
				}
				else if (x <= -1 and y == 0 and second[0] != "O " and chose != 'f')
				{
					system("cls");
					remember = second[0];
					second[0] = "X ";
					field(first, second, third);
					second[0] = remember;
					x = -1;
				}
				else if (x == 0 and y == 0 and second[1] != "O " and chose != 'f')
				{
					system("cls");
					remember = second[1];
					second[1] = "X ";
					field(first, second, third);
					second[1] = remember;

				}
				else if (x >= 1 and y == 0 and second[2] != "O " and chose != 'f')
				{
					system("cls");
					remember = second[2];
					second[2] = "X ";
					field(first, second, third);
					second[2] = remember;
					x = 1;
				}
				else if (x <= -1 and y <= -1 and third[0] != "O " and chose != 'f')
				{
					system("cls");
					remember = third[0];
					third[0] = "X ";
					field(first, second, third);
					third[0] = remember;
					x = -1;
					y = -1;
				}
				else if (x == 0 and y <= -1 and third[1] != "O " and chose != 'f')
				{
					system("cls");
					remember = third[1];
					third[1] = "X ";
					field(first, second, third);
					third[1] = remember;
					y = -1;
				}
				else if (x >= 1 and y <= -1 and third[2] != "O " and chose != 'f')
				{
					system("cls");
					remember = third[2];
					third[2] = "X ";
					field(first, second, third);
					third[2] = remember;
					x = 1;
					y = -1;
				}



				if (x <= -1 and y >= 1 and first[0] == "O ")
				{
					system("cls");
					remember = first[0];
					first[0] = "Z ";
					field(first, second, third);
					first[0] = remember;
					x = -1;
					y = 1;
				}
				else if (x == 0 and y >= 1 and first[1] == "O ")
				{
					system("cls");
					remember = first[1];
					first[1] = "Z ";
					field(first, second, third);
					first[1] = remember;
					y = 1;
				}
				else if (x >= 1 and y >= 1 and first[2] == "O ")
				{
					system("cls");
					remember = first[2];
					first[2] = "Z ";
					field(first, second, third);
					first[2] = remember;
					y = 1;
					x = 1;
				}
				else if (x <= -1 and y == 0 and second[0] == "O ")
				{
					system("cls");
					remember = second[0];
					second[0] = "Z ";
					field(first, second, third);
					second[0] = remember;
					x = -1;
				}
				else if (x == 0 and y == 0 and second[1] == "O ")
				{
					system("cls");
					remember = second[1];
					second[1] = "Z ";
					field(first, second, third);

				}
				else if (x >= 1 and y == 0 and second[2] == "O ")
				{
					system("cls");
					remember = second[2];
					second[2] = "Z ";
					field(first, second, third);
					second[2] = remember;
					x = 1;
				}
				else if (x <= -1 and y <= -1 and third[0] == "O ")
				{
					system("cls");
					remember = third[0];
					third[0] = "Z ";
					field(first, second, third);
					third[0] = remember;
					x = -1;
					y = -1;
				}
				else if (x == 0 and y <= -1 and third[1] == "O ")
				{
					system("cls");
					remember = third[1];
					third[1] = "Z ";
					field(first, second, third);
					third[1] = remember;
					y = -1;
				}
				else if (x >= 1 and y <= -1 and third[2] == "O ")
				{
					system("cls");
					remember = third[2];
					third[2] = "Z ";
					field(first, second, third);
					third[2] = remember;
					x = 1;
					y = -1;
				}


				if (x <= -1 and y >= 1 and first[0] == "X ")
				{
					system("cls");
					remember = first[0];
					first[0] = "Z ";
					field(first, second, third);
					first[0] = remember;
					x = -1;
					y = 1;
				}
				else if (x == 0 and y >= 1 and first[1] == "X ")
				{
					system("cls");
					remember = first[1];
					first[1] = "Z ";
					field(first, second, third);
					first[1] = remember;
					y = 1;
				}
				else if (x >= 1 and y >= 1 and first[2] == "X ")
				{
					system("cls");
					remember = first[2];
					first[2] = "Z ";
					field(first, second, third);
					first[2] = remember;
					y = 1;
					x = 1;
				}
				else if (x <= -1 and y == 0 and second[0] == "X ")
				{
					system("cls");
					remember = second[0];
					second[0] = "Z ";
					field(first, second, third);
					second[0] = remember;
					x = -1;
				}
				else if (x == 0 and y == 0 and second[1] == "X ")
				{
					system("cls");
					remember = second[1];
					second[1] = "Z ";
					field(first, second, third);
					second[1] = remember;

				}
				else if (x >= 1 and y == 0 and second[2] == "X ")
				{
					system("cls");
					remember = second[2];
					second[2] = "Z ";
					field(first, second, third);
					second[2] = remember;
					x = 1;
				}
				else if (x <= -1 and y <= -1 and third[0] == "X ")
				{
					system("cls");
					remember = third[0];
					third[0] = "Z ";
					field(first, second, third);
					third[0] = remember;
					x = -1;
					y = -1;
				}
				else if (x == 0 and y <= -1 and third[1] == "X ")
				{
					system("cls");
					remember = third[1];
					third[1] = "Z ";
					field(first, second, third);
					third[1] = remember;
					y = -1;
				}
				else if (x >= 1 and y <= -1 and third[2] == "X ")
				{
					system("cls");
					remember = third[2];
					third[2] = "Z ";
					field(first, second, third);
					third[2] = remember;
					x = 1;
					y = -1;
				}



				if (x == -1 and y == 1 and first[0] != "O " and chose == 'f' and first[0] != "X ")
				{
					system("cls");
					first[0] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == 0 and y == 1 and first[1] != "O " and chose == 'f' and first[1] != "X ")
				{
					system("cls");
					first[1] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == 1 and y == 1 and first[2] != "O " and chose == 'f' and first[2] != "X ")
				{
					system("cls");
					first[2] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == -1 and y == 0 and second[0] != "O " and chose == 'f' and second[0] != "X ")
				{
					system("cls");
					second[0] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == 0 and y == 0 and second[1] != "O " and chose == 'f' and second[1] != "X ")
				{
					system("cls");
					second[1] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == 1 and y == 0 and second[2] != "O " and chose == 'f' and second[2] != "X ")
				{
					system("cls");
					second[2] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == -1 and y == -1 and third[0] != "O " and chose == 'f' and third[0] != "X ")
				{
					system("cls");
					third[0] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == 0 and y == -1 and third[1] != "O " and chose == 'f' and third[1] != "X ")
				{
					system("cls");
					third[1] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}
				else if (x == 1 and y == -1 and third[2] != "O " and chose == 'f' and third[2] != "X ")
				{
					system("cls");
					third[2] = "X ";
					field(first, second, third);
					exit = 1;
					win = check_win_X(first, second, third);
					win = check_draw(first, second, third, win);
				}

			}

			exit = 0;


			//Ход О

			for (;exit == 0;)
			{

				if (win == 'q')
				{

					chose = _getch();
					tie(y, x) = get_chose(chose, y, x);

					if (x <= -1 and y >= 1 and first[0] != "X " and chose != 'f')
					{
						system("cls");
						remember = first[0];
						first[0] = "O ";
						field(first, second, third);
						first[0] = remember;
						x = -1;
						y = 1;
					}
					else if (x == 0 and y >= 1 and first[1] != "X " and chose != 'f')
					{
						system("cls");
						remember = first[1];
						first[1] = "O ";
						field(first, second, third);
						first[1] = remember;
						y = 1;
					}
					else if (x >= 1 and y >= 1 and first[2] != "X " and chose != 'f')
					{
						system("cls");
						remember = first[2];
						first[2] = "O ";
						field(first, second, third);
						first[2] = remember;
						y = 1;
						x = 1;
					}
					else if (x <= -1 and y == 0 and second[0] != "X " and chose != 'f')
					{
						system("cls");
						remember = second[0];
						second[0] = "O ";
						field(first, second, third);
						second[0] = remember;
						x = -1;
					}
					else if (x == 0 and y == 0 and second[1] != "X " and chose != 'f')
					{
						system("cls");
						remember = second[1];
						second[1] = "O ";
						field(first, second, third);
						second[1] = remember;

					}
					else if (x >= 1 and y == 0 and second[2] != "X " and chose != 'f')
					{
						system("cls");
						remember = second[2];
						second[2] = "O ";
						field(first, second, third);
						second[2] = remember;
						x = 1;
					}
					else if (x <= -1 and y <= -1 and third[0] != "X " and chose != 'f')
					{
						system("cls");
						remember = third[0];
						third[0] = "O ";
						field(first, second, third);
						third[0] = remember;
						x = -1;
						y = -1;
					}
					else if (x == 0 and y <= -1 and third[1] != "X " and chose != 'f')
					{
						system("cls");
						remember = third[1];
						third[1] = "O ";
						field(first, second, third);
						third[1] = remember;
						y = -1;
					}
					else if (x >= 1 and y <= -1 and third[2] != "X " and chose != 'f')
					{
						system("cls");
						remember = third[2];
						third[2] = "O ";
						field(first, second, third);
						third[2] = remember;
						x = 1;
						y = -1;
					}



					if (x <= -1 and y >= 1 and first[0] == "O ")
					{
						system("cls");
						remember = first[0];
						first[0] = "Z ";
						field(first, second, third);
						first[0] = remember;
						x = -1;
						y = 1;
					}
					else if (x == 0 and y >= 1 and first[1] == "O ")
					{
						system("cls");
						remember = first[1];
						first[1] = "Z ";
						field(first, second, third);
						first[1] = remember;
						y = 1;
					}
					else if (x >= 1 and y >= 1 and first[2] == "O ")
					{
						system("cls");
						remember = first[2];
						first[2] = "Z ";
						field(first, second, third);
						first[2] = remember;
						y = 1;
						x = 1;
					}
					else if (x <= -1 and y == 0 and second[0] == "O ")
					{
						system("cls");
						remember = second[0];
						second[0] = "Z ";
						field(first, second, third);
						second[0] = remember;
						x = -1;
					}
					else if (x == 0 and y == 0 and second[1] == "O ")
					{
						system("cls");
						remember = second[1];
						second[1] = "Z ";
						field(first, second, third);

					}
					else if (x >= 1 and y == 0 and second[2] == "O ")
					{
						system("cls");
						remember = second[2];
						second[2] = "Z ";
						field(first, second, third);
						second[2] = remember;
						x = 1;
					}
					else if (x <= -1 and y <= -1 and third[0] == "O ")
					{
						system("cls");
						remember = third[0];
						third[0] = "Z ";
						field(first, second, third);
						third[0] = remember;
						x = -1;
						y = -1;
					}
					else if (x == 0 and y <= -1 and third[1] == "O ")
					{
						system("cls");
						remember = third[1];
						third[1] = "Z ";
						field(first, second, third);
						third[1] = remember;
						y = -1;
					}
					else if (x >= 1 and y <= -1 and third[2] == "O ")
					{
						system("cls");
						remember = third[2];
						third[2] = "Z ";
						field(first, second, third);
						third[2] = remember;
						x = 1;
						y = -1;
					}


					if (x <= -1 and y >= 1 and first[0] == "X ")
					{
						system("cls");
						remember = first[0];
						first[0] = "Z ";
						field(first, second, third);
						first[0] = remember;
						x = -1;
						y = 1;
					}
					else if (x == 0 and y >= 1 and first[1] == "X ")
					{
						system("cls");
						remember = first[1];
						first[1] = "Z ";
						field(first, second, third);
						first[1] = remember;
						y = 1;
					}
					else if (x >= 1 and y >= 1 and first[2] == "X ")
					{
						system("cls");
						remember = first[2];
						first[2] = "Z ";
						field(first, second, third);
						first[2] = remember;
						y = 1;
						x = 1;
					}
					else if (x <= -1 and y == 0 and second[0] == "X ")
					{
						system("cls");
						remember = second[0];
						second[0] = "Z ";
						field(first, second, third);
						second[0] = remember;
						x = -1;
					}
					else if (x == 0 and y == 0 and second[1] == "X ")
					{
						system("cls");
						remember = second[1];
						second[1] = "Z ";
						field(first, second, third);
						second[1] = remember;

					}
					else if (x >= 1 and y == 0 and second[2] == "X ")
					{
						system("cls");
						remember = second[2];
						second[2] = "Z ";
						field(first, second, third);
						second[2] = remember;
						x = 1;
					}
					else if (x <= -1 and y <= -1 and third[0] == "X ")
					{
						system("cls");
						remember = third[0];
						third[0] = "Z ";
						field(first, second, third);
						third[0] = remember;
						x = -1;
						y = -1;
					}
					else if (x == 0 and y <= -1 and third[1] == "X ")
					{
						system("cls");
						remember = third[1];
						third[1] = "Z ";
						field(first, second, third);
						third[1] = remember;
						y = -1;
					}
					else if (x >= 1 and y <= -1 and third[2] == "X ")
					{
						system("cls");
						remember = third[2];
						third[2] = "Z ";
						field(first, second, third);
						third[2] = remember;
						x = 1;
						y = -1;
					}



					if (x == -1 and y == 1 and first[0] != "O " and chose == 'f' and first[0] != "X ")
					{
						system("cls");
						first[0] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == 0 and y == 1 and first[1] != "O " and chose == 'f' and first[1] != "X ")
					{
						system("cls");
						first[1] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == 1 and y == 1 and first[2] != "O " and chose == 'f' and first[2] != "X ")
					{
						system("cls");
						first[2] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == -1 and y == 0 and second[0] != "O " and chose == 'f' and second[0] != "X ")
					{
						system("cls");
						second[0] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == 0 and y == 0 and second[1] != "O " and chose == 'f' and second[1] != "X ")
					{
						system("cls");
						second[1] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == 1 and y == 0 and second[2] != "O " and chose == 'f' and second[2] != "X ")
					{
						system("cls");
						second[2] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == -1 and y == -1 and third[0] != "O " and chose == 'f' and third[0] != "X ")
					{
						system("cls");
						third[0] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == 0 and y == -1 and third[1] != "O " and chose == 'f' and third[1] != "X ")
					{
						system("cls");
						third[1] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}
					else if (x == 1 and y == -1 and third[2] != "O " and chose == 'f' and third[2] != "X ")
					{
						system("cls");
						third[2] = "O ";
						field(first, second, third);
						exit = 1;
						win = check_win_O(first, second, third);
						win = check_draw(first, second, third, win);
					}

				}
				else
				{
				exit = 1;
 }

			}

			exit = 0;


		}

		std::cout << " I sosal meni ebali " << endl;

	}

}


