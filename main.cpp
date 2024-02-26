#include <iostream>
#include <conio.h>
#include "Interface.h"


int main()
{
	SetConsoleCP(1251);                                 //смена типа кодировки на windows1251
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //смена цвета выводимого текста в консоль
	SetConsoleTextAttribute(hConsole, TEXT_COLOUR);
	Interface obj;                                      //объект интерфейса 
	obj.CallModeMenu();								    //вызов меню регистрации
}


