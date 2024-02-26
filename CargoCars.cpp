#include "CargoCars.h"


std::istream& operator>>(std::istream& in, CargoCars& obj) //перегрузка операторов ввода
{
	in >> dynamic_cast<CarsForSale&>(obj);
	std::cout << "Введите максимальный перевозимый грузовиком вес(т) : " << std::endl;
	obj.maxLoad = InputDouble(0);
	std::cout << "Введите объем прицепа(м3) : " << std::endl;
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


void CargoCars::SetMaxLoad(double newMaxLoad) //установить значение
{
	maxLoad = newMaxLoad;
}

void CargoCars::SetTrailerVolume(double newVolume) 
{
	trailerVolume = newVolume;
}

double CargoCars::GetMaxLoad() //получить значение 
{
	return maxLoad;
}

double CargoCars::GetTrailerVolume()
{
	return trailerVolume;
}

CargoCars::CargoCars(CargoCars& obj) : CarsForSale(obj) //конструктор копирования
{
	maxLoad = obj.maxLoad;
	trailerVolume = obj.trailerVolume;
}

CargoCars& CargoCars::operator=(CargoCars& obj) //оператор присваивания
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

bool CargoCars::operator==(CargoCars& other) //перегрузка операторов 
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

void CargoCars::PrintTableHead() //вывод шапки таблицы
{
	CarsForSale::PrintTableHead();
	std::cout << std::setw(37) << " Максимальная грузоподъемность(т) " << std::setw(22) << " Объём прицепа(м3) " << std::setw(4) << "\n";
	std::cout << std::setfill(' ') << std::left;
}

void CargoCars::SubMenu(Tree<CargoCars> obj) //функция фильтра
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
				PrintMenuPunct("Максимальную грузоподъемность");
			else std::cout << "Максимальную грузоподъемность" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("Объем прицепа");
			else std::cout << "Объем прицепа" << std::endl;
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
			std::cout << "Введите максимальную грузоподъемность(т)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetMaxLoad(doubleNum);							  //ввод искомой группы
			break;
		case 6:
			std::cout << "Введите объем прицепа(м3)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetTrailerVolume(doubleNum);							  //ввод искомой группы
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

void CargoCars::SetFieldValue() //изменить значение поля
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
				PrintMenuPunct("Максимальную грузоподъемность");
			else std::cout << "Максимальную грузоподъемность" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("Объем прицепа");
			else std::cout << "Объем прицепа" << std::endl;
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
			std::cout << "Введите максимальную грузоподъемность(т)" << std::endl;
			doubleNum = InputDouble();
			SetMaxLoad(doubleNum);							  //ввод искомой группы
			break;
		case 6:
			std::cout << "Введите объем прицепа(м3)" << std::endl;
			doubleNum = InputDouble();
			SetTrailerVolume(doubleNum);							  //ввод искомой группы
			break;
		}
	}
}

int CargoCars::SortData() //сортировать контейнер
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
			PrintMenuPunct("Максимальную грузоподъемность");
		else std::cout << "Максимальную грузоподъемность" << std::endl;
		if (modeSelector == 6)
			PrintMenuPunct("Объем прицепа");
		else std::cout << "Объем прицепа" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 6) modeSelector++;
	}
	return modeSelector;
}
