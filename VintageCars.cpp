#include "VintageCars.h"


std::istream& operator>>(std::istream& in, VintageCars& obj) //перегрузка операторов ввода
{
	in >> dynamic_cast<RentCars&>(obj);
	std::cout << "Введите дату изготовления авто : " << std::endl;
	InputDate(obj.productionDate);
	return in;
}

std::ostream& operator<<(std::ostream& out, VintageCars& obj)
{
	out << dynamic_cast<RentCars&>(obj);
	out << "|" << obj.productionDate << std::right << std::setw(14) << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(116) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, VintageCars& obj)
{
	out << dynamic_cast<RentCars&>(obj);
	out << obj.productionDate << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, VintageCars& obj)
{
	in >> dynamic_cast<RentCars&>(obj);
	in >> obj.productionDate;
	in.get();
	return in;
}

void VintageCars::SetProductionDate(Date anotherDate) //установить поле
{
	productionDate = anotherDate;
}

Date VintageCars::GetProductionDate() //получить поле
{
	return productionDate;
}

VintageCars::VintageCars(VintageCars& obj) : RentCars(obj) //конструктор копирования
{
	productionDate = obj.productionDate;
}

VintageCars& VintageCars::operator=(VintageCars& obj) //перегрузка операторов
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		rentPrice = obj.rentPrice;
		productionDate = obj.productionDate;
		compareParam = obj.compareParam;
	}
	return *this;
}

bool VintageCars::operator==(VintageCars& other)
{
	if (strcmp(other.carModel, ""))
		if (!(strcmp(carModel, other.carModel) == 0)) return false;

	if (other.enginePower > 0)
		if (enginePower != other.enginePower) return false;

	if (other.weight > 0)
		if (weight != other.weight) return false;

	if (other.rentPrice > 0)
		if (rentPrice != other.rentPrice) return false;

	if (other.productionDate.GetDay() > 0)
		if (productionDate != other.productionDate) return false;
	return true;
}

bool VintageCars::operator!=(VintageCars& other)
{
	return !(*this == other);
}

bool VintageCars::operator>(VintageCars& other)
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
		return productionDate > other.productionDate;
	return false;
}

bool VintageCars::operator<(VintageCars& other)
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
		return productionDate < other.productionDate;
	return false;
}

void VintageCars::PrintTableHead() //вывод шапки таблицы
{
	RentCars::PrintTableHead();
	std::cout << std::setw(21) << " Дата выпуска " << std::setw(8) << "\n";
	std::cout << std::setfill(' ') << std::left;
}


void VintageCars::SubMenu(Tree<VintageCars> obj) //меню фильтра
{
	int modeSelector;
	Date newDate;
	double doubleNum;
	char buf[BASE_LEN];
	VintageCars varNode;
	Tree<VintageCars> newTree;
	system("CLS");
	varNode.PrintTableHead();
	obj.ShowTree(obj.GetRoot());
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
				PrintMenuPunct("Дата производства");
			else std::cout << "Дата производства" << std::endl;
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
		case 5:
			std::cout << "Введите дату выпуска автомобиля" << std::endl;
			InputDate(newDate);
			varNode.SetProductionDate(newDate);							  //ввод искомой группы
			break;
		}
		if (newTree.GetRoot())newTree.ClrTreeRoot(newTree.GetRoot());
		FilterNodes(varNode, obj.Begin(), obj.End(), newTree);                 //функция поиска с введенными данными
		if (!(newTree.GetRoot()))
		{
			std::cout << "Ничего не найдено." << std::endl;
			Sleep(2000);
			return;
		}
	}
}

void VintageCars::SetFieldValue() //изменить значение поля класса
{
	Date newDate;
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
				PrintMenuPunct("Дата производства");
			else std::cout << "Дата производства" << std::endl;
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
			std::cout << "Введите дату выпуска автомобиля" << std::endl;
			InputDate(newDate);
			SetProductionDate(newDate);							  //ввод искомой группы
			break;
		}
	}
}


int VintageCars::SortData() //сортировать контейнер
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
			PrintMenuPunct("Дата производства");
		else std::cout << "Дата производства" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 5) modeSelector++;
	}
	return modeSelector;
}

