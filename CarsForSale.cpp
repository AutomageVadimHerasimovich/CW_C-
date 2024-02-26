#include "CarsForSale.h"
#include <iostream>

std::istream& operator>>(std::istream& in, CarsForSale& obj) //перегрузка операторов ввода
{
    in >> dynamic_cast<Car&>(obj);
    std::cout << "Введите цену автомобиля ($) : " << std::endl;
    obj.carPrice = InputDouble(1);
    return in;
}

std::ostream& operator<<(std::ostream& out, CarsForSale& obj)
{
	out << dynamic_cast<Car&>(obj);
	out << "|" << std::setw(21) << obj.carPrice << ' ';
    return out;
}

std::ofstream& operator<<(std::ofstream& out, CarsForSale& obj)
{
	out << dynamic_cast<Car&>(obj);
	out << obj.carPrice << ' ';
	return out;
}

std::ifstream& operator>>(std::ifstream& in, CarsForSale& obj)
{
	in >> dynamic_cast<Car&>(obj);
	in >> obj.carPrice;
	return in;
}

void CarsForSale::SetCarPrice(double newPrice) //изменить значение
{
    carPrice = newPrice;
}

double CarsForSale::GetCarPrice() //получить значение
{
    return carPrice;
}

CarsForSale::CarsForSale(CarsForSale& obj) : Car(obj) //контруктор копирования
{
	carPrice = obj.carPrice;
}

CarsForSale& CarsForSale::operator=(CarsForSale& obj) //оператор присваивания
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		carPrice = obj.carPrice;
	}
	return *this;
}	

void CarsForSale::PrintTableHead() //вывод шапки таблицы
{
	Car::PrintTableHead();
	std::cout << std::setw(24) << " Цена покупки($) ";
}

