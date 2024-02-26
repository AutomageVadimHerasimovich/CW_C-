#pragma once
#include "Node.h"

template <typename Type>    
class Tree //����� ����������
{
private:
	Node<Type>* root; //������� ������ ������
public:
	class Iterator //��������� ��������
	{
	private:
		Node<Type>* current;  //��������� �� ������� �������
		Node<Type>* nodeCameFrom; //��������� �� ���������� �������
	public:
		Iterator(); //������������

		Iterator(Node<Type>* otherTree, Node<Type>* cameFrom = nullptr);

		Type& operator++(int); //���������� ����������

		bool operator==(Tree<Type>::Iterator other);
		bool operator!=(Tree<Type>::Iterator other);

		Type& operator*();
	};
	Tree(); //�����������
	~Tree() //����������
	{}

	Iterator Begin(); //������ ������
	Iterator End(); // � ����� ������ ������



	Tree(const Tree& obj); //����������� ����������� � ��������
	Tree<Type>& operator=(Tree<Type>& obj); //������������
	Node<Type>* PushNode(Node<Type>* root, Type data, Node<Type>* prev = nullptr);  //���������� ����
	Node<Type>* DeleteNode(Type data);             //�������� ����
	void CallDeleteNode(Type data);			       //����� ������ ��������    		
	void AddNode(Type data);						//����� ������ ���������� ����
	void ShowTree(Node<Type>* root);			   //������������ ����� ������
	Node<Type>* GetRoot();					       //����� ��������� ����� ������
	void DeleteTree(Node<Type>* root);			   //������� ����� ������
	void ClrTreeRoot(Node<Type>* root);             //����� ������� ������
	Type* GetRootInfo();                            //��������� �������� �����
	Node<Type>* GetMinEl(Node<Type>* root);         //���������� ���. ��-��
};


