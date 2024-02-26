#include "TxtFile.h"

void TxtFile::OpenTxtFileOut(std::string fileName) //открыть для записи
{
		ofStream.open(fileName);
}

void TxtFile::OpenTxtFileIn(std::string fileName) //открыть для чтения
{
		ifStream.open(fileName);
}

void TxtFile::CloseTxtFileOut() //закрыть записывающий
{
	ofStream.close();
}

void TxtFile::CloseTxtFileIn() //закрыть читающий
{
	ifStream.close();
}

bool TxtFile::IsEof() //проверка конца файла
{
	return ifStream.eof();
}

bool TxtFile::IsOpen() //проверка открыт ли файл
{
	return ifStream.is_open();
}

