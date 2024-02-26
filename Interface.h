#pragma once
#include "PassCars.h"
#include "CargoCars.h"
#include "SportCars.h"
#include "VintageCars.h"
#include "Cabriolet.h"
#include "Limousin.h"
#include "AutoStation.h"
#include "ClientOrders.h"


class Interface                                                //класс интерфейса, содержащий все основные меню
{
public :
	void CallTypeMenu(const char* username);                       //меню выбора типа товара
	void CallModeMenu();                                       //меню регистрации

	template<typename Type>
	void CallAdminMenu(Tree<Type> obj, const char* fileName);  //меню работы для администратора

	template<typename Type>
	void CallUserMenu(Tree<Type> obj, const char* fileName, int objType, const char* username);   //меню работы для пользователя

	void CallAutoStationAdminMenu(Tree<AutoStation> obj);      //меню работы для администратора с автостанцией
	void CallAutoStationUserMenu(Tree<AutoStation> obj);       //меню работы для пользователя с автостанцией
};

void Interface::CallModeMenu()                        //меню регистрации
{
	char login[BASE_LEN], password[BASE_LEN];         //строки для записи из файла в мап
	std::map<std::string, std::string> myMap;		  //использование мапа библиотеки stl
	std::map<std::string, std::string>::iterator it;  //итератор мапа
	std::ifstream ifs("registration.txt");			  //подключение потока файла 
	if (ifs.is_open())
	{
		while (true)                                  //выкачиваем из файла список зарегистрированных пользователей
		{
			ifs.getline(login, BASE_LEN, '|');
			ifs.getline(password, BASE_LEN, '|');
			ifs.get();
			if (ifs.eof()) break;                    //если достигнут конец файла 
			myMap.insert({ login, password });
		}
		ifs.close();
	}
	int modeSelector = 0;                             
	int buttonType = 0;
	while (true)								//реализация интерактивного меню
	{
		int modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (modeSelector == 1)
				PrintMenuPunct("Войти в аккаунт");
			else std::cout << "Войти в аккаунт" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Создать аккаунт");
			else std::cout << "Создать аккаунт" << std::endl;

			rewind(stdin);
			buttonType = _getch();				//отслеживание нажатой кнопки
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 2) modeSelector++;
		}
		system("CLS");
		if (modeSelector == 1)
		{
			try
			{
				std::cout << "Введите логин" << std::endl;  //проверка авторизации пользователя
				strcpy_s(login, InputLatinicString());
				if (myMap.find(login) == myMap.end()) throw ContainerException("", "Такого пользователя не существует");
				std::cout << "Введите пароль" << std::endl;
				strcpy_s(password, InputLatinicString());
				if(myMap.find(login)->second != password) throw ContainerException("", "Неверый пароль");
				std::ofstream ofs("registration.txt");      //занесение обновленных данных в файл
				for (it = myMap.begin(); it != myMap.end(); ++it)
				{
					ofs << it->first << "|" << it->second << "|" << "\n";
				}
				ofs.close();
				CallTypeMenu(login);
			}
			catch(ContainerException obj)
			{
				obj.ShowError();
				Sleep(1000);
				continue;
			}
		}
		else      //добавление нового пользователя
		{
			try
			{
				std::cout << "Введите логин" << std::endl;
				strcpy_s(login, InputLatinicString());
				if (myMap.find(login) != myMap.end()) throw ContainerException("", "Данный пользователь уже существует");
				std::cout << "Введите пароль" << std::endl;
				strcpy_s(password, InputLatinicString());
				myMap[login] = password;
			}
			catch(ContainerException obj)
			{
				obj.ShowError();
				Sleep(1000);
				continue;
			}
		}
	}
}

template<typename Type>
void Interface::CallAdminMenu(Tree<Type> obj, const char* fileName) //меню работы для администратора
{
	int modeSelector;
	Type varNode;
	TxtFile fIn;                            //вывод содержимого из файла
	std::list<Tree<Type>> myList;
	fIn.OpenTxtFileIn(fileName);
	if (fIn.IsOpen())
	{
		while (true)
		{
			fIn.InputTxtFile(varNode);
			if (fIn.IsEof()) break;
			obj.AddNode(varNode);
		}
		fIn.CloseTxtFileIn();
	}
	while (true)
	{
		modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (obj.GetRoot())
			{
				varNode.PrintTableHead();      //вывести данные
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("Добавить элемент контейнера");
			else std::cout << "Добавить элемент контейнера" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Удалить элемент контейнера");
			else std::cout << "Удалить элемент контейнера" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("Отфильтровать контейнер");
			else std::cout << "Отфильтровать контейнер" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("Сортировать данные");
			else std::cout << "Сортировать данные" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("Изменить значение поля");
			else std::cout << "Изменить значение поля" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("Отменить последнее действие");
			else std::cout << "Отменить последнее действие" << std::endl;
			if (modeSelector == 7)
				PrintMenuPunct("Сохранить данные");
			else std::cout << "Сохранить данные" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc)
			{
				obj.ClrTreeRoot(obj.GetRoot());
				return;
			}
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 7) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
		{
			if (obj.GetRoot())
			{
				if (myList.size() == 5)
				{
					myList.pop_back();
				}
				myList.push_front(obj);
			}
			std::cin >> varNode;
			obj.AddNode(varNode);          //добавить узел
			break;
		}
		case 2:
		{
			if (obj.GetRoot())
			{
				if (myList.size() == 5)
				{
					myList.pop_back();
				}
				myList.push_front(obj);
			}
			std::cin >> varNode;
			obj.CallDeleteNode(varNode);   //удалить узел
			break;
		}
		case 3:
		{
			if (obj.GetRoot())
			{
				if (myList.size() == 5)
				{
					myList.pop_back();
				}
				myList.push_front(obj);
			}
			varNode.SubMenu(obj);          //фильтр по контейнеру
			break;
		}
		case 4:
		{
			if (obj.GetRoot())
			{
				if (myList.size() == 5)
				{
					myList.pop_back();
				}
				myList.push_front(obj);
			}
			Sort(obj);                    //сортировка по полю
			break;
		}
		case 5:
		{
			if (obj.GetRoot())
			{
				if (myList.size() == 5)
				{
					myList.pop_back();
				}
				myList.push_front(obj);
			}
			SetOtherField(obj, obj.Begin(), obj.End());           //изменение опр поля объекта
			break;
		}
		case 6:
		{

			if (myList.size() != 0)		//отмена действия
			{
				obj.ClrTreeRoot(obj.GetRoot());
				obj = myList.front();
				myList.pop_front();
			}
			else
			{
				std::cout << "Невозможно отменить дейтсвие" << std::endl;
				Sleep(1000);
			}
			break;
		}
		case 7:
		{
			SaveToFile(obj, fileName);   //сохранить изменения в файл
			break;
		}
		}
	}
}

template<typename Type>
void Interface::CallUserMenu(Tree<Type> obj, const char* fileName, int objType, const char* username) //меню работы пользователя
{
	Type varNode;
	ClientOrders order;
	std::list<ClientOrders> myList;		  //использование листа библиотеки stl
	std::list<ClientOrders>::iterator it;
	TxtFile fIn;                          //вывод содержимого из файла
	fIn.OpenTxtFileIn(fileName);
	if (fIn.IsOpen())
	{
		while (true)
		{
			fIn.InputTxtFile(varNode);
			if (fIn.IsEof()) break;      
			obj.AddNode(varNode);
		}
		fIn.CloseTxtFileIn();
	}
	std::ifstream ifs("orders.txt");			  //подключение потока файла 
	if (ifs.is_open())
	{
		while (true)                                  //выкачиваем из файла список зарегистрированных пользователей
		{
			ifs >> order;
			if (ifs.eof()) break;                    //если достигнут конец файла 
			myList.push_front(order);
		}
		ifs.close();
	}
	while (true)
	{
		int modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (obj.GetRoot())
			{
				varNode.PrintTableHead();      //вывести данные
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("Отфильтровать контейнер");
			else std::cout << "Отфильтровать контейнер" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Сортировать данные");
			else std::cout << "Сортировать данные" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("Оформить заказ");
			else std::cout << "Оформить заказ" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc)
			{
				obj.ClrTreeRoot(obj.GetRoot());
				return;
			}
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 3) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
		{
			varNode.SubMenu(obj);        //фильтр
			break;
		}
		case 2:
		{
			Sort(obj);					 //сортировать по полю
			break;
		}
		case 3:
		{
			typename Tree<Type>::Iterator begin;
			std::cin >> varNode;
			for (begin = obj.Begin(); begin != obj.End(); begin++)
				if (*begin == varNode) break;
			if (begin == obj.End())
			{
				std::cout << "Такого корня не существует" << std::endl;
				Sleep(1000);
				break;
			}
			order.SetCarModel(varNode.GetCarModel());
			order.SetUsername(username);
			order.SetServiceType(objType);
			myList.push_front(order);
			obj.CallDeleteNode(varNode);
			SaveToFile(obj, fileName);
			std::ofstream ofs("orders.txt");      //занесение обновленных данных в файл
			for (it = myList.begin(); it != myList.end(); ++it)
			{
				ofs << *it;
			}
			ofs.close();
		}
		}
	}
}

void Interface::CallTypeMenu(const char* username)  //меню выбора типа товара
{
	bool isOver;         
	while (true)                  //интерактивное меню
	{
		int modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (modeSelector == 1)
				PrintMenuPunct("Купить автомобиль");
			else std::cout << "Купить автомобиль" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Взять автомобиль в аренду");
			else std::cout << "Взять автомобиль в аренду" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("Посмотреть список станций обслуживания");
			else std::cout << "Посмотреть список станций обслуживания" << std::endl;
			if (!strcmp(username, "admin"))
			{
				if (modeSelector == 4)
					PrintMenuPunct("Проверить список заказов");
				else std::cout << "Проверить список заказов" << std::endl;
			}
			rewind(stdin);
			buttonType = _getch();  //проверка нажатой кнопки
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < (strcmp(username, "admin") ? 3 : 4)) modeSelector++;
		}
		if (modeSelector == 1)     //пункт покупки авто
		{
			isOver = false;
			while (!isOver)
			{
				modeSelector = 1;
				buttonType = 0;
				while (buttonType != enter)
				{
					system("CLS");
					if (modeSelector == 1)
						PrintMenuPunct("Пассажирские автомобили");
					else std::cout << "Пассажирские автомобили" << std::endl;
					if (modeSelector == 2)
						PrintMenuPunct("Грузовые автомобили");
					else std::cout << "Грузовые автомобили" << std::endl;
					if (modeSelector == 3)
						PrintMenuPunct("Спортивные автомобили");
					else std::cout << "Спортивные автомобили" << std::endl;
					rewind(stdin);
					buttonType = _getch();  //проверка нажатой кнопки на клавиатуре
					if (buttonType == esc)
					{
						isOver = true;
						break;
					}
					if (buttonType == up && modeSelector > 1) modeSelector--;
					if (buttonType == down && modeSelector < 3) modeSelector++;
				}
				if (isOver) break;
				switch (modeSelector)
				{
				case 1:
				{
					Tree<PassCars> tree;
					if(!strcmp(username, "admin"))  //работа с пассажирскими машинами
						CallAdminMenu(tree, "pass.txt");
					else
						CallUserMenu(tree, "pass.txt", 1, username);
					break;
				}
				case 2:
				{
					Tree<CargoCars> tree;
					if (!strcmp(username, "admin"))  //работа с грузовыми машинами
						CallAdminMenu(tree, "cargo.txt");
					else
						CallUserMenu(tree, "cargo.txt", 1, username);
					break;
				}
				case 3:
				{
					Tree<SportCars> tree;
					if (!strcmp(username, "admin"))  //работа со спортивными машинами
						CallAdminMenu(tree, "sport.txt");
					else
						CallUserMenu(tree, "sport.txt", 1, username);
					break;
				}
				}
			}
		}
		else if(modeSelector == 2)      //работа с арендой авто
		{
			isOver = false;
			while (!isOver)
			{

				modeSelector = 1;
				buttonType = 0;
				while (buttonType != enter)
				{
					system("CLS");
					if (modeSelector == 1) 
						PrintMenuPunct("Винтажные автомобили");
					else std::cout << "Винтажные автомобили" << std::endl;
					if (modeSelector == 2) 
						PrintMenuPunct("Лимузины");
					else std::cout << "Лимузины" << std::endl;
					if (modeSelector == 3)
						PrintMenuPunct("Кабриолеты");
					else std::cout << "Кабриолеты" << std::endl;
					rewind(stdin);
					buttonType = _getch(); //проверка нажатой кнопки
					if (buttonType == esc)
					{
						isOver = true;
						break;
					}
					if (buttonType == up && modeSelector > 1) modeSelector--;
					if (buttonType == down && modeSelector < 3) modeSelector++;
				}
				if (isOver) break;
				switch (modeSelector)
				{
				case 1:
				{
					Tree<VintageCars> tree;
					if (!strcmp(username, "admin")) //работа с винтажными машинами
						CallAdminMenu(tree, "vintage.txt");
					else
						CallUserMenu(tree, "vintage.txt", 2, username);
					break;
				}
				case 2:
				{
					Tree<Limousin> tree;
					if (!strcmp(username, "admin")) //работа с лимузинами
						CallAdminMenu(tree, "limousin.txt");
					else
						CallUserMenu(tree, "limousin.txt", 2, username);
					break;
				}
				case 3:
				{
					Tree<Cabriolet> tree;
					if (!strcmp(username, "admin")) //работа с кабриолетами
						CallAdminMenu(tree, "cabriolet.txt");
					else
						CallUserMenu(tree, "cabriolet.txt", 2, username);
					break;
				}
				case 4:
				{
					isOver = true;
				}
				}
			}
		}
		else if (modeSelector == 3)
		{
			Tree<AutoStation> tree;
			if (!strcmp(username, "admin")) //работа с меню автостанций
				CallAutoStationAdminMenu(tree);
			else
				CallAutoStationUserMenu(tree);
		}
		else
		{
			system("CLS");
			ClientOrders order;
			std::list<ClientOrders> myList;
			std::list<ClientOrders>::iterator it;
			std::ifstream ifs("orders.txt");			  //подключение потока файла 
			if (ifs.is_open())
			{
				while (true)                        //выкачиваем из файла список зарегистрированных пользователей
				{
					ifs >> order;
					ifs.get();
					if (ifs.eof()) break;
					myList.push_front(order);
				}
				ifs.close();
				order.PrintTableHead();
				for (it = myList.begin(); it != myList.end(); ++it)
				{
					std::cout << *it;
				}
				std::cout << "\nДля продолжения нажмите любую клавишу. . ." << std::endl;
				rewind(stdin);
				int buf = _getch();
			}
			else
			{
				std::cout << "Заказов на данный момент нет" << std::endl;
				Sleep(2000);
			}
		}
	}
}

void Interface::CallAutoStationAdminMenu(Tree<AutoStation> obj)  //меню работы для администратора с автостанцией
{
	int modeSelector;
	AutoStation varNode;
	TxtFile fIn;                                       //чтение из файла
	fIn.OpenTxtFileIn("autostation.txt");
	if (fIn.IsOpen())
	{
		while (true)
		{
			fIn.InputTxtFile(varNode);
			if (fIn.IsEof()) break;                    //если достигнут конец файла 
			obj.AddNode(varNode);
		}
		fIn.CloseTxtFileIn();
	}
	while (true)
	{
		modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (obj.GetRoot())
			{
				varNode.PrintTableHead();      //вывести данные
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("Добавить элемент контейнера");
			else std::cout << "Добавить элемент контейнера" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("Удалить элемент контейнера");
			else std::cout << "Удалить элемент контейнера" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("Сохранить данные");
			else std::cout << "Сохранить данные" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("Изменить значение поля");
			else std::cout << "Изменить значение поля" << std::endl;
			rewind(stdin);
			buttonType = _getch();
			if (buttonType == esc)
			{
				obj.ClrTreeRoot(obj.GetRoot());
				return;
			}
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 4) modeSelector++;
		}
		switch (modeSelector)
		{
		case 1:
		{
			std::cin >> varNode;
			obj.AddNode(varNode);          //добавить узел
			break;
		}
		case 2:
		{
			std::cin >> varNode;
			obj.CallDeleteNode(varNode);   //удалить узел
			break;
		}
		case 3:
		{
			SaveToFile(obj, "autostation.txt"); //сохранить в файл изменения
			break;
		}
		case 4:
			SetOtherField(obj, obj.Begin(), obj.End());           //изменить значение определенного поля
			break;
		}
	}
}

void Interface::CallAutoStationUserMenu(Tree<AutoStation> obj)  //меню работы для администратора с автостанцией
{
	AutoStation varNode;
	TxtFile fIn;                         //чтение из файла
	fIn.OpenTxtFileIn("autostation.txt");
	if (fIn.IsOpen())
	{
		while (true)
		{
			fIn.InputTxtFile(varNode);
			if (fIn.IsEof()) break;     //если достигнут конец файла 
			obj.AddNode(varNode);
		}
		fIn.CloseTxtFileIn();
	}
	system("CLS");
	if (obj.GetRoot())
	{
		varNode.PrintTableHead();      //вывести данные
		obj.ShowTree(obj.GetRoot());
	}
	std::cout << "\nДля продолжения нажмите любую клавишу. . ." << std::endl;
	rewind(stdin);
	int buf = _getch();
}

