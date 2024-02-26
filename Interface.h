#pragma once
#include "PassCars.h"
#include "CargoCars.h"
#include "SportCars.h"
#include "VintageCars.h"
#include "Cabriolet.h"
#include "Limousin.h"
#include "AutoStation.h"
#include "ClientOrders.h"


class Interface                                                //����� ����������, ���������� ��� �������� ����
{
public :
	void CallTypeMenu(const char* username);                       //���� ������ ���� ������
	void CallModeMenu();                                       //���� �����������

	template<typename Type>
	void CallAdminMenu(Tree<Type> obj, const char* fileName);  //���� ������ ��� ��������������

	template<typename Type>
	void CallUserMenu(Tree<Type> obj, const char* fileName, int objType, const char* username);   //���� ������ ��� ������������

	void CallAutoStationAdminMenu(Tree<AutoStation> obj);      //���� ������ ��� �������������� � ������������
	void CallAutoStationUserMenu(Tree<AutoStation> obj);       //���� ������ ��� ������������ � ������������
};

void Interface::CallModeMenu()                        //���� �����������
{
	char login[BASE_LEN], password[BASE_LEN];         //������ ��� ������ �� ����� � ���
	std::map<std::string, std::string> myMap;		  //������������� ���� ���������� stl
	std::map<std::string, std::string>::iterator it;  //�������� ����
	std::ifstream ifs("registration.txt");			  //����������� ������ ����� 
	if (ifs.is_open())
	{
		while (true)                                  //���������� �� ����� ������ ������������������ �������������
		{
			ifs.getline(login, BASE_LEN, '|');
			ifs.getline(password, BASE_LEN, '|');
			ifs.get();
			if (ifs.eof()) break;                    //���� ��������� ����� ����� 
			myMap.insert({ login, password });
		}
		ifs.close();
	}
	int modeSelector = 0;                             
	int buttonType = 0;
	while (true)								//���������� �������������� ����
	{
		int modeSelector = 1;
		int buttonType = 0;
		while (buttonType != enter)
		{
			system("CLS");
			if (modeSelector == 1)
				PrintMenuPunct("����� � �������");
			else std::cout << "����� � �������" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("������� �������");
			else std::cout << "������� �������" << std::endl;

			rewind(stdin);
			buttonType = _getch();				//������������ ������� ������
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < 2) modeSelector++;
		}
		system("CLS");
		if (modeSelector == 1)
		{
			try
			{
				std::cout << "������� �����" << std::endl;  //�������� ����������� ������������
				strcpy_s(login, InputLatinicString());
				if (myMap.find(login) == myMap.end()) throw ContainerException("", "������ ������������ �� ����������");
				std::cout << "������� ������" << std::endl;
				strcpy_s(password, InputLatinicString());
				if(myMap.find(login)->second != password) throw ContainerException("", "������� ������");
				std::ofstream ofs("registration.txt");      //��������� ����������� ������ � ����
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
		else      //���������� ������ ������������
		{
			try
			{
				std::cout << "������� �����" << std::endl;
				strcpy_s(login, InputLatinicString());
				if (myMap.find(login) != myMap.end()) throw ContainerException("", "������ ������������ ��� ����������");
				std::cout << "������� ������" << std::endl;
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
void Interface::CallAdminMenu(Tree<Type> obj, const char* fileName) //���� ������ ��� ��������������
{
	int modeSelector;
	Type varNode;
	TxtFile fIn;                            //����� ����������� �� �����
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
				varNode.PrintTableHead();      //������� ������
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("�������� ������� ����������");
			else std::cout << "�������� ������� ����������" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("������� ������� ����������");
			else std::cout << "������� ������� ����������" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("������������� ���������");
			else std::cout << "������������� ���������" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("����������� ������");
			else std::cout << "����������� ������" << std::endl;
			if (modeSelector == 5)
				PrintMenuPunct("�������� �������� ����");
			else std::cout << "�������� �������� ����" << std::endl;
			if (modeSelector == 6)
				PrintMenuPunct("�������� ��������� ��������");
			else std::cout << "�������� ��������� ��������" << std::endl;
			if (modeSelector == 7)
				PrintMenuPunct("��������� ������");
			else std::cout << "��������� ������" << std::endl;
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
			obj.AddNode(varNode);          //�������� ����
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
			obj.CallDeleteNode(varNode);   //������� ����
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
			varNode.SubMenu(obj);          //������ �� ����������
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
			Sort(obj);                    //���������� �� ����
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
			SetOtherField(obj, obj.Begin(), obj.End());           //��������� ��� ���� �������
			break;
		}
		case 6:
		{

			if (myList.size() != 0)		//������ ��������
			{
				obj.ClrTreeRoot(obj.GetRoot());
				obj = myList.front();
				myList.pop_front();
			}
			else
			{
				std::cout << "���������� �������� ��������" << std::endl;
				Sleep(1000);
			}
			break;
		}
		case 7:
		{
			SaveToFile(obj, fileName);   //��������� ��������� � ����
			break;
		}
		}
	}
}

template<typename Type>
void Interface::CallUserMenu(Tree<Type> obj, const char* fileName, int objType, const char* username) //���� ������ ������������
{
	Type varNode;
	ClientOrders order;
	std::list<ClientOrders> myList;		  //������������� ����� ���������� stl
	std::list<ClientOrders>::iterator it;
	TxtFile fIn;                          //����� ����������� �� �����
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
	std::ifstream ifs("orders.txt");			  //����������� ������ ����� 
	if (ifs.is_open())
	{
		while (true)                                  //���������� �� ����� ������ ������������������ �������������
		{
			ifs >> order;
			if (ifs.eof()) break;                    //���� ��������� ����� ����� 
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
				varNode.PrintTableHead();      //������� ������
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("������������� ���������");
			else std::cout << "������������� ���������" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("����������� ������");
			else std::cout << "����������� ������" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("�������� �����");
			else std::cout << "�������� �����" << std::endl;
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
			varNode.SubMenu(obj);        //������
			break;
		}
		case 2:
		{
			Sort(obj);					 //����������� �� ����
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
				std::cout << "������ ����� �� ����������" << std::endl;
				Sleep(1000);
				break;
			}
			order.SetCarModel(varNode.GetCarModel());
			order.SetUsername(username);
			order.SetServiceType(objType);
			myList.push_front(order);
			obj.CallDeleteNode(varNode);
			SaveToFile(obj, fileName);
			std::ofstream ofs("orders.txt");      //��������� ����������� ������ � ����
			for (it = myList.begin(); it != myList.end(); ++it)
			{
				ofs << *it;
			}
			ofs.close();
		}
		}
	}
}

void Interface::CallTypeMenu(const char* username)  //���� ������ ���� ������
{
	bool isOver;         
	while (true)                  //������������� ����
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
				PrintMenuPunct("����� ���������� � ������");
			else std::cout << "����� ���������� � ������" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("���������� ������ ������� ������������");
			else std::cout << "���������� ������ ������� ������������" << std::endl;
			if (!strcmp(username, "admin"))
			{
				if (modeSelector == 4)
					PrintMenuPunct("��������� ������ �������");
				else std::cout << "��������� ������ �������" << std::endl;
			}
			rewind(stdin);
			buttonType = _getch();  //�������� ������� ������
			if (buttonType == esc) return;
			if (buttonType == up && modeSelector > 1) modeSelector--;
			if (buttonType == down && modeSelector < (strcmp(username, "admin") ? 3 : 4)) modeSelector++;
		}
		if (modeSelector == 1)     //����� ������� ����
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
						PrintMenuPunct("������������ ����������");
					else std::cout << "������������ ����������" << std::endl;
					if (modeSelector == 2)
						PrintMenuPunct("�������� ����������");
					else std::cout << "�������� ����������" << std::endl;
					if (modeSelector == 3)
						PrintMenuPunct("���������� ����������");
					else std::cout << "���������� ����������" << std::endl;
					rewind(stdin);
					buttonType = _getch();  //�������� ������� ������ �� ����������
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
					if(!strcmp(username, "admin"))  //������ � ������������� ��������
						CallAdminMenu(tree, "pass.txt");
					else
						CallUserMenu(tree, "pass.txt", 1, username);
					break;
				}
				case 2:
				{
					Tree<CargoCars> tree;
					if (!strcmp(username, "admin"))  //������ � ��������� ��������
						CallAdminMenu(tree, "cargo.txt");
					else
						CallUserMenu(tree, "cargo.txt", 1, username);
					break;
				}
				case 3:
				{
					Tree<SportCars> tree;
					if (!strcmp(username, "admin"))  //������ �� ����������� ��������
						CallAdminMenu(tree, "sport.txt");
					else
						CallUserMenu(tree, "sport.txt", 1, username);
					break;
				}
				}
			}
		}
		else if(modeSelector == 2)      //������ � ������� ����
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
						PrintMenuPunct("��������� ����������");
					else std::cout << "��������� ����������" << std::endl;
					if (modeSelector == 2) 
						PrintMenuPunct("��������");
					else std::cout << "��������" << std::endl;
					if (modeSelector == 3)
						PrintMenuPunct("����������");
					else std::cout << "����������" << std::endl;
					rewind(stdin);
					buttonType = _getch(); //�������� ������� ������
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
					if (!strcmp(username, "admin")) //������ � ���������� ��������
						CallAdminMenu(tree, "vintage.txt");
					else
						CallUserMenu(tree, "vintage.txt", 2, username);
					break;
				}
				case 2:
				{
					Tree<Limousin> tree;
					if (!strcmp(username, "admin")) //������ � ����������
						CallAdminMenu(tree, "limousin.txt");
					else
						CallUserMenu(tree, "limousin.txt", 2, username);
					break;
				}
				case 3:
				{
					Tree<Cabriolet> tree;
					if (!strcmp(username, "admin")) //������ � ������������
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
			if (!strcmp(username, "admin")) //������ � ���� �����������
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
			std::ifstream ifs("orders.txt");			  //����������� ������ ����� 
			if (ifs.is_open())
			{
				while (true)                        //���������� �� ����� ������ ������������������ �������������
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
				std::cout << "\n��� ����������� ������� ����� �������. . ." << std::endl;
				rewind(stdin);
				int buf = _getch();
			}
			else
			{
				std::cout << "������� �� ������ ������ ���" << std::endl;
				Sleep(2000);
			}
		}
	}
}

void Interface::CallAutoStationAdminMenu(Tree<AutoStation> obj)  //���� ������ ��� �������������� � ������������
{
	int modeSelector;
	AutoStation varNode;
	TxtFile fIn;                                       //������ �� �����
	fIn.OpenTxtFileIn("autostation.txt");
	if (fIn.IsOpen())
	{
		while (true)
		{
			fIn.InputTxtFile(varNode);
			if (fIn.IsEof()) break;                    //���� ��������� ����� ����� 
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
				varNode.PrintTableHead();      //������� ������
				obj.ShowTree(obj.GetRoot());
			}
			if (modeSelector == 1)
				PrintMenuPunct("�������� ������� ����������");
			else std::cout << "�������� ������� ����������" << std::endl;
			if (modeSelector == 2)
				PrintMenuPunct("������� ������� ����������");
			else std::cout << "������� ������� ����������" << std::endl;
			if (modeSelector == 3)
				PrintMenuPunct("��������� ������");
			else std::cout << "��������� ������" << std::endl;
			if (modeSelector == 4)
				PrintMenuPunct("�������� �������� ����");
			else std::cout << "�������� �������� ����" << std::endl;
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
			obj.AddNode(varNode);          //�������� ����
			break;
		}
		case 2:
		{
			std::cin >> varNode;
			obj.CallDeleteNode(varNode);   //������� ����
			break;
		}
		case 3:
		{
			SaveToFile(obj, "autostation.txt"); //��������� � ���� ���������
			break;
		}
		case 4:
			SetOtherField(obj, obj.Begin(), obj.End());           //�������� �������� ������������� ����
			break;
		}
	}
}

void Interface::CallAutoStationUserMenu(Tree<AutoStation> obj)  //���� ������ ��� �������������� � ������������
{
	AutoStation varNode;
	TxtFile fIn;                         //������ �� �����
	fIn.OpenTxtFileIn("autostation.txt");
	if (fIn.IsOpen())
	{
		while (true)
		{
			fIn.InputTxtFile(varNode);
			if (fIn.IsEof()) break;     //���� ��������� ����� ����� 
			obj.AddNode(varNode);
		}
		fIn.CloseTxtFileIn();
	}
	system("CLS");
	if (obj.GetRoot())
	{
		varNode.PrintTableHead();      //������� ������
		obj.ShowTree(obj.GetRoot());
	}
	std::cout << "\n��� ����������� ������� ����� �������. . ." << std::endl;
	rewind(stdin);
	int buf = _getch();
}

