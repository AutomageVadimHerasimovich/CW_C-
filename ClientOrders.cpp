#include "ClientOrders.h"

void ClientOrders::SetCarModel(const char* newModel)
{
	strcpy_s(carModel, newModel);
}

void ClientOrders::SetServiceType(int newServiceType)
{
	serviceType = newServiceType;
}

void ClientOrders::SetUsername(const char* newUsername)
{
	strcpy_s(username, newUsername);
}

ClientOrders::ClientOrders(const ClientOrders& obj)
{
	strcpy_s(carModel, obj.carModel);
	serviceType = obj.serviceType;
	strcpy_s(username, obj.username);
}

ClientOrders& ClientOrders::operator=(ClientOrders& obj)
{
	if (this != &obj)
	{
		strcpy_s(carModel, obj.carModel);
		serviceType = obj.serviceType;
		strcpy_s(username, obj.username);
	}
	return *this;
}

void ClientOrders::PrintTableHead()
{
	std::cout << std::right << std::setfill('_') << std::setw(15) << " Модель " 
		<< std::setw(19) << " Тип услуги " << std::setw(20) << " Заказчик " << std::setw(7) << "\n";
}

std::ostream& operator<<(std::ostream& out, ClientOrders& obj)
{
	out  << "|" << std::left << std::setfill(' ') << std::setw(17) << obj.carModel
		<< "|" << std::setw(18) << ((obj.serviceType == 1) ? "Покупка" : "Аренда") << "|" << std::setw(22) << obj.username << "|" << std::endl;
	out << std::setfill('-') << std::right << std::setw(61) << " " << std::setfill(' ');
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& out, ClientOrders& obj)
{
	out << obj.carModel << '|' <<  obj.username << '|' << obj.serviceType << ' ';
	return out;
}

std::ifstream& operator>>(std::ifstream& in, ClientOrders& obj)
{
	in.getline(obj.carModel, BASE_LEN, '|');
	in.getline(obj.username, BASE_LEN, '|');
	in >> obj.serviceType;
	return in;
}
