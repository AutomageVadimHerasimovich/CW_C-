#pragma once
#include "ExceptionType.h"

class ContainerException : public ExceptionType                          //����� ������ �����
{
private:
	char exceptionContainerName[BASE_LEN] = "";                          //��������� ����� ������ ��������� ������ 

public:
	ContainerException(const char* type, const char* name);
	~ContainerException();
	void ShowError();
};
