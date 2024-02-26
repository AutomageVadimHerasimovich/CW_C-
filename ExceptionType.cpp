#include "ExceptionType.h"

ExceptionType::ExceptionType(const char* type)         //конструктор
{
	strcpy_s(exceptionType, type);					   //абсолютно виртуальная
}

ExceptionType::~ExceptionType()                        //и деструктор
{}

void ExceptionType::ShowError()                         //абсолютно виртуальный метод вывода
{}