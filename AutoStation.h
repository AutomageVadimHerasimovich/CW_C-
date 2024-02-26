#pragma once
#include "Car.h"

class AutoStation                //класс автостанций
{
private:
	char geoLocation[BASE_LEN]; //адрес
	double avgCheckPrice;       //средний чек
public:
	AutoStation() : geoLocation(""), avgCheckPrice(0.0)
	{}

	~AutoStation()
	{}

	void SetGeoLocation(const char* newGeo); //установить/получить значение
	void SetAvgCheckPrice(double newPrice);

	const char* GetGeoLocation();
	double GetAvgCheckPrice();

	AutoStation(AutoStation& obj);      
	AutoStation& operator=(AutoStation& obj);

	bool operator==(AutoStation& other);    //перегрузка операторов
	bool operator!=(AutoStation& other);
	bool operator>(AutoStation& other);
	bool operator<(AutoStation& other);

	friend std::istream& operator>>(std::istream& in, AutoStation& obj);
	friend std::ostream& operator<<(std::ostream& out, AutoStation& obj);

	friend std::ofstream& operator<<(std::ofstream& out, AutoStation& obj);
	friend std::ifstream& operator>>(std::ifstream& in, AutoStation& obj);

	void PrintTableHead();  //вывод шапки таблицы
	void SetFieldValue();   //изменить поле 
};