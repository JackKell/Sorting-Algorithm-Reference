/*
Author: Brandon Olson
Date: 10/4/2014
File Name: SortingDriver
File Purpose: A program that takes two arguments, the filename a data file 
and an integer that defines the alogrithm that will be used to sort then
it reporst the information to the console.
Class Name: Data Structures and Algorthims
*/

//IMPORTS
#include <iostream>
#include "MyList.h"
#include <string>
#include <stdio.h>
#include <time.h>       
#include <math.h> 
#include <fstream>
#include <stdlib.h>  

//NAMESPACE
using namespace std;

//PROTOTPES
template <typename T>
void selectionSort(MyList<T>& argMyList);
template <typename T>
void bubbleSort(MyList<T>& argMyList);
template <typename T>
void insertionSort(MyList<T>& argMyList);
template <typename T>
void sort(MyList<T>& argMyList, int argSortType);
MyList<int> convertDataToLinkedList(string argFileName);

//DEFINITIONS
template <typename T>
void selectionSort(MyList<T>& argMyList)
{
	int listLength = argMyList.Length();
	for (int confirmedIndex = 0; confirmedIndex < listLength; confirmedIndex++)
	{
		T smallestDataValue = argMyList.At(confirmedIndex);
		int smallestDataIndex = confirmedIndex;
		for (int searchIndex = confirmedIndex; searchIndex < listLength; searchIndex++)
		{
			if (smallestDataValue > argMyList.At(searchIndex))
			{
				smallestDataValue = argMyList.At(searchIndex);
				smallestDataIndex = searchIndex;
			}
		}
		argMyList.SwitchData(smallestDataIndex, confirmedIndex);
	}
}
template <typename T>
void bubbleSort(MyList<T>& argMyList)
{
	int listLength = argMyList.Length();
	for (int confirmedIndex = 0; confirmedIndex < listLength - 1; confirmedIndex++)
	{
		for (int searchIndex = 0; searchIndex < listLength - 1; searchIndex++)
		{
			if (argMyList.At(searchIndex) > argMyList.At(searchIndex + 1))
			{
				argMyList.SwitchData(searchIndex, searchIndex + 1);
			}
		}	
	}
}
template <typename T>
void insertionSort(MyList<T>& argMyList)
{
	int listLength = argMyList.Length();
	for (int confirmedIndex = 1; confirmedIndex < listLength; confirmedIndex++)
	{
		int currentIndex = confirmedIndex;
		do
		{
			argMyList.SwitchData(currentIndex, currentIndex - 1);
			currentIndex = currentIndex - 1;
		} while ((currentIndex > 0) && (argMyList.At(currentIndex) < argMyList.At(currentIndex - 1)));
	}
	if (argMyList.At(listLength - 1) < argMyList.At(listLength - 2))
	{
		argMyList.SwitchData(listLength - 1, listLength - 2);
	}
}
template <typename T>
void sort(MyList<T>& argMyList, int argSortType)
{
	switch (argSortType)
	{
	case 0:
		selectionSort(argMyList);
		break;
	case 1:
		bubbleSort(argMyList);
		break;
	case 2:
		insertionSort(argMyList);
		break;
	default:
		bubbleSort(argMyList);
		break;
	}
}
MyList<int> convertDataToLinkedList(string argFileName)
{
	MyList<int> intList = MyList<int>();
	ifstream dataFile ("Resource Files/Data/" + argFileName);
	string data;
	int i;
	cout << dataFile.is_open();
	if (dataFile.is_open())
	{
		while (!dataFile.eof())
		{
			dataFile >> data;
			i =  stoi(data);
			intList.Insert(i);
		}
	}
	return intList;
	
}

int main()
{
	MyList<int> aList = MyList<int>();
	aList.Insert(5);
	aList.Insert(8);
	aList.Insert(9);
	aList.Insert(-5);
	aList.Insert(3);
	aList.Insert(10);
	aList.Print();
	insertionSort(aList);
	aList.Print();
	system("Pause");
	return 0;
}