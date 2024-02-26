#pragma once
#include "CarsForSale.h"

class SportCars : public CarsForSale //класс спортивных авто
{
private:
	double accelTime;      //время разгона
public:
	SportCars() : CarsForSale(), accelTime(0.0)
	{}
	~SportCars() //конструктор и деструктор
	{}

	void SetAccelTime(double newTime); //установить время

	double GetAccelTime(); //получить время

	SportCars(SportCars& other); //конструктор перемещения
	SportCars& operator=(SportCars& obj); //перегрузки операторов

	bool operator==(SportCars& other); 
	bool operator!=(SportCars& other);
	bool operator>(SportCars& other);
	bool operator<(SportCars& other);

	friend std::istream& operator>>(std::istream& in, SportCars& obj);
	friend std::ostream& operator<<(std::ostream& out, SportCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, SportCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, SportCars& obj);

	void virtual PrintTableHead(); //вывод шапки таблицы
	void SubMenu(Tree<SportCars> obj); //меню фильтра
	void SetFieldValue(); //изменить опр поле класса
	int SortData(); //сортировать контейнер
};


