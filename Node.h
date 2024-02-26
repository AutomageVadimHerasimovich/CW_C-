#pragma once
#include "Tree.h"

template<typename Type>
class Node      //класс узла дерева
{
public:
	Node* R;      //правый лист
	Node* L;      //левый лист
	Node* prev;   //родительский корень
	Type data;    //объект в узле
	Node(Type* _data = nullptr) : R(nullptr), L(nullptr), prev(nullptr), data(*_data)
	{}
	~Node()   //конструктор и деструктор
	{}

	Node(Node<Type>& obj); //конструктор копирования
	Node<Type>& operator=(Node<Type>& obj); //оператор присваивания
};

template<typename Type>
Node<Type>::Node(Node<Type>& obj)  //конструктор копирования
{
	R = obj.R;
	L = obj.L;
	prev = obj.prev;
	data = obj.data;
}

template<typename Type>
Node<Type>& Node<Type>::operator=(Node<Type>& obj) //оператор присваивания
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
