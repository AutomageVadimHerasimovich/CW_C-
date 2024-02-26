#include "Cabriolet.h"

std::istream& operator>>(std::istream& in, Cabriolet& obj) //перегрузка операторов
{
	int roofType;
	in >> dynamic_cast<RentCars&>(obj);
	std::cout << "Выберете тип крыши в кабриолете : " << std::endl;
	std::cout << "1.Складная\n2.Крыша отсутствует полностью" << std::endl;
	roofType = InputInt(1, 2);
	if (roofType == 1) obj.isRoof = true;
	else obj.isRoof = false;
	return in;
}

std::ostream& operator<<(std::ostream& out, Cabriolet& obj)
{
	out << dynamic_cast<RentCars&>(obj);
	out << "|" << std::setw(24) << (obj.isRoof ? "Есть" : "Нет") << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(117) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, Cabriolet& obj)
{
	out << dynamic_cast<RentCars&>(obj);
	out << obj.isRoof << std::endl;
	return out;	
}

std::ifstream& operator>>(std::ifstream& in, Cabriolet& obj)
{
	in >> dynamic_cast<RentCars&>(obj);
	in >> obj.isRoof;
	in.get();
	return in;
}


void Cabriolet::SetIsRoof(bool roof) //ихменение значения
{
	isRoof = roof;
}
 
const char* Cabriolet::GetIsRoof() //получение значения
{
	return isRoof ? "Есть складная крыша\n" : "Крыша отсутствует\n";
}

Cabriolet::Cabriolet(Cabriolet& obj) : RentCars(obj) //конструктор копирования
{
	isRoof = obj.isRoof;
}

Cabriolet& Cabriolet::operator=(Cabriolet& obj) //оператор присваивания
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		rentPrice = obj.rentPrice;
		isRoof = obj.isRoof;
		compareParam = obj.compareParam;
	}
	return *this;
}

bool Cabriolet::operator==(Cabriolet& other) //перегрузка операторов
{
	if (strcmp(other.carModel, ""))
		if (!(strcmp(carModel, other.carModel) == 0)) return false;

	if (other.enginePower > 0)
		if (enginePower != other.enginePower) return false;

	if (other.weight > 0)
		if (weight != other.weight) return false;

	if (other.rentPrice > 0)
		if (rentPrice != other.rentPrice) return false;
	return true;
}

bool Cabriolet::operator!=(Cabriolet& other)
{
	return !(*this == other);
}

bool Cabriolet::operator>(Cabriolet& other)
{
	if (compareParam == 0)
		return strcmp(carModel, other.carModel) > 0;
	if (compareParam == 1)
		return enginePower > other.enginePower;
	if (compareParam == 2)
		return weight > other.weight;
	if (compareParam == 3)
		return rentPrice > other.rentPrice;
	return false;
}

bool Cabriolet::operator<(Cabriolet& other)
{
	if (compareParam == 0)
		return strcmp(carModel, other.carModel) <= 0;
	if (compareParam == 1)
		return enginePower < other.enginePower;
	if (compareParam == 2)
		return weight < other.weight;
	if (compareParam == 3)
		return rentPrice < other.rentPrice;
	return false;
}

void Cabriolet::PrintTableHead() //вывод шапки таблицы
{
	RentCars::PrintTableHead();
	std::cout << std::setw(22) << " Наличие крыши " << std::setw(8) << "\n";
	std::cout << std::setfill(' ') << std::left;
}



void Cabriolet::SubMenu(Tree<Cabriolet> obj) //меню фильтра
{
	double doubleNum;
	char buf[BASE_LEN];
	Cabriolet varNode;
	Tree<Cabriolet> newTree;
	while (true)
	{
		int modeSelector = 1;
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
			else if (obj.GetRoot())
			{
				varNode.PrintTableHead();
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("Модель автомобиля");
			else std::cout << "Модель автомобиля" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Мощность двигателя");
			else std::cout << "Мощность двигателя" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("Вес");
			else std::cout << "Вес" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("Цена аренды");
			else std::cout << "Цена аренды" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 4) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
			std::cout << "Введите модель автомобиля" << std::endl;
			strcpy_s(buf, InputLatinicString());                     //ввод искомого ФИО
			varNode.SetCarModel(buf);
			break;
		case 2:
			std::cout << "Введите мощность двигателя(кВт/л)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetEnginePower(doubleNum);							  //ввод искомой группы
			break;
		case 3:
			std::cout << "Введите вес автомобиля(т)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetWeight(doubleNum);							  //ввод искомой группы
			break;
		case 4:
			std::cout << "Введите цену аренды автомобиля($/мес)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetRentPrice(doubleNum);							  //ввод искомой группы
			break;
		}
		if (newTree.GetRoot())newTree.ClrTreeRoot(newTree.GetRoot());
		FilterNodes(varNode, obj.Begin(), obj.End(), newTree);               //функция поиска с введенными данными
		if (!(newTree.GetRoot()))
		{
			std::cout << "Ничего не найдено." << std::endl;
			Sleep(2000);
			return;
		}
	}
}

void Cabriolet::SetFieldValue() //изменить опр поле класса
{
	int intNum;
	double doubleNum;
	char buf[BASE_LEN];
	while (true)
	{
		int modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (modeSelector == 1)
				PrintMenuPunct("Модель автомобиля");
			else std::cout << "Модель автомобиля" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Мощность двигателя");
			else std::cout << "Мощность двигателя" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("Вес");
			else std::cout << "Вес" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("Цена аренды");
			else std::cout << "Цена аренды" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("Наличие складной крыши");
			else std::cout << "Наличие складной крыши" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 5) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
			std::cout << "Введите модель автомобиля" << std::endl;
			strcpy_s(buf, InputLatinicString());                     //ввод искомого ФИО
			SetCarModel(buf);
			break;
		case 2:
			std::cout << "Введите мощность двигателя(кВт/л)" << std::endl;
			doubleNum = InputDouble();
			SetEnginePower(doubleNum);							  //ввод искомой группы
			break;
		case 3:
			std::cout << "Введите вес автомобиля(т)" << std::endl;
			doubleNum = InputDouble();
			SetWeight(doubleNum);							  //ввод искомой группы
			break;
		case 4:
			std::cout << "Введите цену аренды автомобиля($/мес)" << std::endl;
			doubleNum = InputDouble();
			SetRentPrice(doubleNum);							  //ввод искомой группы
			break;
		case 5:
			system("cls");
			std::cout << "1.Складная\n2.Крыша отсутствует полностью" << std::endl;
			intNum = InputInt(1, 2);
			SetIsRoof(intNum == 1 ? true : false);				 //ввод искомой группы
			break;
		}
	}
}

int Cabriolet::SortData() //сортировка контейнера
{
	int modeSelector = 1;
	int buttonType = 0;
	while (buttonType != enter)
	{
		system("CLS");
		if (modeSelector == 1)
			PrintMenuPunct("Модель автомобиля");
		else std::cout << "Модель автомобиля" << std::endl;
		if (modeSelector == 2)
			PrintMenuPunct("Мощность двигателя");
		else std::cout << "Мощность двигателя" << std::endl;
		if (modeSelector == 3)
			PrintMenuPunct("Вес");
		else std::cout << "Вес" << std::endl;
		if (modeSelector == 4)
			PrintMenuPunct("Цена аренды");
		else std::cout << "Цена аренды" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 4) modeSelector++;
	}
	return modeSelector;
}
