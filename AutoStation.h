#pragma once
#include "Car.h"

class AutoStation                //����� �����������
{
private:
	char geoLocation[BASE_LEN]; //�����
	double avgCheckPrice;       //������� ���
public:
	AutoStation() : geoLocation(""), avgCheckPrice(0.0)
	{}

	~AutoStation()
	{}

	void SetGeoLocation(const char* newGeo); //����������/�������� ��������
	void SetAvgCheckPrice(double newPrice);

	const char* GetGeoLocation();
	double GetAvgCheckPrice();

	AutoStation(AutoStation& obj);      
	AutoStation& operator=(AutoStation& obj);

	bool operator==(AutoStation& other);    //���������� ����������
	bool operator!=(AutoStation& other);
	bool operator>(AutoStation& other);
	bool operator<(AutoStation& other);

	friend std::istream& operator>>(std::istream& in, AutoStation& obj);
	friend std::ostream& operator<<(std::ostream& out, AutoStation& obj);

	friend std::ofstream& operator<<(std::ofstream& out, AutoStation& obj);
	friend std::ifstream& operator>>(std::ifstream& in, AutoStation& obj);

	void PrintTableHead();  //����� ����� �������
	void SetFieldValue();   //�������� ���� 
};