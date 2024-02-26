#include "SportCars.h"


std::istream& operator>>(std::istream& in, SportCars& obj) //���������� ���������� �����
{
	in >> dynamic_cast<CarsForSale&>(obj);
	std::cout << "������� ����� ������� �� 100 ��/�(�) : " << std::endl;
	obj.accelTime = InputDouble();
	return in;
}

std::ostream& operator<<(std::ostream& out, SportCars& obj)
{
	out << dynamic_cast<CarsForSale&>(obj);
	out << "|" << std::setw(21) << obj.accelTime << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(113) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, SportCars& obj)
{
	out << dynamic_cast<CarsForSale&>(obj);
	out << obj.accelTime << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, SportCars& obj)
{
	in >> dynamic_cast<CarsForSale&>(obj);
	in >> obj.accelTime;
	in.get();
	return in;
}

void SportCars::SetAccelTime(double newTime) //�������� ����
{
	accelTime = newTime;
}

double SportCars::GetAccelTime() //�������� ����
{
	return accelTime;
}

SportCars::SportCars(SportCars& obj) : CarsForSale(obj)//����������� �����������
{
	accelTime = obj.accelTime;
}

SportCars& SportCars::operator=(SportCars& obj) //�������� �������������
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		carPrice = obj.carPrice;
		accelTime = obj.accelTime;
		compareParam = obj.compareParam;
	}
	return *this;
}

bool SportCars::operator==(SportCars& other) //���������� ����������
{
	if (strcmp(other.carModel, ""))
		if (!(strcmp(carModel, other.carModel) == 0)) return false;

	if (other.enginePower > 0)
		if (enginePower != other.enginePower) return false;

	if (other.weight > 0)
		if (weight != other.weight) return false;

	if (other.carPrice > 0)
		if (carPrice != other.carPrice) return false;

	if (other.accelTime > 0)
		if (accelTime != other.accelTime) return false;

	return true;
}

bool SportCars::operator!=(SportCars& other)
{
	return !(*this == other);
}

bool SportCars::operator>(SportCars& other)
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
		return accelTime > other.accelTime;
	return false;
}

bool SportCars::operator<(SportCars& other)
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
		return accelTime < other.accelTime;
	return false;
}

void SportCars::PrintTableHead() //����� ����� �������
{
	CarsForSale::PrintTableHead();
	std::cout << std::setw(21) << " ����� �������(�) " << std::setw(4) << "\n";
	std::cout << std::setfill(' ') << std::left;
}

void SportCars::SubMenu(Tree<SportCars> obj) //������ ����������
{
	int modeSelector;
	double doubleNum;
	char buf[BASE_LEN];
	SportCars varNode;
	Tree<SportCars> newTree;
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
				PrintMenuPunct("����� ������� �� 100 ��/�");
			else std::cout << "����� ������� �� 100 ��/�" << std::endl;
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
			std::cout << "������� ��������� ����������($)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetCarPrice(doubleNum);							  //���� ������� ������
			break;
		case 5:
			std::cout << "������� ����� ������� �� 100 ��/�(�)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetAccelTime(doubleNum);							  //���� ������� ������
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

void SportCars::SetFieldValue() //�������� ���� ������
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
				PrintMenuPunct("����� ������� �� 100 ��/�");
			else std::cout << "����� ������� �� 100 ��/�" << std::endl;
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
			std::cout << "������� ��������� ����������($)" << std::endl;
			doubleNum = InputDouble();
			SetCarPrice(doubleNum);							  //���� ������� ������
			break;
		case 5:
			std::cout << "������� ����� ������� �� 100 ��/�(�)" << std::endl;
			doubleNum = InputDouble();
			SetAccelTime(doubleNum);							  //���� ������� ������
			break;
		}
	}
}

int SportCars::SortData() //����������� ���������
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
			PrintMenuPunct("����� ������� �� 100 ��/�");
		else std::cout << "����� ������� �� 100 ��/�" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 5) modeSelector++;
	}
	return modeSelector;
}