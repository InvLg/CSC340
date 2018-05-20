#include <iostream>
#include "dynamicArray.h"

using namespace std;


int main()
{
	int * myArray;
	int size = 5;
	int newsize = 10;
	int newsizeShrink = 2;
	array_constructor(myArray,  size);

	for (int i = 0; i < size; i++)
	{
		cout << myArray[i] << endl;
	}

	cout << " delimeter" << endl;
	array_resize(myArray, size, newsize);

	for (int i = 0; i < newsize; i++)
	{
		cout << myArray[i] << endl;
	}

	cout << " delimeter" << endl;

	array_resize(myArray, size, newsizeShrink);

	for (int i = 0; i < newsizeShrink; i++)
	{
		cout << myArray[i] << endl;
	}

	cout << " delimeter" << endl;
	array_resize(myArray, newsizeShrink, newsize);

	for (int i = 0; i < newsize; i++)
	{
		cout << myArray[i] << endl;
	}
	cout << " delimeter" << endl;
	array_set(myArray, newsize);
	for (int i = 0; i < newsize; i++)
	{
		cout << myArray[i] << endl;
	}


	cout << "now ascending" << endl;
	mysort(myArray, newsize, &my_less_equal);
	for (int i = 0; i < newsize; i++)
	{
		cout << myArray[i] << endl;
	}
	cout << "now descending" << endl;
	mysort(myArray, newsize, &my_greater_equal);
	for (int i = 0; i < newsize; i++)
	{
		cout << myArray[i] << endl;
	}
	cout << "deallocate intPTR" << endl;
	
	array_destructor(myArray);
	cout << "deallocated" << endl;




	system ("pause");
}