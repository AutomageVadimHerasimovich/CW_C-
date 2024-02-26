#pragma once
#include "Tree.h"

template<typename Type>
Node<Type>* Copy(Node<Type>* node, Node<Type>* other, Node<Type>* previous = nullptr);  // —копировать дерево

template <typename Type>    //фильтр контейнера 
void FilterNodes(Type data, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree);

template <typename Type>
void Sort(Tree<Type>& obj);  //сортировка по опр полю

template <typename Type>    //сохранить изменени€ в файл
void SaveToFile(Tree<Type> obj, const char* filename);

template <typename Type>    //изменить опр поле
void SetOtherField(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end);

template<typename Type>		//копирование контейнера
void CopyTree(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree);


template<typename Type>   //фильтр контейнера 
void FilterNodes(Type data, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree)
{
	while (begin != end)
	{
		if (*begin == data) newTree.AddNode(*begin);
		begin++;
	}
}

template<typename Type> //копирование контейнера
void CopyTree(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end, Tree<Type>& newTree)
{
	if (!obj.GetRoot()) return;
	for(begin;  begin != end; begin++)
		newTree.AddNode(*begin);
}

template<typename Type> //сортировка по опр полю
void Sort(Tree<Type>& obj)
{
	if (!obj.GetRoot()) return;
	Type varNode;
	Tree<Type> newTree;
	int sortType = varNode.SortData() - 1;
	system("CLS");
	CopyTree(obj, obj.Begin(), obj.End(), newTree);    //копируем дерево, с которым будем работать
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

template<typename Type>  //сохранить изменени€ в файл
void SaveToFile(Tree<Type> obj, const char* fileName)
{
	TxtFile fOut;
	Tree<Type> newTree;
	system("CLS");
	CopyTree(obj, obj.Begin(), obj.End(), newTree);              //копируем дерево, с которым будем работать
	typename Tree<Type>::Iterator begin = newTree.Begin();
	fOut.OpenTxtFileOut(fileName);       //открытие файла дл€ дозаписи
	while (begin != newTree.End())        //пока возможно считывать корень дерева
	{
		fOut.OutputTxtFile(*begin);
		begin++;
	}
	newTree.ClrTreeRoot(newTree.GetRoot());
	fOut.CloseTxtFileOut();
}

template<typename Type>   //изменить опр поле
void SetOtherField(Tree<Type>& obj, typename Tree<Type>::Iterator begin, typename Tree<Type>::Iterator end)
{
	Type varNode;
	std::cin >> varNode;
	for (begin; begin != end; begin++)
	{
		if (*begin == varNode) break;
	}
	if (begin == end) std::cout << "“акого объекта не найдено" << std::endl;
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
