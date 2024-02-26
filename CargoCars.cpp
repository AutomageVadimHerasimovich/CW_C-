#include "CargoCars.h"


std::istream& operator>>(std::istream& in, CargoCars& obj) //���������� ���������� �����
{
	in >> dynamic_cast<CarsForSale&>(obj);
	std::cout << "������� ������������ ����������� ���������� ���(�) : " << std::endl;
	obj.maxLoad = InputDouble(0);
	std::cout << "������� ����� �������(�3) : " << std::endl;
	obj.trailerVolume = InputDouble(0);
	return in;
}

std::ostream& operator<<(std::ostream& out, CargoCars& obj) 
{
	out << dynamic_cast<CarsForSale&>(obj);
	out << "|" << std::setw(36) << obj.maxLoad << "|" << std::setw(22) << obj.trailerVolume << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(151) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, CargoCars& obj)
{
	out << dynamic_cast<CarsForSale&>(obj);
	out << obj.maxLoad << ' ' << obj.trailerVolume << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, CargoCars& obj)
{
	in >> dynamic_cast<CarsForSale&>(obj);
	in >> obj.maxLoad >> obj.trailerVolume;
	in.get();
	return in;
}


void CargoCars::SetMaxLoad(double newMaxLoad) //���������� ��������
{
	maxLoad = newMaxLoad;
}

void CargoCars::SetTrailerVolume(double newVolume) 
{
	trailerVolume = newVolume;
}

double CargoCars::GetMaxLoad() //�������� �������� 
{
	return maxLoad;
}

double CargoCars::GetTrailerVolume()
{
	return trailerVolume;
}

CargoCars::CargoCars(CargoCars& obj) : CarsForSale(obj) //����������� �����������
{
	maxLoad = obj.maxLoad;
	trailerVolume = obj.trailerVolume;
}

CargoCars& CargoCars::operator=(CargoCars& obj) //�������� ������������
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		carPrice = obj.carPrice;
		maxLoad = obj.maxLoad;
		trailerVolume = obj.trailerVolume;
		compareParam = obj.compareParam;
	}
	return *this;
}

bool CargoCars::operator==(CargoCars& other) //���������� ���������� 
{
	if (strcmp(other.carModel, ""))
		if (!(strcmp(carModel, other.carModel) == 0)) return false;

	if (other.enginePower > 0)
		if (enginePower != other.enginePower) return false;

	if (other.weight > 0)
		if (weight != other.weight) return false;

	if (other.carPrice > 0)
		if (carPrice != other.carPrice) return false;

	if (other.maxLoad > 0)
		if (maxLoad != other.maxLoad) return false;

	if (other.trailerVolume > 0)
		if (trailerVolume != other.trailerVolume) return false;

	return true;
}

bool CargoCars::operator!=(CargoCars& other)
{
	return !(*this == other);
}

bool CargoCars::operator>(CargoCars& other)
{
	if (compareParam == 0)
		return strcmp(carModel, other.carModel) > 0;
	if (compareParam == 1)
		return enginePower > other.enginePower;
	if (compareParam == 2)
		return weight > other.weight;
	if (compareParam == 3)
		return carPrice > other.carPrice;
	if (compareParam == 4)
		return maxLoad > other.maxLoad;
	if (compareParam == 5)
		return trailerVolume > other.trailerVolume;
	return false;
}

bool CargoCars::operator<(CargoCars& other)
{
	if (compareParam == 0)
		return strcmp(carModel, other.carModel) <= 0;
	if (compareParam == 1)
		return enginePower < other.enginePower;
	if (compareParam == 2)
		return weight < other.weight;
	if (compareParam == 3)
		return carPrice < other.carPrice;
	if (compareParam == 4)
		return maxLoad < other.maxLoad;
	if (compareParam == 5)
		return trailerVolume < other.trailerVolume;
	return false;
}

void CargoCars::PrintTableHead() //����� ����� �������
{
	CarsForSale::PrintTableHead();
	std::cout << std::setw(37) << " ������������ ����������������(�) " << std::setw(22) << " ����� �������(�3) " << std::setw(4) << "\n";
	std::cout << std::setfill(' ') << std::left;
}

void CargoCars::SubMenu(Tree<CargoCars> obj) //������� �������
{
	int modeSelector;
	double doubleNum;
	char buf[BASE_LEN];
	CargoCars varNode;
	Tree<CargoCars> newTree;
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
				PrintMenuPunct("����");
			else std::cout << "����" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("������������ ����������������");
			else std::cout << "������������ ����������������" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("����� �������");
			else std::cout << "����� �������" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 6) modeSelector++;
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
			std::cout << "������� ��������� ����������($)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetCarPrice(doubleNum);							  //���� ������� ������
			break;
		case 5:
			std::cout << "������� ������������ ����������������(�)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetMaxLoad(doubleNum);							  //���� ������� ������
			break;
		case 6:
			std::cout << "������� ����� �������(�3)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetTrailerVolume(doubleNum);							  //���� ������� ������
			break;
		}
		if (newTree.GetRoot())newTree.ClrTreeRoot(newTree.GetRoot());
		FilterNodes(varNode, obj.Begin(), obj.End(), newTree);               //������� ������ � ���������� �������
		if (!(newTree.GetRoot()))
		{
			std::cout << "������ �� �������." << std::endl;
			Sleep(2000);
			return;
		}
	}
}

void CargoCars::SetFieldValue() //�������� �������� ����
{ 
	int modeSelector;
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
				PrintMenuPunct("����");
			else std::cout << "����" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("������������ ����������������");
			else std::cout << "������������ ����������������" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("����� �������");
			else std::cout << "����� �������" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 6) modeSelector++;
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
			std::cout << "������� ��������� ����������($)" << std::endl;
			doubleNum = InputDouble();
			SetCarPrice(doubleNum);							  //���� ������� ������
			break;
		case 5:
			std::cout << "������� ������������ ����������������(�)" << std::endl;
			doubleNum = InputDouble();
			SetMaxLoad(doubleNum);							  //���� ������� ������
			break;
		case 6:
			std::cout << "������� ����� �������(�3)" << std::endl;
			doubleNum = InputDouble();
			SetTrailerVolume(doubleNum);							  //���� ������� ������
			break;
		}
	}
}

int CargoCars::SortData() //����������� ���������
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
			PrintMenuPunct("����");
		else std::cout << "����" << std::endl;
		if (modeSelector == 5)
			PrintMenuPunct("������������ ����������������");
		else std::cout << "������������ ����������������" << std::endl;
		if (modeSelector == 6)
			PrintMenuPunct("����� �������");
		else std::cout << "����� �������" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 6) modeSelector++;
	}
	return modeSelector;
}
