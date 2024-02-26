#pragma once
#include "InputException.h"
#include "ContainerException.h"
#include "TxtFile.h"
#include "Tree.h"
#include "Algorithm.h"
#include "MenuButtons.h"


template<typename Type>    
Tree<Type>::Tree() : root(nullptr) //конструкторы
{}
template<typename Type>
Tree<Type>::Tree(const Tree<Type>& obj)
{
	this->root = nullptr;
	this->root = Copy(this->root, obj.root);
}



template<typename Type>
Tree<Type>& Tree<Type>::operator=(Tree<Type>& obj) //орпеатор присваивания
{
	if (this != &obj)
	{
		this->root = nullptr;
		this->root = Copy(this->root, obj.root);
	}
	return *this;
}
//добавление узла													
template<typename Type>  //добавление узла
Node<Type>* Tree<Type>::PushNode(Node<Type>* root, Type data, Node<Type>* prev)
{
	if (!root)
	{
		root = new Node<Type>(&data);
		if (!root)
		{
			std::cout << "Memory error";
			exit(1);
		}
		root->data = data;
		root->prev = prev;
	}
	else if (root->data < data)
		root->R = PushNode(root->R, data, root);
	else
		root->L = PushNode(root->L, data, root);
	return root;
}

template<typename Type>
void Tree<Type> :: AddNode(Type data) //вызов добавления узла
{
	root = PushNode(root, data);
}

template<typename Type> //вызов удаления узла
void Tree<Type>::CallDeleteNode(Type data)
{
	root = DeleteNode(data);
}


template<typename Type> 
Node<Type>* Tree<Type> :: GetRoot() //метод получения корня дерева
{
	return root;
}


template<typename Type>
void Tree<Type>::ShowTree(Node<Type>* root) //симетричный обход
{
	if (root)
	{
		this->ShowTree(root->L);
		std::cout << root->data;
		this->ShowTree(root->R);
	}
}


template<typename Type>
Node<Type>* Tree<Type>::DeleteNode(Type data) //удаление корня 
{
	Node<Type>* rootHelper;					  //вспомогательный указатель
	Node<Type>* rootDeleted;				  //удаляемый корень 
	rootDeleted = root->prev = root;
	int isRightRoot = 0;
	if (!root) return nullptr;
	if (root->data == data)
	{
		if (!(root->R) && !(root->L))
		{
			ClrTreeRoot(root);
			return nullptr;
		}
		else if (root->R && root->L)
		{
			rootHelper = rootDeleted->R;
			while (rootHelper->L) rootHelper = rootHelper->L;
			rootHelper->L = rootDeleted->L;
			root = rootDeleted->R;
		}
		else if (root->R)
			root = rootDeleted->R;
		else if (root->L)
			root = rootDeleted->L;
		delete rootDeleted;
		return root;
	}
	do						//цикл нахождения нужного корня
	{
		if (rootDeleted->data < data)
			if (rootDeleted->R)
			{
				root->prev = rootDeleted;
				rootDeleted = rootDeleted->R;
			}
			else isRightRoot = 1;
		if (rootDeleted->data > data)
			if (rootDeleted->L)
			{
				root->prev = rootDeleted;
				rootDeleted = rootDeleted->L;
			}
			else isRightRoot = 1;
		if (rootDeleted->data == data) isRightRoot = 1;			   //корень найден		
	} while (!isRightRoot);

	if (rootDeleted->data != data)						     	   //корень не был найден
	{
		std::cout << "Такого корня не найдено" << std::endl;
		return root;
	}
	rootHelper = rootDeleted;
	if (rootDeleted->data < root->prev->data) //если удаляемый корень находится в левой половине дерева
	{
		if (rootDeleted->R)
		{
			rootHelper = rootDeleted->R;
			while (rootHelper->L) rootHelper = rootHelper->L;
			root->prev->L = rootDeleted->R;
			rootHelper->L = rootDeleted->L;
		}
		else root->prev->L = rootDeleted->L;
	}
	else
	{
		if (rootDeleted->L)			 //если удаляемый корень находится в правой половине дерева
		{
			rootHelper = rootDeleted->L;
			while (rootHelper->R) rootHelper = rootHelper->R;
			root->prev->R = rootDeleted->L;
			rootHelper->R = rootDeleted->R;
		}
		else 
			root->prev->R = rootDeleted->R;
	}
	delete rootDeleted;
	return root;
}



template<typename Type>
void Tree<Type>::DeleteTree(Node<Type>* root) //очистка дерева с определенного узла
{
	if (root->L) DeleteTree(root->L);
	if (root->R) DeleteTree(root->R);
	delete root;
}

template<typename Type>
void Tree<Type>::ClrTreeRoot(Node<Type>* root) //очистить дерево
{
	if (!root) return;
	DeleteTree(root);
	this->root = nullptr;
}

template<typename Type>
Type* Tree<Type>::GetRootInfo() //получить поле
{
	if(root) return &(root->data);
	return nullptr;
}


template<typename Type>
Node<Type>* Tree<Type>::GetMinEl(Node<Type>* root) //получить поле
{
	if (root)
	{
		if (root->L)
			return GetMinEl(root->L);
		else return root;
	}
	return 0;
}

template<typename Type>
Tree<Type>::Iterator::Iterator() //конструкторы итератора
{
	nodeCameFrom = nullptr;
	current = NULL;
}

template<typename Type>
Tree<Type>::Iterator::Iterator(Node<Type>* data, Node<Type>* dataCameFrom)
{
	current = data;
	nodeCameFrom = dataCameFrom;
}

template<typename Type>
Tree<Type>::template Iterator Tree<Type>::Begin() //начало обхода
{
	Iterator it(GetMinEl(root));
	return it;
}

template<typename Type>
Tree<Type>::template Iterator Tree<Type>::End() //конец обхода
{
	return nullptr;
}

template<typename Type>
Type& Tree<Type>::Iterator::operator++(int) //перегрузки операторов
{
		if (!current->R)
		{
			do
			{
				nodeCameFrom = current;
				current = current->prev;
			} while (current && (nodeCameFrom->data > current->data));
		}
		else
		{
			current = current->R;
			while (current->L) current = current->L;
		}
		return current->data;
}

template<typename Type>
bool Tree<Type>::Iterator::operator==(Tree<Type>::Iterator other)
{
	return current == other.current;
}

template<typename Type>
bool Tree<Type>::Iterator::operator!=(Tree<Type>::Iterator other)
{
	return current != other.current;
}

template<typename Type>
Type& Tree<Type>::Iterator::operator*()
{
	return current->data;
}




