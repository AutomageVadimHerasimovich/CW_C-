#pragma once
#include "Tree.cpp"

class ClientOrders
{
private:
	char carModel[BASE_LEN];
	int serviceType;
	char username[BASE_LEN];
public:

	ClientOrders() : carModel(""), serviceType(0), username("")
	{}
	~ClientOrders()
	{}

	void SetCarModel(const char* newModel); //методы изменения
	void SetServiceType(int newServiceType);
	void SetUsername(const char* newUsername);

	ClientOrders(const ClientOrders& obj); //конструктор копирования
	ClientOrders& operator=(ClientOrders& obj); //перегрузки операторов

	friend std::ostream& operator<<(std::ostream& out, ClientOrders& obj);

	friend std::ofstream& operator<<(std::ofstream& out, ClientOrders& obj);
	friend std::ifstream& operator>>(std::ifstream& in, ClientOrders& obj);

	void PrintTableHead(); //вывод шапки таблицы
};