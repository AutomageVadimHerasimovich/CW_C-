#include "SportCars.h"


std::istream& operator>>(std::istream& in, SportCars& obj) //перегрузка операторов ввода
{
	in >> dynamic_cast<CarsForSale&>(obj);
	std::cout << "Введите время разгона до 100 км/ч(с) : " << std::endl;
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

void SportCars::SetAccelTime(double newTime) //изменить поле
{
	accelTime = newTime;
}

double SportCars::GetAccelTime() //получить поле
{
	return accelTime;
}

SportCars::SportCars(SportCars& obj) : CarsForSale(obj)//конструктор копирования
{
	accelTime = obj.accelTime;
}

SportCars& SportCars::operator=(SportCars& obj) //оператор присванивания
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

bool SportCars::operator==(SportCars& other) //перегрузки операторов
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

void SportCars::PrintTableHead() //вывод шапки таблицы
{
	CarsForSale::PrintTableHead();
	std::cout << std::setw(21) << " Время разгона(с) " << std::setw(4) << "\n";
	std::cout << std::setfill(' ') << std::left;
}

void SportCars::SubMenu(Tree<SportCars> obj) //фильтр контейнера
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
				PrintMenuPunct("Время разгона до 100 км/ч");
			else std::cout << "Время разгона до 100 км/ч" << std::endl;
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
			std::cout << "Введите стоимость автомобиля($)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetCarPrice(doubleNum);							  //ввод искомой группы
			break;
		case 5:
			std::cout << "Введите время разгона до 100 км/ч(с)" << std::endl;
			doubleNum = InputDouble();
			varNode.SetAccelTime(doubleNum);							  //ввод искомой группы
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

void SportCars::SetFieldValue() //изменить поле класса
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
				PrintMenuPunct("Время разгона до 100 км/ч");
			else std::cout << "Время разгона до 100 км/ч" << std::endl;
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
			std::cout << "Введите стоимость автомобиля($)" << std::endl;
			doubleNum = InputDouble();
			SetCarPrice(doubleNum);							  //ввод искомой группы
			break;
		case 5:
			std::cout << "Введите время разгона до 100 км/ч(с)" << std::endl;
			doubleNum = InputDouble();
			SetAccelTime(doubleNum);							  //ввод искомой группы
			break;
		}
	}
}

int SportCars::SortData() //сортировать контейнер
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
			PrintMenuPunct("Время разгона до 100 км/ч");
		else std::cout << "Время разгона до 100 км/ч" << std::endl;
		rewind(stdin);
		buttonType = _getch();
		if (buttonType == esc) return 1;
		if (buttonType == up && modeSelector > 1) modeSelector--;
		if (buttonType == down && modeSelector < 5) modeSelector++;
	}
	return modeSelector;
}