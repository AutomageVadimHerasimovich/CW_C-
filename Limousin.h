#pragma once
#include "RentCars.h"


class Limousin : public RentCars //����� ��������
{
private:

	int seatsNumber;          //����� �������

public:
	Limousin() : RentCars(), seatsNumber(0) //�����������
	{} 
	~Limousin() //����������
	{}

	void SetSeatsNumber(int newNum); //�������� ����� ����

	int GetSeatsNumber();  //������� ����� ����

	Limousin(Limousin& other); //����������� �����������
	Limousin& operator=(Limousin& obj); //�������� ������������

	bool operator==(Limousin& other); //���������� ����������
	bool operator!=(Limousin& other);
	bool operator>(Limousin& other);
	bool operator<(Limousin& other);

	friend std::istream& operator>>(std::istream& in, Limousin& obj);
	friend std::ostream& operator<<(std::ostream& out, Limousin& obj);

	friend std::ofstream& operator<<(std::ofstream& out, Limousin& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Limousin& obj);

	void virtual PrintTableHead(); //����� ����� �������
	void SubMenu(Tree<Limousin> obj); //���� �������
	void SetFieldValue(); //��������� ��� ���� ������
	int SortData(); //���������� ����������
};