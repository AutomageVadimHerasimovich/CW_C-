#include "RentCars.h"

std::istream& operator>>(std::istream& in, RentCars& obj) //перегрузка операторов ввода
{
    in >> dynamic_cast<Car&>(obj);
    std::cout << "¬ведите цену автомобил€ за мес€ц ($/мес.) : " << std::endl;
    obj.rentPrice = InputDouble(1);
    return in;
}

std::ostream& operator<<(std::ostream& out, RentCars& obj)
{
	out << dynamic_cast<Car&>(obj);
	out << "|" << std::setw(22) << obj.rentPrice << ' ';
    return out;
}

std::ofstream& operator<<(std::ofstream& out, RentCars& obj)
{
	out << dynamic_cast<Car&>(obj);
	out << obj.rentPrice << ' ';
	return out;
}

std::ifstream& operator>>(std::ifstream& in, RentCars& obj)
{
	in >> dynamic_cast<Car&>(obj);
	in >> obj.rentPrice;
	return in;
}

void RentCars::SetRentPrice(double newPrice) //изменить поле
{
    rentPrice = newPrice;
}

double RentCars::GetRentPrice() //получить поле
{
    return rentPrice;
}

RentCars::RentCars(RentCars& obj) : Car(obj) //конструктор копировани€
{
	rentPrice = obj.rentPrice;
}

RentCars& RentCars::operator=(RentCars& obj) //оператор присваивани€
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		rentPrice = obj.rentPrice;
	}
	return *this;
}

void RentCars::PrintTableHead() //вывести шапку таблицы
{
	Car::PrintTableHead();
	std::cout << std::setw(23) << " ÷ена аренды($) ";
}
