#pragma once
#include "RentCars.h"

class Cabriolet : public RentCars  //����� ����������
{
private:
	bool isRoof;                   //������� �������� �����
public:
	Cabriolet() : RentCars(), isRoof(false)
	{}

	void SetIsRoof(bool roof);    //����������/�������� ��������

	const char* GetIsRoof();

	Cabriolet(Cabriolet& other);
	Cabriolet& operator=(Cabriolet& obj);

	bool operator==(Cabriolet& other); //���������� ����������
	bool operator!=(Cabriolet& other);
	bool operator>(Cabriolet& other);
	bool operator<(Cabriolet& other);

	friend std::istream& operator>>(std::istream& in, Cabriolet& obj);
	friend std::ostream& operator<<(std::ostream& out, Cabriolet& obj);

	friend std::ofstream& operator<<(std::ofstream& out, Cabriolet& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Cabriolet& obj);

	void virtual PrintTableHead();   //����� �������
	void SubMenu(Tree<Cabriolet> obj); //������� ��� �������
	void SetFieldValue();            //���������� �������� ����
	int SortData();                  //������������� 
};