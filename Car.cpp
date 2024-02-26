#include "Car.h"

std::istream& operator>>(std::istream& in, Car& obj) //���������� ���������� �����
{
	std::cout << "������� ������ ���������� : " << std::endl;
	strcpy_s(obj.carModel, InputLatinicString());
	std::cout << "������� �������� ���������(���/�) : " << std::endl;
	obj.enginePower = InputDouble(1);
	std::cout << "������� ��� ������(�) : " << std::endl;
	obj.weight = InputDouble(0.5);
	return in;
}

std::ostream& operator<<(std::ostream& out, Car& obj)
{
	out << "|" << std::left << std::setw(17) << obj.carModel << "|" << std::setw(33) << obj.enginePower << "|" << std::setw(14) << obj.weight;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, Car& obj)
{
	out << obj.carModel << '|' << obj.enginePower << ' ' << obj.weight << ' ';
	return out;
}

std::ifstream& operator>>(std::ifstream& in, Car& obj)
{
	in.getline(obj.carModel, BASE_LEN, '|');
	in >> obj.enginePower;
	in >> obj.weight;
	return in;
}

Car::Car() : carModel(""), enginePower(0.0), weight(0.0), compareParam(0)
{}

Car::Car(Car & obj) //������������ �����������
{
	strcpy_s(carModel, obj.carModel);
	enginePower = obj.enginePower;
	weight = obj.weight;
	compareParam = obj.compareParam;
}

void Car::SetCompareParam(int otherParam) //���������� ��������
{
	compareParam = otherParam;
}

void Car::SetCarModel(const char* newModel)
{
	strcpy_s(carModel, newModel);
}

void Car::SetEnginePower(double power)
{
	enginePower = power;
}

void Car::SetWeight(double newWeight)
{
	weight = newWeight;
}

const char* Car::GetCarModel() //�������� ��������
{
	return carModel;
}

double Car::GetEnginePower()
{
	return enginePower;
}

double Car::GetWeight()
{
	return weight;
}

Car& Car::operator=(Car& obj) //�������� ������������
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
	}
	return *this;
}

void Car::PrintTableHead() //����� ����� �������
{
	std::cout << std::right << std::setfill('_') << std::setw(15) << " ������ " << std::setw(34) << " �������� ���������(���/�) " << std::setw(15) << " ���(�) ";
}

void PrintMenuPunct(const char* text)       //����� ������ ���������� ������ ��� �������������� ����
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, BACKGROUND_BLUE | TEXT_COLOUR); //��������� ���� ���� �� �������
	std::cout << text << std::endl;
	SetConsoleTextAttribute(hStdOut, TEXT_COLOUR);                   //���������� ����� � ������ ����
}
