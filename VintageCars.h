#pragma once
#include "RentCars.h"
#include "Date.h"

class VintageCars : public RentCars //����� ��������� ����
{
private:
	Date productionDate; //���� �������
public:
	VintageCars() : RentCars(), productionDate()
	{}
	~VintageCars() //����������� � ����������
	{}

	void SetProductionDate(Date anotherDate); //���������� ����

	Date GetProductionDate(); //�������� ����

	VintageCars(VintageCars& other); //����������� �����������
	VintageCars& operator=(VintageCars& obj); 

	bool operator==(VintageCars& other); //���������� ����������
	bool operator!=(VintageCars& other);
	bool operator>(VintageCars& other);
	bool operator<(VintageCars& other);

	friend std::istream& operator>>(std::istream& in, VintageCars& obj);
	friend std::ostream& operator<<(std::ostream& out, VintageCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, VintageCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, VintageCars& obj);

	void virtual PrintTableHead(); //����� ����� �������
	void SubMenu(Tree<VintageCars> obj); //���� �������
	void SetFieldValue(); //�������� �������� ���� 
	int SortData(); //����������� ���������
};