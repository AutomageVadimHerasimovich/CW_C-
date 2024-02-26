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
#define BASE_LEN 80  //стандартная длина строки
#define TEXT_COLOUR  FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN //стандартный цвет текста

class ExceptionType                           //базовый класс ошибок
{
protected:
	char exceptionType[BASE_LEN] = "";        //тип ошибки 
public:
	ExceptionType(const char* type);          //конструктор
	~ExceptionType();                         //и деструктор
	virtual void ShowError() = 0;             //абсолютно виртуальная 
};