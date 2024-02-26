#pragma once
#include "CarsForSale.h"

class CargoCars : public CarsForSale //класс грузовых машин
{
private:
	double maxLoad;     //грузоподъемность
	double trailerVolume; //объем прицепа
public:
	CargoCars() : CarsForSale(), maxLoad(0.0), trailerVolume(0.0)
	{}
	~CargoCars() //деструктор
	{}

	void SetMaxLoad(double newMaxLoad);  //методы изменения
	void SetTrailerVolume(double newVolume);

	double GetMaxLoad();       //и получения полей
	double GetTrailerVolume();

	CargoCars(CargoCars& other); //конструктор копирования
	CargoCars& operator=(CargoCars& obj); //оператор присваивания

	bool operator==(CargoCars& other); //перегрузка операторов
	bool operator!=(CargoCars& other);
	bool operator>(CargoCars& other);
	bool operator<(CargoCars& other);

	friend std::istream& operator>>(std::istream& in, CargoCars& obj);
	friend std::ostream& operator<<(std::ostream& out, CargoCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, CargoCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, CargoCars& obj);

	void virtual PrintTableHead(); //вывод шапки таблицы
	void SubMenu(Tree<CargoCars> obj); //меню фильтра
	void SetFieldValue();       //изменение значение опр поля
	int SortData(); //сортировка контейнера
};