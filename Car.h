#pragma once
#include "Tree.cpp"


class Car                   //базовый класс авто
{
protected:
	char carModel[BASE_LEN]; //модель авто
	double enginePower; //мощность двигателя
	double weight;      //вес

	int compareParam;   //тип сортировки
public:
	Car();   //конструктор

	virtual ~Car() //виртуальный деструктор
	{}
	
	void SetCompareParam(int otherParam); //методы изменения
	void SetCarModel(const char* newModel); 
	void SetEnginePower(double power);
	void SetWeight(double newWeight);

	const char* GetCarModel();     //и получения значений
	double GetEnginePower();
	double GetWeight();

	Car(Car& other); //конструктор копирования
	Car& operator=(Car& obj); //перегрузки операторов

	friend std::istream& operator>>(std::istream& in, Car& obj);
	friend std::ostream& operator<<(std::ostream& out, Car& obj);

	friend std::ofstream& operator<<(std::ofstream& out, Car& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Car& obj);

	void virtual PrintTableHead(); //вывод шапки таблицы

};

void PrintMenuPunct(const char* text); //метод интерактивного меню