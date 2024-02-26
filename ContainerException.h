#pragma once
#include "ExceptionType.h"

class ContainerException : public ExceptionType                          //класс ошибок ввода
{
private:
	char exceptionContainerName[BASE_LEN] = "";                          //Сообщение чтобы помочь исправить ошибку 

public:
	ContainerException(const char* type, const char* name);
	~ContainerException();
	void ShowError();
};
