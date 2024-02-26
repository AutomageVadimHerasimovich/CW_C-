#pragma once
#include "Car.h"

class CarsForSale : public Car //����� ����� ��� �������
{
protected:
	double carPrice;   //���� ����������
public:
	CarsForSale() : Car(), carPrice(0.0) //����������� 
	{} 
	~CarsForSale() //����������
	{}

	void SetCarPrice(double newPrice); //���������� ����

	double GetCarPrice();  //�������� ����

	CarsForSale(CarsForSale& other); //����������� �����������
	CarsForSale& operator=(CarsForSale& obj); //�������� ������������

	friend std::istream& operator>>(std::istream& in, CarsForSale& obj); //���������� ����������
	friend std::ostream& operator<<(std::ostream& out, CarsForSale& obj);

	friend std::ofstream& operator<<(std::ofstream& out, CarsForSale& obj);
	friend std::ifstream& operator>>(std::ifstream& in, CarsForSale& obj);

	void virtual PrintTableHead(); //����� ����� �������
};