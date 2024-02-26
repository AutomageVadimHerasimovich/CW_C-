#include "Car.h"

std::istream& operator>>(std::istream& in, Car& obj) //перегрузка операторов ввода
{
	std::cout << "Введите модель автомобиля : " << std::endl;
	strcpy_s(obj.carModel, InputLatinicString());
	std::cout << "Введите мощность двигателя(кВт/л) : " << std::endl;
	obj.enginePower = InputDouble(1);
	std::cout << "Введите вес машины(т) : " << std::endl;
	obj.weight = InputDouble(0.5);
	return in;
}

std::ostream& operator<<(std::ostream& out, Car& obj)
{
	out << "|" << std::left << std::setw(17) << obj.carModel << "|" << std::setw(33) << obj.enginePower << "|" << std::setw(14) << obj.weight;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, Car& obj)
{
	out << obj.carModel << '|' << obj.enginePower << ' ' << obj.weight << ' ';
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Car& obj)
{
	in.getline(obj.carModel, BASE_LEN, '|');
	in >> obj.enginePower;
	in >> obj.weight;
	return in;
}

Car::Car() : carModel(""), enginePower(0.0), weight(0.0), compareParam(0)
{}

Car::Car(Car & obj) //конструкторы копирования
{
	strcpy_s(carModel, obj.carModel);
	enginePower = obj.enginePower;
	weight = obj.weight;
	compareParam = obj.compareParam;
}

void Car::SetCompareParam(int otherParam) //установить значение
{
	compareParam = otherParam;
}

void Car::SetCarModel(const char* newModel)
{
	strcpy_s(carModel, newModel);
}

void Car::SetEnginePower(double power)
{
	enginePower = power;
}

void Car::SetWeight(double newWeight)
{
	weight = newWeight;
}

const char* Car::GetCarModel() //получить значение
{
	return carModel;
}

double Car::GetEnginePower()
{
	return enginePower;
}

double Car::GetWeight()
{
	return weight;
}

Car& Car::operator=(Car& obj) //оператор присваивания
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
	}
	return *this;
}

void Car::PrintTableHead() //вывод шапки таблицы
{
	std::cout << std::right << std::setfill('_') << std::setw(15) << " Модель " << std::setw(34) << " Мощность двигателя(кВт/л) " << std::setw(15) << " Вес(т) ";
}

void PrintMenuPunct(const char* text)       //метод вывода выбранного пункта для интерактивного меню
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | TEXT_COLOUR); //добавляем цвет фона за текстом
	std::cout << text << std::endl;
	SetConsoleTextAttribute(hStdOut, TEXT_COLOUR);                   //возвращаем текст в нужный цвет
}
