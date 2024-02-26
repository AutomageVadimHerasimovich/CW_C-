#pragma once
#include "InputException.h"

struct Date         //класс даты
{
	Date() : day(0), month(0), year(0) //конструктор
	{} 
	Date(Date& other); //и деструктор
	Date& operator=(Date& other); //оператор присваивания

	friend void InputDate(Date& newDate); //ввод даты

	friend std::ostream& operator<<(std::ostream& out, Date& someDate);

	friend std::ofstream& operator<<(std::ofstream& out, Date& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Date& obj);

	bool operator==(Date& other); //перегрузка операторов
	bool operator!=(Date& other);

	bool operator>(Date& other);
	bool operator<(Date& other);

	int GetDay(); //метод получения дня

private:
	int day; //день
	int month; //месяц
	int year; //год
};

