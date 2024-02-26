#pragma once
#include "ExceptionType.h"

class InputException : public ExceptionType            //����� ������ �����
{
private:
	char exceptionInputName[BASE_LEN] = "";            //��������� ����� ������ ��������� ������ 

public:
	InputException(const char* type, const char* name);
	~InputException();
	void ShowError();                                  //����� ������

};


int InputInt(int min = 0, int max = 1000000);            //���� ����
double InputDouble(double min = 0.0, double max = 1000000000.0);  //���� ������������� �����
char* InputCyrillicString();                                   //���� ���������
char* InputLatinicString();                                    //���� ��������

std::string ConvertIntToString(int num);    //������ �������� ����� � ������
std::string ConvertDblToString(double num);
