#pragma once
#include "RentCars.h"

class Cabriolet : public RentCars  //класс кабриолета
{
private:
	bool isRoof;                   //наличие складной крыши
public:
	Cabriolet() : RentCars(), isRoof(false)
	{}

	void SetIsRoof(bool roof);    //установить/получить значение

	const char* GetIsRoof();

	Cabriolet(Cabriolet& other);
	Cabriolet& operator=(Cabriolet& obj);

	bool operator==(Cabriolet& other); //перегрузка операторов
	bool operator!=(Cabriolet& other);
	bool operator>(Cabriolet& other);
	bool operator<(Cabriolet& other);

	friend std::istream& operator>>(std::istream& in, Cabriolet& obj);
	friend std::ostream& operator<<(std::ostream& out, Cabriolet& obj);

	friend std::ofstream& operator<<(std::ofstream& out, Cabriolet& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Cabriolet& obj);

	void virtual PrintTableHead();   //шапка таблицы
	void SubMenu(Tree<Cabriolet> obj); //подменю для фильтра
	void SetFieldValue();            //установить значение поля
	int SortData();                  //отсортировать 
};