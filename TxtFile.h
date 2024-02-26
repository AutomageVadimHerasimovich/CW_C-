#pragma once
#include "File.h"

class TxtFile : public File  //класс работы с текстовыми файлами
{
public:
	void OpenTxtFileOut(std::string fileName); //открыть файл для записи
	void OpenTxtFileIn(std::string fileName); //открыть для чтения
	void CloseTxtFileOut(); //закрыть записывающий
	void CloseTxtFileIn(); //закрыть читающий
	bool IsEof(); //проверить не конец ли файла
	bool IsOpen(); // проверить открыт ли файл

	template<typename Type>
	void OutputTxtFile(Type& obj); //запись в файл
	template<typename Type>
	void InputTxtFile(Type& obj); //чтение из файла
};


template<typename Type>
void TxtFile::OutputTxtFile(Type& obj) //вывод в файл
{
	ofStream << obj;
}

template<typename Type>
void TxtFile::InputTxtFile(Type& obj) //ввод из файла
{
	ifStream >> obj;
}
