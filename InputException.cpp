#include "InputException.h"


int InputInt(int min, int max) //��������� ����� ������
{
	int var = 0;
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin >> var;
			if (!std::cin || std::cin.peek() != '\n')
				throw InputException("������ ������� ������", "������� ����� �����");
			if (var > max || var < min) throw InputException("������ ������ �� �������", 
				("������� ������ � �������� �� " + ConvertIntToString(min) 
					+ " �� " + ConvertIntToString(max)).c_str());
			return var;
		}

		catch (InputException obj)
		{
			std::cin.clear();
			obj.ShowError();
		}
	}
}

double InputDouble(double min, double max) //��������� ����� ������������� �����
{
	double var = 0;
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin >> var;
			if (!std::cin || std::cin.peek() != '\n') throw InputException("������ ������� ������", "");
			if (var > max || var < min) throw InputException("������ ������ �� �������", ("������� ������ � �������� �� " + ConvertDblToString(min)
				+ " �� " + ConvertDblToString(max)).c_str());
			return var;
		}

		catch (InputException obj)
		{

			std::cin.clear();
			obj.ShowError();
		}
	}
}

char* InputCyrillicString() //���� ���������
{
	char* buffer = new char[BASE_LEN];
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin.getline(buffer, BASE_LEN);
			if (!std::cin)throw InputException("������ ������ �� �������", "������� ������ ����� 80 �������� ");
			for (unsigned int i = 0; i < strlen(buffer); i++)
			{
				if ((buffer[i] < '�' or buffer[i] > '�') and buffer[i] != ' ' and buffer[i] != ',' and buffer[i] != '.' and buffer[i] < '0' or buffer[i] > '9')
					throw InputException("������ ����� ���������� ������", "������� ������ ����������");
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

char* InputLatinicString() //���� �������� 
{
	char* buffer = new char[BASE_LEN];
	while (true)
	{
		try
		{
			rewind(stdin);
			std::cin.getline(buffer, BASE_LEN);
			if (!std::cin)throw InputException("������ ������ �� �������", "������� ������ ������ 80 �������� ");
			for (unsigned int i = 0; i < strlen(buffer); i++)
			{
				if ((buffer[i] < 'A' or buffer[i] > 'Z') and (buffer[i] < 'a' or buffer[i] > 'z') 
					and buffer[i] != ' ' and buffer[i] != ',' and buffer[i] != '.' and (buffer[i] < '0' or buffer[i] > '9'))
					throw InputException("������ ����� ���������� ������", "������� ������ ���������");
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

std::string ConvertIntToString(int num) //����������� ������ � ������
{
	char buf[BASE_LEN];
	sprintf_s(buf, "%d", num);
	std::string str = buf;
	return str;
}

std::string ConvertDblToString(double num) //����������� ������������� � ������
{
	char buf[BASE_LEN];
	sprintf_s(buf, "%lf", num);
	std::string str = buf;
	return str;
}


InputException::~InputException() //����������
{}

void InputException::ShowError() //����� ������
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
