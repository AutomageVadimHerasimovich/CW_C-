#pragma once
#include "CarsForSale.h"

class PassCars : public CarsForSale //класс пассажирских авто
{
private:
	int seatsNumber;           //число сидений
	double trunkVolume;        //объем багажника
public:
	PassCars() : CarsForSale(), seatsNumber(0), trunkVolume(-1)
	{}
	~PassCars() //конструктор и деструктор
	{}
	
	void SetSeatsNumber(int newSeatsNum); //методы изменения
	void SetTrunkVolume(double newVolume);

	int GetSeatsNumber();            //и получения значений
	double GetTrunkVolume();

	PassCars(PassCars& other);      //констуктор копирования
	PassCars& operator=(PassCars& obj); //оператор присваивания

	bool operator==(PassCars& other); //перегрузки операторов
	bool operator!=(PassCars& other);
	bool operator>(PassCars& other);
	bool operator<(PassCars& other);

	friend std::istream& operator>>(std::istream& in, PassCars& obj);
	friend std::ostream& operator<<(std::ostream& out, PassCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, PassCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, PassCars& obj);

	void virtual PrintTableHead();  //вывод шапки таблицы
	void SubMenu(Tree<PassCars> obj); //меню фильтра
	void SetFieldValue(); //изменение значений полей
	int SortData(); //меню сортировки
};
