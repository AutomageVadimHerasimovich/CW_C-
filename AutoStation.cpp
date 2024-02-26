#include "AutoStation.h"

std::istream& operator>>(std::istream& in, AutoStation& obj) //перегрузка операторов
{
	std::cout << "Введите средний чек на станции обслуживания : " << std::endl;
	obj.avgCheckPrice = InputDouble(1);
	std::cout << "Укажите адрес станции обслуживания : " << std::endl;
	strcpy_s(obj.geoLocation, InputCyrillicString());
	return in;
}

std::ostream& operator<<(std::ostream& out, AutoStation& obj)
{
	out << "|" << std::left << std::setw(21) << obj.avgCheckPrice << "|" << std::setw(22) << obj.geoLocation << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(47) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, AutoStation& obj)
{
	out << obj.geoLocation << '|' << obj.avgCheckPrice << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, AutoStation& obj)
{
	in.getline(obj.geoLocation, BASE_LEN, '|');
	in >> obj.avgCheckPrice;
	in.get();
	return in;
}

void AutoStation::SetAvgCheckPrice(double newPrice) //изменение значения
{
	avgCheckPrice = newPrice;
}

void AutoStation::SetGeoLocation(const char* newGeo)
{
	strcpy_s(geoLocation, newGeo);
}

const char* AutoStation::GetGeoLocation() //получение значения
{
	return geoLocation;
}

double AutoStation::GetAvgCheckPrice()
{
	return avgCheckPrice;
}

AutoStation::AutoStation(AutoStation& obj) //конструктор копирования
{
	strcpy_s(geoLocation, obj.geoLocation);
	avgCheckPrice = obj.avgCheckPrice;
}

AutoStation& AutoStation::operator=(AutoStation& obj) //оператор присваивания
{
	if (this != &obj)
	{
		strcpy_s(geoLocation, obj.geoLocation);
		avgCheckPrice = obj.avgCheckPrice;
	}
	return *this;
}

bool AutoStation::operator==(AutoStation& other) //перегрузка операторов
{
	if (strcmp(other.geoLocation, ""))
		if (!(strcmp(geoLocation, other.geoLocation) == 0)) return false;

	if (other.avgCheckPrice > 0)
		if (avgCheckPrice != other.avgCheckPrice) return false;

	return true;
}

bool AutoStation::operator!=(AutoStation& other)
{
	return !(*this == other);
}

bool AutoStation::operator>(AutoStation& other)
{
	return avgCheckPrice > other.avgCheckPrice;
}

bool AutoStation::operator<(AutoStation& other)
{
	return avgCheckPrice < other.avgCheckPrice;
}

void AutoStation::PrintTableHead() //вывод шапки таблицы
{
	std::cout << std::setfill('_') << std::setw(20) << " Средний чек($) " << std::setw(23) << " Местоположение " << std::setw(4) << "\n";
	std::cout << std::setfill(' ') << std::left;
}

void AutoStation::SetFieldValue() //изменить поле класса
{
	int modeSelector;
	double doubleNum;
	char buf[BASE_LEN];
	while (true)
	{
		modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (modeSelector == 1)
				PrintMenuPunct("Местоположение");
			else std::cout << "Местоположение" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Средний чек");
			else std::cout << "Средний чек" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 2) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
			std::cout << "Введите местоположение станции" << std::endl;
			strcpy_s(buf, InputCyrillicString());                     //ввод искомого ФИО
			SetGeoLocation(buf);
			break;
		case 2:
			std::cout << "Введите средний чек на станции($)" << std::endl;
			doubleNum = InputDouble();
			SetAvgCheckPrice(doubleNum);							  //ввод искомой группы
			break;
		}
	}
}
