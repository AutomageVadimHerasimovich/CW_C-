#include <iostream>
#include <conio.h>
#include "Interface.h"


int main()
{
	SetConsoleCP(1251);                                 //����� ���� ��������� �� windows1251
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //����� ����� ���������� ������ � �������
	SetConsoleTextAttribute(hConsole, TEXT_COLOUR);
	Interface obj;                                      //������ ���������� 
	obj.CallModeMenu();								    //����� ���� �����������
}


