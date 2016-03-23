/*
File Name: MyNode.h
Special Thanks: To Commissioner Gordon for helping with the MyList.h Insert and Print methods 
and to Kyle Huntsman who helped make the structure for a templated class
Author: Brandon Olson 
Date: 9/21/2014
File Description: This file contains a very simple node class that is used for a linked list
data structure.
*/

//IMPORTS
#pragma once
#include <iostream>
template <typename T>
class MyNode
{
public:
	MyNode<T>(void);
	MyNode<T>(T argData);
	~MyNode(void);
	T data;
	MyNode* successor;
	MyNode* predecessor;
};

//CONSTRUCTOR(S) and DECONSTRUCTOR
template <typename T>
MyNode<T>::MyNode(void)
{
	data = NULL;
	successor = NULL;
	predecessor = NULL;
}

template <typename T>
MyNode<T>::MyNode(T argData)
{
	data = argData;
	successor = NULL;
	predecessor = NULL;
}

template <typename T>
MyNode<T>::~MyNode(void)
{

}