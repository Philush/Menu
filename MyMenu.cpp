#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>

enum codes {
	Enter = 13,
	ESC = 27,
	Up = 72,
	Down = 80,
};


int Select_Result(int Num, int level, int current)
{

	system("cls");

	if (level == 0 && Num == 1)
	{
		std::cout << "��������( ���������� �� ����� ���������, ��� ��� �������� ���� ������ ���� ���, � �� ����� ������ ��������� �� ������";
		return 1;
	}

	if (level == 0 && Num == 2)
	{

		srand(time(NULL));
		short NumDrink;

		NumDrink = rand() % 5;

		std::string drinks[5]{
			"���",
			"�����",
			"���������",
			"�������",
			"��������", };

		std::cout << "������� " << drinks[NumDrink] << " :3" << std::endl;

		return 1;
	}
	if (level == 2)
	{
		switch (current)
		{
		case 1:
		{
			switch (Num)
			{
			case 1:
			{
				std::cout << "3 ������� �� 15 ����������";
				break;
			}
			case 2:
			{
				std::cout << "2 ������� �� 10 �������";
				break;
			}
			case 3:
			{
				std::cout << "5 �������� �� 10 �������� ������";
				break;
			}
			}
			break;
		}

		case 2:
		{

			switch (Num)
			{

			case 1:
			{
				std::cout << "����������: ������������ �����";
				break;
			}
			case 2:
			{
				std::cout << "����������: ����� ������ �����";
				break;
			}
			case 3:
			{
				std::cout << "����������: ��� ���";
				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (Num)
			{
			case 1:
			{
				std::cout << "� ��� ���������� ����������� �� ��������? � ������������ ������ ������ �� ���������� ���������.";
				break;
			}
			case 2:
			{
				std::cout << "���� ������ ��� ����� ������� ��� �������� ������";
				break;
			}
			case 3:
			{
				std::cout << "vk.com/d17192015";
				break;
			}
			}
		}

		}

		//if (current == 1)				//����������
		//{
		//	if (Num == 1)
		//	{
		//		std::cout << "3 ������� �� 15 ����������";
		//	}
		//	if (Num == 2)
		//	{
		//		std::cout << "2 ������� �� 10 �������";
		//	}
		//	if (Num == 3)
		//	{
		//		std::cout << "5 �������� �� 10 �������� ������";
		//	}
		//}
		//if (current == 2)		//������
		//{
		//	if (Num == 1)
		//	{
		//		std::cout << "������������ �����";
		//	}
		//	if (Num == 2)
		//	{
		//		std::cout << "����� ������ �����";
		//	}
		//	if (Num == 3)
		//	{
		//		std::cout << "��� ���";
		//	}
		//}
		//if (current == 3)		//���-�� ������...
		//{
		//	if (Num == 1)
		//	{
		//		std::cout << "� ��� ���������� ����������� �� ��������? � ������������ ������ ������ �� ���������� ���������.";
		//	}
		//	if (Num == 2)
		//	{
		//		std::cout << "���� ������ ��� ����� ������� ��� �������� ������";
		//	}
		//	if (Num == 3)
		//	{
		//		std::cout << "vk.com/d17192015";
		//	}
		//}
		return 1;
	}


}





template <typename T>
void display(int Num, T menu, short size)
{
	std::cout << "\x1b[32m" << menu[0] << "\x1b[0m" << std::endl << std::endl;
	for (int i = 1; i < size; i++)
	{
		if (i == Num)
		{
			std::cout << "\x1b[31m-->\x1b[0m" << menu[i] << std::endl << std::endl;
		}
		else
		{
			std::cout << "  " << menu[i] << std::endl << std::endl;
		}
	}
}


void SelectDisplay(short Num, std::string menu_list[3][4], short current, const int Col)
{

	std::cout << "\x1b[32m" << menu_list[current - 1][0] << "\x1b[0m" << std::endl << std::endl;
	Num--;
	current--;

	for (int i = 1; i < Col; i++) {
		if ((i - 1) == Num)
		{
			std::cout << "\x1b[31m-->\x1b[0m" << menu_list[current][i] << std::endl << std::endl;
		}
		else
		{
			std::cout << "  " << menu_list[current][i] << std::endl << std::endl;
		}
	}
}


void Initial_Display(short Level, short Current, short Num)
{
	switch (Level)
	{
	case 0:
	{
		const short size = 4;
		std::string menu[size]{
			"����������, ������������! �� ����-�� ������?",
			"���� ��������, ������ ��� ������ ����� � ����� �������, � ������ ������ ���!!!",
			"� ���� ���-�� ������, �� �� ���� ��� (((",
			"� �� ����, ���� ���� :("
		};
		display(Num, menu, size);
	}
	break;

	case 1:
	{
		const short size = 4;
		std::string menu[size]{
			"������� �������� ��� ����������!",
			"����� ���� �� ������ ���������?",
			"����� ���������� ���-��?",
			"���-�� ������?"
		};
		display(Num, menu, size);
	}
	break;

	case 2:
	{
		const short Line = 3;
		const short Col = 4;
		std::string menu_list[Line][Col]{
		 "��� ������ ���-�� ���: \"�������� - ��� �����\". �������� ����������.","���������� �1","���������� �2","���������� �3",
		 "����� ���� �� �������������?","�������","�����","������",
		 "����... ���� �� ����...","����� ���� �������?","����� ���������� ����?","������ �� �� ������?",
		};

		SelectDisplay(Num, menu_list, Current, Col);
	}

	}


}


int wanna_exit() {			//����� (�� ���������� ������� ���, ����� �� ����������� ������� ���������)

	system("cls");
	std::cout << "�� ������������� ������ �����? ���� �� - ����� 'Y', ���� ��� - ����� ������ ������";

	if (_getch() == 'y')
		return 1;
	else
		return 0;

}

int main() {
	setlocale(LC_ALL, "RUS");

	std::cout << "������� ������� �����! ��� ����, ��������� ������������ ������� � ������ 0091\n" <<    //�����������
		"��������� \x1b[32m�����\x1b[0m � \x1b[32m����\x1b[0m - ����� ������� ������ ����\n"
		"\x1b[32mEnter\x1b[0m - ������������� ������\n"
		"\x1b[32mEsc\x1b[0m - ������ ������/����������� �����" << std::endl << std::endl;

	system("pause");
	system("cls");

	short num = 1, level = 0, current = 1;

	Initial_Display(level, current, num);

	while (true)
	{
		switch (_getch())
		{
		case Down:
			num == 3 ? num = 1 : num++;
			break;

		case Up:
			num == 1 ? num = 3 : num--;
			break;

		case Enter:

			if (Select_Result(num, level, current) == 1)
			{
				num = 1, level = 0, current = 1;
				std::cout << "\n";
				system("pause");
				if (wanna_exit() == 1)
				{
					return 0;
				}
			}
			else
			{
				current = num;
				level++;
				num = 1;
			}

			break;

		case ESC:
			if (level < 1)
			{
				if (wanna_exit())
				{
					return 0;
				}
			}
			else
			{
				level--;
				num = 1;
			}
			break;
		}
		system("cls");
		Initial_Display(level, current, num);
	}
	return 0;
}
