#pragma once
#include "Node.h"

template <typename Type>    
class Tree //класс контейнера
{
private:
	Node<Type>* root; //главный корень дерева
public:
	class Iterator //вложенный итератор
	{
	private:
		Node<Type>* current;  //указатель на текущий элемент
		Node<Type>* nodeCameFrom; //указатель на предыдущий элемент
	public:
		Iterator(); //конструкторы

		Iterator(Node<Type>* otherTree, Node<Type>* cameFrom = nullptr);

		Type& operator++(int); //перегрузки операторов

		bool operator==(Tree<Type>::Iterator other);
		bool operator!=(Tree<Type>::Iterator other);

		Type& operator*();
	};
	Tree(); //конструктор
	~Tree() //деструктор
	{}

	Iterator Begin(); //методы начала
	Iterator End(); // и конца обхода дерева



	Tree(const Tree& obj); //конструктор копирования и оператор
	Tree<Type>& operator=(Tree<Type>& obj); //присваивания
	Node<Type>* PushNode(Node<Type>* root, Type data, Node<Type>* prev = nullptr);  //добавление узла
	Node<Type>* DeleteNode(Type data);             //удаление узла
	void CallDeleteNode(Type data);			       //вызов метода удаления    		
	void AddNode(Type data);						//метод вызова добавления узла
	void ShowTree(Node<Type>* root);			   //симметричный вывод дерева
	Node<Type>* GetRoot();					       //метод получения корня дерева
	void DeleteTree(Node<Type>* root);			   //очистка всего дерева
	void ClrTreeRoot(Node<Type>* root);             //вызов очистки дерева
	Type* GetRootInfo();                            //получение главного корня
	Node<Type>* GetMinEl(Node<Type>* root);         //нахождение мин. эл-та
};


