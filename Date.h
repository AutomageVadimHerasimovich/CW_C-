#pragma once
#include "InputException.h"

struct Date         //����� ����
{
	Date() : day(0), month(0), year(0) //�����������
	{} 
	Date(Date& other); //� ����������
	Date& operator=(Date& other); //�������� ������������

	friend void InputDate(Date& newDate); //���� ����

	friend std::ostream& operator<<(std::ostream& out, Date& someDate);

	friend std::ofstream& operator<<(std::ofstream& out, Date& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Date& obj);

	bool operator==(Date& other); //���������� ����������
	bool operator!=(Date& other);

	bool operator>(Date& other);
	bool operator<(Date& other);

	int GetDay(); //����� ��������� ���

private:
	int day; //����
	int month; //�����
	int year; //���
};

