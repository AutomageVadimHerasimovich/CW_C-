#pragma once
#include "RentCars.h"


class Limousin : public RentCars //класс лимузина
{
private:

	int seatsNumber;          //число сидений

public:
	Limousin() : RentCars(), seatsNumber(0) //конструктор
	{} 
	~Limousin() //деструктор
	{}

	void SetSeatsNumber(int newNum); //получить число мест

	int GetSeatsNumber();  //вернуть число мест

	Limousin(Limousin& other); //конструктор копирования
	Limousin& operator=(Limousin& obj); //оператор присваивания

	bool operator==(Limousin& other); //перегрузка операторов
	bool operator!=(Limousin& other);
	bool operator>(Limousin& other);
	bool operator<(Limousin& other);

	friend std::istream& operator>>(std::istream& in, Limousin& obj);
	friend std::ostream& operator<<(std::ostream& out, Limousin& obj);

	friend std::ofstream& operator<<(std::ofstream& out, Limousin& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Limousin& obj);

	void virtual PrintTableHead(); //вывод шапки таблицы
	void SubMenu(Tree<Limousin> obj); //меню фильтра
	void SetFieldValue(); //изменение опр поля класса
	int SortData(); //сортировка контейнера
};