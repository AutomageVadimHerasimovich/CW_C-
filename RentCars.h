#pragma once
#include "Car.h"

class RentCars : public Car   //класс аренды машин
{
protected:
	double rentPrice;    //цена аренды
public:
	RentCars() : Car(), rentPrice(0.0)
	{}
	~RentCars() //конструктор и деструктор
	{}

	void SetRentPrice(double newPrice); //установить цену

	double GetRentPrice(); //получить цену

	RentCars(RentCars& other); //конструктор копирования
	RentCars& operator=(RentCars& obj); //перегрузки операторов

	friend std::istream& operator>>(std::istream& in, RentCars& obj);
	friend std::ostream& operator<<(std::ostream& out, RentCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, RentCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, RentCars& obj);

	void virtual PrintTableHead(); //выовод шапки таблицы
};