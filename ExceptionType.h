#pragma once
#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <windows.h>
#define BASE_LEN 80  //����������� ����� ������
#define TEXT_COLOUR  FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN //����������� ���� ������

class ExceptionType                           //������� ����� ������
{
protected:
	char exceptionType[BASE_LEN] = "";        //��� ������ 
public:
	ExceptionType(const char* type);          //�����������
	~ExceptionType();                         //� ����������
	virtual void ShowError() = 0;             //��������� ����������� 
};