#include "ExceptionType.h"

ExceptionType::ExceptionType(const char* type)         //�����������
{
	strcpy_s(exceptionType, type);					   //��������� �����������
}

ExceptionType::~ExceptionType()                        //� ����������
{}

void ExceptionType::ShowError()                         //��������� ����������� ����� ������
{}