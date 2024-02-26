#pragma once
#include "CarsForSale.h"

class CargoCars : public CarsForSale //����� �������� �����
{
private:
	double maxLoad;     //����������������
	double trailerVolume; //����� �������
public:
	CargoCars() : CarsForSale(), maxLoad(0.0), trailerVolume(0.0)
	{}
	~CargoCars() //����������
	{}

	void SetMaxLoad(double newMaxLoad);  //������ ���������
	void SetTrailerVolume(double newVolume);

	double GetMaxLoad();       //� ��������� �����
	double GetTrailerVolume();

	CargoCars(CargoCars& other); //����������� �����������
	CargoCars& operator=(CargoCars& obj); //�������� ������������

	bool operator==(CargoCars& other); //���������� ����������
	bool operator!=(CargoCars& other);
	bool operator>(CargoCars& other);
	bool operator<(CargoCars& other);

	friend std::istream& operator>>(std::istream& in, CargoCars& obj);
	friend std::ostream& operator<<(std::ostream& out, CargoCars& obj);

	friend std::ofstream& operator<<(std::ofstream& out, CargoCars& obj);
	friend std::ifstream& operator>>(std::ifstream& in, CargoCars& obj);

	void virtual PrintTableHead(); //����� ����� �������
	void SubMenu(Tree<CargoCars> obj); //���� �������
	void SetFieldValue();       //��������� �������� ��� ����
	int SortData(); //���������� ����������
};