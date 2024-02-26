#include "AutoStation.h"

std::istream& operator>>(std::istream& in, AutoStation& obj) //���������� ����������
{
	std::cout << "������� ������� ��� �� ������� ������������ : " << std::endl;
	obj.avgCheckPrice = InputDouble(1);
	std::cout << "������� ����� ������� ������������ : " << std::endl;
	strcpy_s(obj.geoLocation, InputCyrillicString());
	return in;
}

std::ostream& operator<<(std::ostream& out, AutoStation& obj)
{
	out << "|" << std::left << std::setw(21) << obj.avgCheckPrice << "|" << std::setw(22) << obj.geoLocation << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(47) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, AutoStation& obj)
{
	out << obj.geoLocation << '|' << obj.avgCheckPrice << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, AutoStation& obj)
{
	in.getline(obj.geoLocation, BASE_LEN, '|');
	in >> obj.avgCheckPrice;
	in.get();
	return in;
}

void AutoStation::SetAvgCheckPrice(double newPrice) //��������� ��������
{
	avgCheckPrice = newPrice;
}

void AutoStation::SetGeoLocation(const char* newGeo)
{
	strcpy_s(geoLocation, newGeo);
}

const char* AutoStation::GetGeoLocation() //��������� ��������
{
	return geoLocation;
}

double AutoStation::GetAvgCheckPrice()
{
	return avgCheckPrice;
}

AutoStation::AutoStation(AutoStation& obj) //����������� �����������
{
	strcpy_s(geoLocation, obj.geoLocation);
	avgCheckPrice = obj.avgCheckPrice;
}

AutoStation& AutoStation::operator=(AutoStation& obj) //�������� ������������
{
	if (this != &obj)
	{
		strcpy_s(geoLocation, obj.geoLocation);
		avgCheckPrice = obj.avgCheckPrice;
	}
	return *this;
}

bool AutoStation::operator==(AutoStation& other) //���������� ����������
{
	if (strcmp(other.geoLocation, ""))
		if (!(strcmp(geoLocation, other.geoLocation) == 0)) return false;

	if (other.avgCheckPrice > 0)
		if (avgCheckPrice != other.avgCheckPrice) return false;

	return true;
}

bool AutoStation::operator!=(AutoStation& other)
{
	return !(*this == other);
}

bool AutoStation::operator>(AutoStation& other)
{
	return avgCheckPrice > other.avgCheckPrice;
}

bool AutoStation::operator<(AutoStation& other)
{
	return avgCheckPrice < other.avgCheckPrice;
}

void AutoStation::PrintTableHead() //����� ����� �������
{
	std::cout << std::setfill('_') << std::setw(20) << " ������� ���($) " << std::setw(23) << " �������������� " << std::setw(4) << "\n";
	std::cout << std::setfill(' ') << std::left;
}

void AutoStation::SetFieldValue() //�������� ���� ������
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
				PrintMenuPunct("��������������");
			else std::cout << "��������������" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("������� ���");
			else std::cout << "������� ���" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 2) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
			std::cout << "������� �������������� �������" << std::endl;
			strcpy_s(buf, InputCyrillicString());                     //���� �������� ���
			SetGeoLocation(buf);
			break;
		case 2:
			std::cout << "������� ������� ��� �� �������($)" << std::endl;
			doubleNum = InputDouble();
			SetAvgCheckPrice(doubleNum);							  //���� ������� ������
			break;
		}
	}
}
