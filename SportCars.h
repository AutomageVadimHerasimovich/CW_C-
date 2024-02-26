#pragma once
#include "CarsForSale.h"

class SportCars : public CarsForSale //����� ���������� ����
{
private:
	double accelTime;      //����� �������
public:
	SportCars() : CarsForSale(), accelTime(0.0)
	{}
	~SportCars() //����������� � ����������
	{}

	void SetAccelTime(double newTime); //���������� �����

	double GetAccelTime(); //�������� �����

	SportCars(SportCars& other); //����������� �����������
	SportCars& operator=(SportCars& obj); //���������� ����������

	bool operator==(SportCars& other); 
	bool operator!=(SportCars& other);
	bool operator>(SportCars& other);
	bool operator<(SportCars& other);

	friend std::istream& operator>>(std::istream& in, SportCars& obj);
	friend std::ostream& operator<<(std::ostream& out, SportCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, SportCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, SportCars& obj);

	void virtual PrintTableHead(); //����� ����� �������
	void SubMenu(Tree<SportCars> obj); //���� �������
	void SetFieldValue(); //�������� ��� ���� ������
	int SortData(); //����������� ���������
};


