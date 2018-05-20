#include <iostream>
#include <ctime>//srand
#include "dynamicArray.h"

using namespace std;

int * array_constructor(int * &intPtr, int &size)

{

	//fix that array_constructor() failed the test when a caller requests to construct an array of an non-positive size!
	if (size <= 0)
	{
		return NULL;
	}

	else{
	//create a temp array to expand array and let intPtr point to this array
	int *tempArray = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		tempArray[i] = i * i;
	}

	//exception handling
	try 
	{
		intPtr = tempArray;
	}
	catch (std::bad_alloc& bad)
	{
		std::cerr << "bad_alloc for intPtr in array_constructor" << bad.what() << endl;
		exit(-1);
	}
	intPtr = tempArray;
	for (int i = 0; i < size; i++)
	{
		cout << intPtr[i] << endl;
	}		

	//deallocate temp
	//delete[] tempArray;
	
	return intPtr;
	}
}


int * array_resize(int * &intPtr, int& currSize, int& newSize)
{

	//fix
	//terminate called after throwing an instance of 'std::bad_array_new_length'
	//what() : std::bad_array_new_length

	if (newSize <= 0)
		return NULL;

	else if (currSize == newSize)
		return intPtr;


	//expansion
	else if (newSize > currSize) 
	{
		int *tempArray = new int[newSize];

		for (int i = 0; i < currSize; i++)
		{
			tempArray[i] = intPtr[i];
		}

		for (int i = currSize; i < newSize; i++)
		{
			tempArray[i] = i * i;
		}

		delete[] intPtr;
		intPtr = tempArray;

		return intPtr;
	}
	
	//shrink
	else if (newSize < currSize)
	{
		int *tempArray = new int[newSize];

		for (int i = 0; i < newSize; i++)
		{
			tempArray[i] = intPtr[i];
		}
		//point to the temp
		delete[] intPtr;
		intPtr = tempArray;
		return tempArray;
	}

}

void array_destructor(int * &intPtr)
{
	//deallocate
	delete[] intPtr;
	intPtr = NULL;
}

void array_set(int * &intPtr, int &size)
{

	srand(time(0));
	
	for (int i = 0; i < size; i++)
	{
		//let each elements in the array intPtr be a random num
		intPtr[i] = rand();
	}
}

bool my_less_equal(int &x, int&y)
{
	if (x <= y)
		return true;
	else
		return false;
}

bool my_greater_equal(int &x, int&y)
{
	if (x >= y)
		return true;
	else
		return false;
}


void mysort(int* &intPtr, int size, bool(*comp)(int&, int&))
{
	int i, j,key;
	for (i = 1; i < size; i++)
	{
		key = intPtr[i];
		int j = i - 1;


		while (j >= 0 && comp(key, intPtr[j]))
		{
			intPtr[j + 1] = intPtr[j];
			j = j - 1;
		}
		intPtr[j + 1] = key;
	}
}