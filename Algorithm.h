#pragma once
#include "Tree.h"

template<typename Type>
Node<Type>* Copy(Node<Type>* node, Node<Type>* other, Node<Type>* previous = nullptr);  // ����������� ������

template <typename Type>    //������ ���������� 
void FilterNodes(Type data, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree);

template <typename Type>
void Sort(Tree<Type>& obj);  //���������� �� ��� ����

template <typename Type>    //��������� ��������� � ����
void SaveToFile(Tree<Type> obj, const char* filename);

template <typename Type>    //�������� ��� ����
void SetOtherField(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end);

template<typename Type>		//����������� ����������
void CopyTree(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree);


template<typename Type>   //������ ���������� 
void FilterNodes(Type data, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree)
{
	while (begin != end)
	{
		if (*begin == data) newTree.AddNode(*begin);
		begin++;
	}
}

template<typename Type> //����������� ����������
void CopyTree(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree)
{
	if (!obj.GetRoot()) return;
	for(begin;  begin != end; begin++)
		newTree.AddNode(*begin);
}

template<typename Type> //���������� �� ��� ����
void Sort(Tree<Type>& obj)
{
	if (!obj.GetRoot()) return;
	Type varNode;
	Tree<Type> newTree;
	int sortType = varNode.SortData() - 1;
	system("CLS");
	CopyTree(obj, obj.Begin(), obj.End(), newTree);    //�������� ������, � ������� ����� ��������
	typename Tree<Type>::Iterator begin = newTree.Begin();
	obj.ClrTreeRoot(obj.GetRoot());
	while (begin != newTree.End())
	{
		varNode = (*begin);
		varNode.SetCompareParam(sortType);
		obj.AddNode(varNode);
		begin++;
	}
	newTree.ClrTreeRoot(newTree.GetRoot());
}

template<typename Type>  //��������� ��������� � ����
void SaveToFile(Tree<Type> obj, const char* fileName)
{
	TxtFile fOut;
	Tree<Type> newTree;
	system("CLS");
	CopyTree(obj, obj.Begin(), obj.End(), newTree);              //�������� ������, � ������� ����� ��������
	typename Tree<Type>::Iterator begin = newTree.Begin();
	fOut.OpenTxtFileOut(fileName);       //�������� ����� ��� ��������
	while (begin != newTree.End())        //���� �������� ��������� ������ ������
	{
		fOut.OutputTxtFile(*begin);
		begin++;
	}
	newTree.ClrTreeRoot(newTree.GetRoot());
	fOut.CloseTxtFileOut();
}

template<typename Type>   //�������� ��� ����
void SetOtherField(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end)
{
	Type varNode;
	std::cin >> varNode;
	for (begin; begin != end; begin++)
	{
		if (*begin == varNode) break;
	}
	if (begin == end) std::cout << "������ ������� �� �������" << std::endl;
	else (*begin).SetFieldValue();
}











template<typename Type>
Node<Type>* Copy(Node<Type>* node, Node<Type>* other, Node<Type>* previous)
{
	if (other)
	{
		node = new Node<Type>(&other->data);
		node->prev = previous;
		node->R = Copy(node->R, other->R, node);
		node->L = Copy(node->L, other->L, node);
		return node;
	}
	return nullptr;
}
