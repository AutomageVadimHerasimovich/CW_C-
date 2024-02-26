#pragma once
#include "File.h"

class TxtFile : public File  //����� ������ � ���������� �������
{
public:
	void OpenTxtFileOut(std::string fileName); //������� ���� ��� ������
	void OpenTxtFileIn(std::string fileName); //������� ��� ������
	void CloseTxtFileOut(); //������� ������������
	void CloseTxtFileIn(); //������� ��������
	bool IsEof(); //��������� �� ����� �� �����
	bool IsOpen(); // ��������� ������ �� ����

	template<typename Type>
	void OutputTxtFile(Type& obj); //������ � ����
	template<typename Type>
	void InputTxtFile(Type& obj); //������ �� �����
};


template<typename Type>
void TxtFile::OutputTxtFile(Type& obj) //����� � ����
{
	ofStream << obj;
}

template<typename Type>
void TxtFile::InputTxtFile(Type& obj) //���� �� �����
{
	ifStream >> obj;
}
