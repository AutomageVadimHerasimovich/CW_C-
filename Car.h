#pragma once
#include "Tree.cpp"


class Car                   //������� ����� ����
{
protected:
	char carModel[BASE_LEN]; //������ ����
	double enginePower; //�������� ���������
	double weight;      //���

	int compareParam;   //��� ����������
public:
	Car();   //�����������

	virtual ~Car() //����������� ����������
	{}
	
	void SetCompareParam(int otherParam); //������ ���������
	void SetCarModel(const char* newModel); 
	void SetEnginePower(double power);
	void SetWeight(double newWeight);

	const char* GetCarModel();     //� ��������� ��������
	double GetEnginePower();
	double GetWeight();

	Car(Car& other); //����������� �����������
	Car& operator=(Car& obj); //���������� ����������

	friend std::istream& operator>>(std::istream& in, Car& obj);
	friend std::ostream& operator<<(std::ostream& out, Car& obj);

	friend std::ofstream& operator<<(std::ofstream& out, Car& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Car& obj);

	void virtual PrintTableHead(); //����� ����� �������

};

void PrintMenuPunct(const char* text); //����� �������������� ����