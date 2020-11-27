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
		std::cout << "Простите( Получилось всё очень некрасиво, так как владелец кода набрал кучу дел, а по итогу ничего полностью не сделал";
		return 1;
	}

	if (level == 0 && Num == 2)
	{

		srand(time(NULL));
		short NumDrink;

		NumDrink = rand() % 5;

		std::string drinks[5]{
			"чаёк",
			"кофеёк",
			"лимонадик",
			"водичку",
			"коктейль", };

		std::cout << "Попейте " << drinks[NumDrink] << " :3" << std::endl;

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
				std::cout << "3 подхода по 15 приседаний";
				break;
			}
			case 2:
			{
				std::cout << "2 подхода по 10 выпадов";
				break;
			}
			case 3:
			{
				std::cout << "5 подходов по 10 наклонов головы";
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
				std::cout << "Посмотрите: Американский пирог";
				break;
			}
			case 2:
			{
				std::cout << "Посмотрите: Жизнь Дэвида Гейла";
				break;
			}
			case 3:
			{
				std::cout << "Посмотрите: Час пик";
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
				std::cout << "— Чем отличается программист от политика? — Программисту платят деньги за работающие программы.";
				break;
			}
			case 2:
			{
				std::cout << "Этот раздел был самый трудный для фантазии кодера";
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

		//if (current == 1)				//Упражнения
		//{
		//	if (Num == 1)
		//	{
		//		std::cout << "3 подхода по 15 приседаний";
		//	}
		//	if (Num == 2)
		//	{
		//		std::cout << "2 подхода по 10 выпадов";
		//	}
		//	if (Num == 3)
		//	{
		//		std::cout << "5 подходов по 10 наклонов головы";
		//	}
		//}
		//if (current == 2)		//Фильмы
		//{
		//	if (Num == 1)
		//	{
		//		std::cout << "Американский пирог";
		//	}
		//	if (Num == 2)
		//	{
		//		std::cout << "Жизнь Дэвида Гейла";
		//	}
		//	if (Num == 3)
		//	{
		//		std::cout << "Час пик";
		//	}
		//}
		//if (current == 3)		//Что-то другое...
		//{
		//	if (Num == 1)
		//	{
		//		std::cout << "— Чем отличается программист от политика? — Программисту платят деньги за работающие программы.";
		//	}
		//	if (Num == 2)
		//	{
		//		std::cout << "Этот раздел был самый трудный для фантазии кодера";
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
			"Здравствуй, пользователь! Вы ччто-то хотите?",
			"Хочу ругаться, потому что работа сдана в самый дедлайн, а второй вообще нет!!!",
			"Я хочу что-то попить, но не знаю что (((",
			"Я не знаю, чего хочу :("
		};
		display(Num, menu, size);
	}
	break;

	case 1:
	{
		const short size = 4;
		std::string menu[size]{
			"Давайте подумаем над вариантами!",
			"Может быть вы хотите размяться?",
			"Может посмотреть что-то?",
			"Что-то другое?"
		};
		display(Num, menu, size);
	}
	break;

	case 2:
	{
		const short Line = 3;
		const short Col = 4;
		std::string menu_list[Line][Col]{
		 "Как сказал кто-то там: \"Движение - это жизнь\". Выберите упражнение.","Упражнение №1","Упражнение №2","Упражнение №3",
		 "Какой жанр вы предпочитаете?","Комедия","Драма","Боевик",
		 "Хммм... Даже не знаю...","Может быть анекдот?","Может интересный факт?","Ссылка на вк кодера?",
		};

		SelectDisplay(Num, menu_list, Current, Col);
	}

	}


}


int wanna_exit() {			//Выход (не получается сделать так, чтобы он воспринимал русскую раскладку)

	system("cls");
	std::cout << "Ты действительно хочешь выйти? Если да - нажми 'Y', если нет - любую другую кнопку";

	if (_getch() == 'y')
		return 1;
	else
		return 0;

}

int main() {
	setlocale(LC_ALL, "RUS");

	std::cout << "Доброго времени суток! Это меню, сделанное органическим отходом с группы 0091\n" <<    //Приветствие
		"Стрелочки \x1b[32mвверх\x1b[0m и \x1b[32mвниз\x1b[0m - выбор нужного пункта меню\n"
		"\x1b[32mEnter\x1b[0m - подтверждение выбора\n"
		"\x1b[32mEsc\x1b[0m - отмена выбора/возвращение назад" << std::endl << std::endl;

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
