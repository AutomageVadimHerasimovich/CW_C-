#include "Date.h"

std::ostream& operator<<(std::ostream& out, Date& someDate)  //���������� ���������� �����
{
	out << std::right << std::setw(2) << someDate.day << '.' << std::setw(2) << someDate.month << '.' << std::setw(4) << someDate.year << std::left;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, Date& obj)
{
	out << obj.day << ' ';
	out << obj.month << ' ';
	out << obj.year;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Date& obj)
{
	in >> obj.day;
	in >> obj.month;
	in >> obj.year;
	return in;
}


void InputDate(Date& newDate) //��������� ����� ����
{
	while (true)
	{
		try
		{
			std::cout << "������� ����" << std::endl;
			rewind(stdin);
			newDate.day = InputInt(1, 31);
			std::cout << "������� �����" << std::endl;
			rewind(stdin);
			newDate.month = InputInt(1, 12);
			std::cout << "������� ���" << std::endl;
			rewind(stdin);
			newDate.year = InputInt(1);
			if ((newDate.month <= 7 && newDate.month % 2 == 0 && newDate.day == 31)
				|| (newDate.month > 7 && newDate.month % 2 == 1 && newDate.day == 31)
				|| (newDate.month == 2 && newDate.day > 28))
			{
				throw InputException("������ ������ �� �������", "� ���� ������ ��� ������ ���, ������� ���� ������ ");
			}
			return;
		}
		catch (InputException obj)
		{
			obj.ShowError();
		}
	}
}

Date::Date(Date& other) //����������� �����������
{
	day = other.day;
	month = other.month;
	year = other.year;
}

Date& Date::operator=(Date& other) //�������� ������������
{
	if (this != &other)
	{
		day = other.day;
		month = other.month;
		year = other.year;
	}
	return *this;
}

bool Date::operator==(Date& other) //���������� ����������
{
	if (day != other.day) return false;
	if (month != other.month) return false;
	if (year != other.year) return false;
	return true;
}

bool Date::operator!=(Date& other)
{
	return !(*this == other);
}

bool Date::operator>(Date& other)
{
	if (year == other.year)
	{
		if (month == other.month)
		{
			if (day == other.day)
			{
				return true;
			} else return day > other.day;
		} else return month > other.month;
	} else return year > other.year;
}

bool Date::operator<(Date& other)
{
	if (year == other.year)
	{
		if (month == other.month)
		{
			if (day == other.day)
			{
				return false;
			}
			else return day < other.day;
		}
		else return month < other.month;
	}
	else return year < other.year;
}

int Date::GetDay() //�������� ��������
{
	return day;
}
