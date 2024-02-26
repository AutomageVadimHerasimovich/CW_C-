#include "PassCars.h"


std::istream& operator>>(std::istream& in, PassCars& obj) //перегрузка операторов ввода
{
	in >> dynamic_cast<CarsForSale&>(obj);
	std::cout << "Введите число мест в автомобиле : " << std::endl;
	obj.seatsNumber = InputInt(1, 10);
	std::cout << "Введите объем багажника(если багажника нет - введите 0)" << std::endl;	
	obj.trunkVolume = InputDouble(0);
	return in;
	
}

std::ostream& operator<<(std::ostream& out, PassCars& obj)
{
	out << dynamic_cast<CarsForSale&>(obj);
	out << "|" << std::setw(15) << obj.seatsNumber << "|" << std::setw(23) << obj.trunkVolume << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(131) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, PassCars& obj)
{
	out << dynamic_cast<CarsForSale&>(obj);
	out << obj.seatsNumber << ' ' << obj.trunkVolume << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, PassCars& obj)
{
	in >> dynamic_cast<CarsForSale&>(obj);
	in >> obj.seatsNumber >> obj.trunkVolume;
	in.get();
	return in;
}

void PassCars::SetSeatsNumber(int newSeatsNum) //изменить поле
{
	seatsNumber = newSeatsNum;
}

void PassCars::SetTrunkVolume(double newVolume)
{
	trunkVolume = newVolume;
}

int PassCars::GetSeatsNumber()   //получить поле
{
	return seatsNumber;
}

double PassCars::GetTrunkVolume()
{
	return trunkVolume;
}

PassCars::PassCars(PassCars& obj) : CarsForSale(obj) //конструктор копир.
{
	seatsNumber = obj.seatsNumber;
	trunkVolume = obj.trunkVolume;
}

PassCars& PassCars::operator=(PassCars& obj) //перегрузка операторов
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		enginePower = obj.enginePower;
		weight = obj.weight;
		carPrice = obj.carPrice;
		seatsNumber = obj.seatsNumber;
		trunkVolume = obj.trunkVolume;
		compareParam = obj.compareParam;
	}
	return *this;
}

bool PassCars::operator==(PassCars& other)
{
	if (strcmp(other.carModel, ""))
		if (!(strcmp(carModel, other.carModel) == 0)) return false;

	if (other.enginePower > 0)
		if (enginePower != other.enginePower) return false;

	if (other.weight > 0)
		if (weight != other.weight) return false;

	if (other.carPrice > 0)
		if (carPrice != other.carPrice) return false;
	if (other.seatsNumber > 0)
		if (seatsNumber != other.seatsNumber) return false;

	if (other.trunkVolume >= 0)
		if (trunkVolume != other.trunkVolume) return false;

	return true;
}

bool PassCars::operator!=(PassCars& other)
{
	return !(*this == other);
}

bool PassCars::operator>(PassCars& other)
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
		return seatsNumber > other.seatsNumber;
	if (compareParam == 5)
		return trunkVolume > other.trunkVolume;
	return false;
}

bool PassCars::operator<(PassCars& other)
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
		return seatsNumber < other.seatsNumber;
	if (compareParam == 5)
		return trunkVolume < other.trunkVolume;
	return false;
}

void PassCars::PrintTableHead() //вывод шапки таблицы
{
	CarsForSale::PrintTableHead();
	std::cout << std::setw(16) << " Кол-во мест " << std::setw(23) << " Объём багажника(л) " << std::setw(4) << "\n";
	std::cout << std::setfill(' ') << std::left;
}

void PassCars::SubMenu(Tree<PassCars> obj) //меню фильтра
{
	int intNum, modeSelector;
	double doubleNum;
	char buf[BASE_LEN];
	PassCars varNode;
	Tree<PassCars> newTree;
	system("CLS");
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
				PrintMenuPunct("Цена");
			else std::cout << "Цена" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("Число пасс. мест");
			else std::cout << "Число пасс. мест" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("Объем багажника");
			else std::cout << "Объем багажника" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc)
			{
				return;
			}
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 6) modeSelector++;
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
			std::cout << "Введите стоимость автомобиля($)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetCarPrice(doubleNum);							  //ввод искомой группы
			break;
		case 5:
			std::cout << "Введите число пассажирских мест" << std::endl;
			intNum = InputInt();
			varNode.SetSeatsNumber(intNum);							  //ввод искомой группы
			break;
		case 6:
			std::cout << "Введите объем багажника(л)" << std::endl;
			doubleNum = InputDouble(0);
			varNode.SetTrunkVolume(doubleNum);							  //ввод искомой группы
			break;
		}
		if(newTree.GetRoot())newTree.ClrTreeRoot(newTree.GetRoot());
		FilterNodes(varNode, obj.Begin(), obj.End(), newTree);                 //функция поиска с введенными данными
		if (!newTree.GetRoot())
		{
			std::cout << "Ничего не найдено." << std::endl;
			Sleep(2000);
			return;
		}
	}
}

void PassCars::SetFieldValue() //изменить значение поля
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
				PrintMenuPunct("Цена");
			else std::cout << "Цена" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("Число пасс. мест");
			else std::cout << "Число пасс. мест" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("Объем багажника");
			else std::cout << "Объем багажника" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 6) modeSelector++;
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
			std::cout << "Введите стоимость автомобиля($)" << std::endl;
			doubleNum = InputDouble();
			SetCarPrice(doubleNum);							  //ввод искомой группы
			break;
		case 5:
			std::cout << "Введите число пассажирских мест" << std::endl;
			intNum = InputInt();
			SetSeatsNumber(intNum);							  //ввод искомой группы
			break;
		case 6:
			std::cout << "Введите объем багажника(л)" << std::endl;
			doubleNum = InputDouble(0);
			SetTrunkVolume(doubleNum);							  //ввод искомой группы
			break;
		}
	}
}

int PassCars::SortData() //сортировать контейнер
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
			PrintMenuPunct("Цена");
		else std::cout << "Цена" << std::endl;
		if (modeSelector == 5)
			PrintMenuPunct("Число пасс. мест");
		else std::cout << "Число пасс. мест" << std::endl;
		if (modeSelector == 6)
			PrintMenuPunct("Объем багажника");
		else std::cout << "Объем багажника" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 6) modeSelector++;
	}
	return modeSelector;
}

