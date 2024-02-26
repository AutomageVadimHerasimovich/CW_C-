#include "RentCars.h"

std::istream& operator>>(std::istream& in, RentCars& obj) //���������� ���������� �����
{
    in >> dynamic_cast<Car&>(obj);
    std::cout << "������� ���� ���������� �� ����� ($/���.) : " << std::endl;
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

void RentCars::SetRentPrice(double newPrice) //�������� ����
{
    rentPrice = newPrice;
}

double RentCars::GetRentPrice() //�������� ����
{
    return rentPrice;
}

RentCars::RentCars(RentCars& obj) : Car(obj) //����������� �����������
{
	rentPrice = obj.rentPrice;
}

RentCars& RentCars::operator=(RentCars& obj) //�������� ������������
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

void RentCars::PrintTableHead() //������� ����� �������
{
	Car::PrintTableHead();
	std::cout << std::setw(23) << " ���� ������($) ";
}
