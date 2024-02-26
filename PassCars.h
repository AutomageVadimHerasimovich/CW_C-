#pragma once
#include "CarsForSale.h"

class PassCars : public CarsForSale //����� ������������ ����
{
private:
	int seatsNumber;           //����� �������
	double trunkVolume;        //����� ���������
public:
	PassCars() : CarsForSale(), seatsNumber(0), trunkVolume(-1)
	{}
	~PassCars() //����������� � ����������
	{}
	
	void SetSeatsNumber(int newSeatsNum); //������ ���������
	void SetTrunkVolume(double newVolume);

	int GetSeatsNumber();            //� ��������� ��������
	double GetTrunkVolume();

	PassCars(PassCars& other);      //���������� �����������
	PassCars& operator=(PassCars& obj); //�������� ������������

	bool operator==(PassCars& other); //���������� ����������
	bool operator!=(PassCars& other);
	bool operator>(PassCars& other);
	bool operator<(PassCars& other);

	friend std::istream& operator>>(std::istream& in, PassCars& obj);
	friend std::ostream& operator<<(std::ostream& out, PassCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, PassCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, PassCars& obj);

	void virtual PrintTableHead();  //����� ����� �������
	void SubMenu(Tree<PassCars> obj); //���� �������
	void SetFieldValue(); //��������� �������� �����
	int SortData(); //���� ����������
};
