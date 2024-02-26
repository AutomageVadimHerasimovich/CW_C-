#include "TxtFile.h"

void TxtFile::OpenTxtFileOut(std::string fileName) //������� ��� ������
{
		ofStream.open(fileName);
}

void TxtFile::OpenTxtFileIn(std::string fileName) //������� ��� ������
{
		ifStream.open(fileName);
}

void TxtFile::CloseTxtFileOut() //������� ������������
{
	ofStream.close();
}

void TxtFile::CloseTxtFileIn() //������� ��������
{
	ifStream.close();
}

bool TxtFile::IsEof() //�������� ����� �����
{
	return ifStream.eof();
}

bool TxtFile::IsOpen() //�������� ������ �� ����
{
	return ifStream.is_open();
}

