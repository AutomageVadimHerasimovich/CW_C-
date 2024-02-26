#include "Limousin.h"


std::istream& operator>>(std::istream& in, Limousin& obj) //���������� ���������� �����
{
	in >> dynamic_cast<RentCars&>(obj);
	std::cout << "������� ����� ������������ ���� : " << std::endl;
	obj.seatsNumber = InputInt(1, 15);
	return in;
}

std::ostream& operator<<(std::ostream& out, Limousin& obj)
{
	out << dynamic_cast<RentCars&>(obj);
	out << "|" << std::setw(22) << obj.seatsNumber << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(115) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, Limousin& obj)
{
	out << dynamic_cast<RentCars&>(obj);
	out << obj.seatsNumber << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Limousin& obj)
{
	in >> dynamic_cast<RentCars&>(obj);
	in >> obj.seatsNumber;
	in.get();
	return in;
}

void Limousin::SetSeatsNumber(int newNum) //�������� ��������
{
	seatsNumber = newNum;
}

int Limousin::GetSeatsNumber() //�������� ��������
{
	return seatsNumber;
}

Limousin::Limousin(Limousin& obj) : RentCars(obj) //����������� �����������
{
	seatsNumber = obj.seatsNumber;
}

Limousin& Limousin::operator=(Limousin& obj) //�������� ������������
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		rentPrice = obj.rentPrice;
		seatsNumber = obj.seatsNumber;
		compareParam = obj.compareParam;
	}
	return *this;
}

bool Limousin::operator==(Limousin& other) //���������� ����������
{
	if (strcmp(other.carModel, ""))
		if (!(strcmp(carModel, other.carModel) == 0)) return false;

	if (other.enginePower > 0)
		if (enginePower != other.enginePower) return false;

	if (other.weight > 0)
		if (weight != other.weight) return false;

	if (other.rentPrice > 0)
		if (rentPrice != other.rentPrice) return false;

	if (other.seatsNumber > 0)
		if (seatsNumber != other.seatsNumber) return false;
	return true;
}

bool Limousin::operator!=(Limousin& other) 
{
	return !(*this == other);
}

bool Limousin::operator>(Limousin& other)
{
	if (compareParam == 0)
		return strcmp(carModel, other.carModel) > 0;
	if (compareParam == 1)
		return enginePower > other.enginePower;
	if (compareParam == 2)
		return weight > other.weight;
	if (compareParam == 3)
		return rentPrice > other.rentPrice;
	if (compareParam == 4)
		return seatsNumber > other.seatsNumber;
	return false;
}

bool Limousin::operator<(Limousin& other)
{
	if (compareParam == 0)
		return strcmp(carModel, other.carModel) <= 0;
	if (compareParam == 1)
		return enginePower < other.enginePower;
	if (compareParam == 2)
		return weight < other.weight;
	if (compareParam == 3)
		return rentPrice < other.rentPrice;
	if (compareParam == 4)
		return seatsNumber < other.seatsNumber;
	return false;
}

void Limousin::PrintTableHead() //����� ����� �������
{
	RentCars::PrintTableHead();
	std::cout << std::setw(20) << " ���-�� ���� " << std::setw(8) << "\n";
	std::cout << std::setfill(' ') << std::left;
}



void Limousin::SubMenu(Tree<Limousin> obj) //������ ����������
{
	int intNum, modeSelector;
	double doubleNum;
	char buf[BASE_LEN];
	Limousin varNode;
	Tree<Limousin> newTree;
	while (true)
	{
		modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (newTree.GetRoot())
			{
				varNode.PrintTableHead();
				newTree.ShowTree(newTree.GetRoot());
			}
			else if (obj.GetRoot())
			{
				varNode.PrintTableHead();
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("������ ����������");
			else std::cout << "������ ����������" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("�������� ���������");
			else std::cout << "�������� ���������" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("���");
			else std::cout << "���" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("���� ������");
			else std::cout << "���� ������" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("����� ������������ ����");
			else std::cout << "����� ������������ ����" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 5) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
			std::cout << "������� ������ ����������" << std::endl;
			strcpy_s(buf, InputLatinicString());                     //���� �������� ���
			varNode.SetCarModel(buf);
			break;
		case 2:
			std::cout << "������� �������� ���������(���/�)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetEnginePower(doubleNum);							  //���� ������� ������
			break;
		case 3:
			std::cout << "������� ��� ����������(�)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetWeight(doubleNum);							  //���� ������� ������
			break;
		case 4:
			std::cout << "������� ���� ������ ����������($/���)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetRentPrice(doubleNum);					      //���� ������� ������
			break;
		case 5:
			std::cout << "������� ����� ������������ ����" << std::endl;
			intNum = InputInt();
			varNode.SetSeatsNumber(intNum);							   //���� ������� ������
			break;
		}
		if (newTree.GetRoot())newTree.ClrTreeRoot(newTree.GetRoot());
		FilterNodes(varNode, obj.Begin(), obj.End(), newTree);                 //������� ������ � ���������� �������
		if (!(newTree.GetRoot()))
		{
			std::cout << "������ �� �������." << std::endl;
			Sleep(2000);
			return;
		}
	}
}

void Limousin::SetFieldValue() //�������� ���� ����������
{
	int intNum, modeSelector;
	double doubleNum;
	char buf[BASE_LEN];
	while (true)
	{
		modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (modeSelector == 1)
				PrintMenuPunct("������ ����������");
			else std::cout << "������ ����������" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("�������� ���������");
			else std::cout << "�������� ���������" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("���");
			else std::cout << "���" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("���� ������");
			else std::cout << "���� ������" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("����� ������������ ����");
			else std::cout << "����� ������������ ����" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 5) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
			std::cout << "������� ������ ����������" << std::endl;
			strcpy_s(buf, InputLatinicString());                     //���� �������� ���
			SetCarModel(buf);
			break;
		case 2:
			std::cout << "������� �������� ���������(���/�)" << std::endl;
			doubleNum = InputDouble();
			SetEnginePower(doubleNum);							  //���� ������� ������
			break;
		case 3:
			std::cout << "������� ��� ����������(�)" << std::endl;
			doubleNum = InputDouble();
			SetWeight(doubleNum);							  //���� ������� ������
			break;
		case 4:
			std::cout << "������� ���� ������ ����������($/���)" << std::endl;
			doubleNum = InputDouble();
			SetRentPrice(doubleNum);							  //���� ������� ������
			break;
		case 5:
			std::cout << "������� ����� ������������ ����" << std::endl;
			intNum = InputInt();
			SetSeatsNumber(intNum);							   //���� ������� ������
			break;
		}
	}
}

int Limousin::SortData() //���������� ����������
{
	int modeSelector = 1;
	int buttonType = 0;
	while (buttonType != enter)
	{
		system("CLS");
		if (modeSelector == 1)
			PrintMenuPunct("������ ����������");
		else std::cout << "������ ����������" << std::endl;
		if (modeSelector == 2)
			PrintMenuPunct("�������� ���������");
		else std::cout << "�������� ���������" << std::endl;
		if (modeSelector == 3)
			PrintMenuPunct("���");
		else std::cout << "���" << std::endl;
		if (modeSelector == 4)
			PrintMenuPunct("���� ������");
		else std::cout << "���� ������" << std::endl;
		if (modeSelector == 5)
			PrintMenuPunct("����� ������������ ����");
		else std::cout << "����� ������������ ����" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 5) modeSelector++;
	}
	return modeSelector;
}
