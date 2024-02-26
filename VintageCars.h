#pragma once
#include "RentCars.h"
#include "Date.h"

class VintageCars : public RentCars //класс винтажных авто
{
private:
	Date productionDate; //дата выпуска
public:
	VintageCars() : RentCars(), productionDate()
	{}
	~VintageCars() //конструктор и деструктор
	{}

	void SetProductionDate(Date anotherDate); //установить дату

	Date GetProductionDate(); //получить дату

	VintageCars(VintageCars& other); //конструктор копирования
	VintageCars& operator=(VintageCars& obj); 

	bool operator==(VintageCars& other); //перегрузка операторов
	bool operator!=(VintageCars& other);
	bool operator>(VintageCars& other);
	bool operator<(VintageCars& other);

	friend std::istream& operator>>(std::istream& in, VintageCars& obj);
	friend std::ostream& operator<<(std::ostream& out, VintageCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, VintageCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, VintageCars& obj);

	void virtual PrintTableHead(); //вывод шапки таблицы
	void SubMenu(Tree<VintageCars> obj); //меню фильтра
	void SetFieldValue(); //изменить значение поля 
	int SortData(); //сортировать контейнер
};