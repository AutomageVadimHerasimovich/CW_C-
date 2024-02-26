#include "InputException.h"


int InputInt(int min, int max) //обработка ввода целого
{
	int var = 0;
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin >> var;
			if (!std::cin || std::cin.peek() != '\n')
				throw InputException("Ошибка формата данных", "Введите целое число");
			if (var > max || var < min) throw InputException("Ошибка выхода за границы", 
				("Введите строку в границах от " + ConvertIntToString(min) 
					+ " до " + ConvertIntToString(max)).c_str());
			return var;
		}

		catch (InputException obj)
		{
			std::cin.clear();
			obj.ShowError();
		}
	}
}

double InputDouble(double min, double max) //обработка ввода вещественного числа
{
	double var = 0;
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin >> var;
			if (!std::cin || std::cin.peek() != '\n') throw InputException("Ошибка формата данных", "");
			if (var > max || var < min) throw InputException("Ошибка выхода за границы", ("Введите строку в границах от " + ConvertDblToString(min)
				+ " до " + ConvertDblToString(max)).c_str());
			return var;
		}

		catch (InputException obj)
		{

			std::cin.clear();
			obj.ShowError();
		}
	}
}

char* InputCyrillicString() //ввод кириллицы
{
	char* buffer = new char[BASE_LEN];
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin.getline(buffer, BASE_LEN);
			if (!std::cin)throw InputException("Ошибка выхода за границы", "Введите строку менее 80 символов ");
			for (unsigned int i = 0; i < strlen(buffer); i++)
			{
				if ((buffer[i] < 'А' or buffer[i] > 'я') and buffer[i] != ' ' and buffer[i] != ',' and buffer[i] != '.' and buffer[i] < '0' or buffer[i] > '9')
					throw InputException("Ошибка ввода символьных данных", "Введите строку кириллицей");
			}
			return buffer;
		}
		catch (InputException obj)
		{
			std::cin.clear();
			obj.ShowError();
		}
	}
}

char* InputLatinicString() //ввод латиницы 
{
	char* buffer = new char[BASE_LEN];
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin.getline(buffer, BASE_LEN);
			if (!std::cin)throw InputException("Ошибка выхода за границы", "Введите строку меньше 80 символов ");
			for (unsigned int i = 0; i < strlen(buffer); i++)
			{
				if ((buffer[i] < 'A' or buffer[i] > 'Z') and (buffer[i] < 'a' or buffer[i] > 'z') 
					and buffer[i] != ' ' and buffer[i] != ',' and buffer[i] != '.' and (buffer[i] < '0' or buffer[i] > '9'))
					throw InputException("Ошибка ввода символьных данных", "Введите строку латиницей");
			}
			return buffer;
		}
		catch (InputException obj)
		{
			std::cin.clear();
			obj.ShowError();
		}
	}
}

std::string ConvertIntToString(int num) //конвертация целого в строку
{
	char buf[BASE_LEN];
	sprintf_s(buf, "%d", num);
	std::string str = buf;
	return str;
}

std::string ConvertDblToString(double num) //конвертация вещественного в строку
{
	char buf[BASE_LEN];
	sprintf_s(buf, "%lf", num);
	std::string str = buf;
	return str;
}


InputException::~InputException() //деструктор
{}

void InputException::ShowError() //вывод ошибки
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << exceptionType << std::endl;
	std::cout << exceptionInputName << std::endl;
	SetConsoleTextAttribute(hConsole, TEXT_COLOUR);
}

InputException::InputException(const char* type, const char* name) : ExceptionType(type)
{
	strcpy_s(exceptionInputName, name);
}
