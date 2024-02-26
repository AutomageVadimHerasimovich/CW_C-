#pragma once
#include "Car.h"

class CarsForSale : public Car //класс машин для продажи
{
protected:
	double carPrice;   //цена автомобиля
public:
	CarsForSale() : Car(), carPrice(0.0) //конструктор 
	{} 
	~CarsForSale() //деструктор
	{}

	void SetCarPrice(double newPrice); //установить цену

	double GetCarPrice();  //получить цену

	CarsForSale(CarsForSale& other); //конструктор копирования
	CarsForSale& operator=(CarsForSale& obj); //оператор присваивания

	friend std::istream& operator>>(std::istream& in, CarsForSale& obj); //перегрузка операторов
	friend std::ostream& operator<<(std::ostream& out, CarsForSale& obj);

	friend std::ofstream& operator<<(std::ofstream& out, CarsForSale& obj);
	friend std::ifstream& operator>>(std::ifstream& in, CarsForSale& obj);

	void virtual PrintTableHead(); //вывод шапки таблицы
};