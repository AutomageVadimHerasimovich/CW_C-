#pragma once
#include "Car.h"

class RentCars : public Car   //����� ������ �����
{
protected:
	double rentPrice;    //���� ������
public:
	RentCars() : Car(), rentPrice(0.0)
	{}
	~RentCars() //����������� � ����������
	{}

	void SetRentPrice(double newPrice); //���������� ����

	double GetRentPrice(); //�������� ����

	RentCars(RentCars& other); //����������� �����������
	RentCars& operator=(RentCars& obj); //���������� ����������

	friend std::istream& operator>>(std::istream& in, RentCars& obj);
	friend std::ostream& operator<<(std::ostream& out, RentCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, RentCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, RentCars& obj);

	void virtual PrintTableHead(); //������ ����� �������
};