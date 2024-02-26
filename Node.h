#pragma once
#include "Tree.h"

template<typename Type>
class Node      //����� ���� ������
{
public:
	Node* R;      //������ ����
	Node* L;      //����� ����
	Node* prev;   //������������ ������
	Type data;    //������ � ����
	Node(Type* _data = nullptr) : R(nullptr), L(nullptr), prev(nullptr), data(*_data)
	{}
	~Node()   //����������� � ����������
	{}

	Node(Node<Type>& obj); //����������� �����������
	Node<Type>& operator=(Node<Type>& obj); //�������� ������������
};

template<typename Type>
Node<Type>::Node(Node<Type>& obj)  //����������� �����������
{
	R = obj.R;
	L = obj.L;
	prev = obj.prev;
	data = obj.data;
}

template<typename Type>
Node<Type>& Node<Type>::operator=(Node<Type>& obj) //�������� ������������
{
	if (this != &obj)
	{
		R = obj.R;
		L = obj.L;
		prev = obj.prev;
		data = obj.data;
	}
	return *this;
}
