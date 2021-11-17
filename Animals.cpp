#include <iostream>
#include <string>
#include <conio.h>

enum codes {
	Enter = 13,
	ESC = 27,
	Up = 72,
	Down = 80,
};

void Start(int& index, short& num)
{
	index = 0;
	num = 0;
	system("cls");
	std::cout << "Zagadai zhivotnoe i nachni igru" << std::endl;
	system("pause");
}

void display(short num, std::string Question[], int index)
{
	system("cls");
	const short size = 2;

	std::string YesNo[size]{
		"Yes",
		"No",
	};

	std::cout << Question[index] << std::endl << std::endl;

	for (int i = 0; i < size; i++)
	{
		if (i == num)
		{
			std::cout << "\x1b[31m-->\x1b[0m" << YesNo[i] << std::endl << std::endl;
		}
		else
		{
			std::cout << "  " << YesNo[i] << std::endl << std::endl;
		}
	}
}

int WinGame()
{
	
	std::cout << std::endl << "You are winner!" << std::endl 
		<< "Do you want to start game again? Y - yes, other key - no";
	if (_getch() == 'y')
		return 2;
	else 
		return 3;

}

int AddQuestion(std::string Question[], int index)
{
	system("cls");

	std::cout << "Ooops... Bolshe net voprosov..." << std::endl;

	std::cout << "Chto za zhivotnoe bilo? Napishi: ";
	std::getline(std::cin, Question[index * 2 + 1]);

	std::cout << std::endl << "Pridumai k nemu vopros. Napishi : ";
	std::getline(std::cin, Question[index]);

	std::cout << "\n\nSpasibo! Igra stala escho luchshe!\n"
		<< "Hochesh nachat' igru zanovo? Y - yes, other key - no";

	if (_getch() == 'y')
		return 2;
	else
		return 3;

}

int main()
{

	short num = 0;	//da-net

	int i = 0;
	int flag = i;			// metka indexa, v kotorom net voprosa
	std::string DataBase[101];

	std::cout << "Privet, davai sigraem v igry Ygadai Zhivotnoe\n" <<
		"Oops, seichas basa dannih pustaya.\n" <<
		"Zagadai kakoe-nibud' zhivotnoe i zapishi vopros, kotorii podhodit k nemu: " << std::endl << std::endl;

	std::getline(std::cin, DataBase[i]);

	std::cout << "A teper' zapishi zagadannoe zhivotnoe:  ";

	std::getline(std::cin, DataBase[i * 2 + 1]);

	flag = i * 2 + 2;
	std::cout << std::endl << "Yohoo! Teper' igra stala esche interesnee!";

	Start(i, num);
	display(num, DataBase, i);


	while (true)
	{
		switch (_getch())
		{
		case Down:
			num == 0 ? num = 1 : num = 0;
			display(num, DataBase, i);
			break;

		case Up:
			num == 0 ? num = 1 : num = 0;

			display(num, DataBase, i);
			break;

		case Enter:
		{
			if (i % 2 == 0)		//vetki voprosov
			{
				if (num == 0)			//perehod k predpolozheniu
				{
					i = i * 2 + 1;
					display(num, DataBase, i);
				}
				else		//perehod k sleduschemu voprosu
				{

					i = i * 2 + 2;

					if (i >= flag)			//esli voprosi konchilis', to dobavit' novii vopros i otvet
					{
						flag = i * 2 + 2;

						if (AddQuestion(DataBase, i) == 3)
						{
							return 0;
						}
						else
						{
							Start(i, num);
							display(num, DataBase, i);
						}
					}
					else				//inache prodolzhit'
					{
						display(num, DataBase, i);
					}
				}
			}
			else		//vetki predpolozhenii
			{
				if (num == 0)		//Win
				{
					if (WinGame() == 3)		//vihod ili prodolzhenie
					{
						return 0;
					}
					else
					{
						Start(i, num);
						display(num, DataBase, i);
					}
				}
				else			//perehod k voprosu
				{
					i += 1;

					if (i >= flag)			//esli voprosi konchilis', to dobavit' novii vopros i otvet
					{
						flag = i * 2 + 2;

						if (AddQuestion(DataBase, i) == 3)
						{
							return 0;
						}
						else
						{
							Start(i, num);
							display(num, DataBase, i);
						}
					}
					else				//inache prodolzhit'
					{
						display(num, DataBase, i);
					}
				}
			}
		}
		}

	}
	return 0;
}