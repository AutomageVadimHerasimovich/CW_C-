#pragma once
#include "ExceptionType.h"

class InputException : public ExceptionType            //класс ошибок ввода
{
private:
	char exceptionInputName[BASE_LEN] = "";            //Сообщение чтобы помочь исправить ошибку 

public:
	InputException(const char* type, const char* name);
	~InputException();
	void ShowError();                                  //вывод ошибки

};


int InputInt(int min = 0, int max = 1000000);            //ввод инта
double InputDouble(double min = 0.0, double max = 1000000000.0);  //ввод вещественного числа
char* InputCyrillicString();                                   //ввод кириллицы
char* InputLatinicString();                                    //ввод латиницы

std::string ConvertIntToString(int num);    //методы перевода числа в строку
std::string ConvertDblToString(double num);
