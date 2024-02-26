#include "ContainerException.h"

ContainerException::ContainerException(const char* type, const char* name) : ExceptionType(type)
{
	strcpy_s(exceptionContainerName, name);
}

ContainerException::~ContainerException() //����������� � ����������
{}

void ContainerException::ShowError() //����� ������ �� �����
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << exceptionType << std::endl;
	std::cout << exceptionContainerName << std::endl;
	SetConsoleTextAttribute(hConsole, TEXT_COLOUR);
}