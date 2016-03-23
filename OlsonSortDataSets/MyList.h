/*
File Name: MyList.h
Special Thanks: To Commissioner Gordon for helping with the MyList.h Insert and Print methods 
and to Kyle Huntsman who helped make the structure for a templated class
Author: Brandon Olson 
Date: 9/21/2014
File Description: This file is a templated doubly linked list class that used to used
store data using a chain of nodes that use to pointer to connect each node together.
*/

//IMPORTING
#pragma once
#include "MyNode.h"
#include <string>

using namespace std;

//CLASS DEFINITION
template <class T>
class MyList
{
public:
	MyList(void);
	~MyList(void);
	MyNode<T>* Find(const T & argValue);
	void Insert(const T & argData);
	bool DeleteFront(void);
	bool DeleteBack(void);
	bool Delete(MyNode<T>* argNodePointer);
	T Minimum(void);
	T Maximum(void);
	void Print(void);
	int Length(void);
	bool IsEmpty(void);
	void Connect(MyNode<T>* nodeOne, MyNode<T>* nodeTwo);
	void UpdateFooter(void);
	T At(int argIndex);
	void SwitchData(int argIndex1, int argIndex2);
	void ChangeData(int argIndex, T argData);
	MyNode<T>* header;
	MyNode<T>* footer;
};

//CONSTRUCTOR(S)

template <class T>
///<summary>
///The default constructor for the MyList class.
///</summary>
MyList<T>::MyList(void)
{
	header = NULL;
	footer = NULL;
}

//DECONSTRUCTOR

template <class T>
///<summary>
///The deconstructor of the MyList class
///</summary>
MyList<T>::~MyList(void)
{
}

//METHODS

template <typename T>
///<summary>
///A method that returns a pointer to a node that has the same data as the given data.
///NULL is returned if that data is not in the list.
///</summary>
MyNode<T>* MyList<T>::Find(const T & argValue)
{
	MyNode<T> *currentNode = new MyNode<T>();
	currentNode = header;
	bool IsAllChecked = false;
	//While loop will cycle through each node read its respective data 
	while (!IsAllChecked)
	{
		if (currentNode->data == argValue)
		{
			return currentNode;
		}
		currentNode = currentNode->successor;
	}
	return NULL;
}

template <typename T>
///<summary>
///A method
///</summary>
void MyList<T>::UpdateFooter(void)
{
	if(!IsEmpty())
	{
		MyNode<T> *currentNode = new MyNode<T>();
		currentNode = header;
		bool IsNotPrinted = true;
		//While loop will cycle through each node read it respective data and output it to the console
		while (IsNotPrinted)
		{
			if (currentNode->successor != NULL)
			{
				currentNode = currentNode->successor;
			}
			else
			{
				footer = currentNode;
				IsNotPrinted = false;
			}
		}
	}
	else
	{
		footer = NULL;
	}
}

template <typename T>
///<summary>
///A method that adds a new node to the front of the linked list.
///</summary>
void MyList<T>::Insert(const T & argData)
{
	MyNode<T>* node = new MyNode<T>(argData);
	Connect(node, header);
	header = node;
	UpdateFooter();
}

template <typename T>
///<summary>
///A method that removes the first node from the list.
///</summary>
bool MyList<T>::DeleteFront()
{
	if (!IsEmpty())
	{
		MyNode<T> *tmp = header->successor;
		Connect(NULL, header->successor);
		delete header;
		header = tmp;
		UpdateFooter();
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
///<summary>
///A method that removes the last node from the list.
///</summary>
bool MyList<T>::DeleteBack()
{
	if (!IsEmpty())
	{
		MyNode<T> *tmp = footer->predecessor;
		Connect(footer->predecessor, NULL);
		delete footer;
		footer = tmp;
		UpdateFooter();
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
///<summary>
///A method that removes the node that the nodePointer points too.
///</summary>
bool MyList<T>::Delete(MyNode<T>* nodePointer) 
{
	if (nodePointer == NULL)
	{
		return false;
	}
	else
	{
		if (nodePointer->predecessor == NULL)
		{
			return DeleteFront();
		}
		else if (nodePointer->successor == NULL)
		{
			return DeleteBack();
		}
		else if (nodePointer->predecessor != NULL & nodePointer->successor != NULL)
		{
			Connect(nodePointer->predecessor, nodePointer->successor);
			delete nodePointer;
			UpdateFooter();
			return true;
		}
	}
}

template <typename T>
///<summary>
///A method that returns the smallest value contained within the doubly linked list.
///</summary>
T MyList<T>::Minimum(void)
{
	if (IsEmpty())
	{
		return NULL;
	}	
	MyNode<T> currentNode = *header;
	T smallest = currentNode.data;
	bool checkedAll = false;
	while (!checkedAll)
	{	
		if (smallest > currentNode.data)
		{
			smallest = currentNode.data;
		}
		if (currentNode.successor != NULL)
		{
			currentNode = *(currentNode.successor);
		}
		else
		{
			checkedAll = true;
		}
	}
	return smallest;
}

template <typename T>
///<summary>
///A method that returns the greatest value contained within the doubly linked list.
///</summary>
T MyList<T>::Maximum(void)
{
	if (IsEmpty())
	{
		return NULL;
	}	
	MyNode<T> currentNode = *header;
	T greatest = currentNode.data;
	bool checkedAll = false;
	while (!checkedAll)
	{	
		if (greatest < currentNode.data)
		{
			greatest = currentNode.data;
		}
		if (currentNode.successor != NULL)
		{
			currentNode = *(currentNode.successor);
		}
		else
		{
			checkedAll = true;
		}
	}
	return greatest;
}

template <typename T>
///<summary>
///Outputs a formated list to the console of the nodes to 
///the console of the given doubly linked list.
///</summary>
void MyList<T>::Print(void)
{
	cout << "[ ";
	if (!IsEmpty())
	{
		MyNode<T> currentNode = *header;
		bool IsNotPrinted = true;
		//While loop will cycle through each node read it respective data and output it to the console
		while (IsNotPrinted)
		{
			cout << currentNode.data;
			if (currentNode.successor != NULL)
			{
				cout << ", ";
				currentNode = *(currentNode.successor);
			}
			else
			{
				IsNotPrinted = false;
			}
		}
	}
	cout << " ] " << endl;
}

template <typename T>
///<summary>
///A method that returns the total number of nodes that are 
///contained within the doubly linked list.
///</summary>
int MyList<T>::Length(void)
{
	if (IsEmpty())
	{
		return 0;
	}	
	MyNode<T> currentNode = *header;
	int count = 0;
	bool checkedAll = false;
	while (!checkedAll)
	{	
		count++;
		if (currentNode.successor != NULL)
		{
			currentNode = *(currentNode.successor);
		}
		else
		{
			checkedAll = true;
		}
	}
	return count;
}

template <typename T>
///<summary>
///A function that determines if the list is empty by 
///determining if the header pointer has a null value
///returning true or false.
///</summary>
bool MyList<T>::IsEmpty(void)
{ 
	return header == NULL;
}

template <typename T>
///<summary>
///A method that when given two node pointers it will 
///connect there respective predecessor and successor
///of each node together. The first nodeOne will be 
///connected in front of nodeTwo.
///</summary>
void MyList<T>::Connect(MyNode<T>* nodeOne, MyNode<T>* nodeTwo)
{
	if (nodeOne != NULL)
	{
		nodeOne->successor = nodeTwo;
	}

	if(nodeTwo != NULL)
	{
		nodeTwo->predecessor = nodeOne;
	}
}

template <typename T>
///<summary>
///A method that returns the node that is currently occupying a given index.
///</summary>
T MyList<T>::At(int argIndex)
{
	if (argIndex < 0 || argIndex >= Length())
	{
		throw "The index is out of bounds for the list";
	}
	if (!IsEmpty())
	{
		MyNode<T>* currentNode = header;
		for (int currentIndex = 0; currentIndex < argIndex; currentIndex++)
		{
			currentNode = currentNode->successor;
		}
		return currentNode->data;
	}
	else
	{
		return NULL;
	}
}

template <typename T>
///<summary>
///A method that switchs the data at two given indexs;
///</summary>
void MyList<T>::SwitchData(int argIndex1, int argIndex2)
{
	if (argIndex1 < 0 || argIndex1 >= Length())
	{
		throw "Index1 is out of bounds for the list";
	}
	if (argIndex2 < 0 || argIndex2 >= Length())
	{
		throw "Index2 is out of bounds for the list";
	}
	if (!IsEmpty())
	{
		if (argIndex1 != argIndex2)
		{
			T data1 = At(argIndex1);
			T data2 = At(argIndex2);
			ChangeData(argIndex2, data1);
			ChangeData(argIndex1, data2);
		}
	}
}

template <typename T>
///<summary>
///A method that changes the data at a given index;
///</summary>
void MyList<T>::ChangeData(int argIndex, T argData)
{
	if (argIndex < 0 || argIndex >= Length())
	{
		throw "The index is out of bounds for the list";
	}
	if (!IsEmpty())
	{
		MyNode<T>* currentNode = header;
		for (int currentIndex = 0; currentIndex < argIndex; currentIndex++)
		{
			currentNode = currentNode->successor;
		}
		currentNode->data = argData;
	}
}