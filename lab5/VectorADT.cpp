#include <iostream>
#include <cstring>
#include "VectorADT.h"


using namespace std;
VectorADT::VectorADT()
{
	////a default constructor to initialize the data members as follows: 0-->size, 10->capacity,
	size = 0;
	capacity = 10;
	//and allocating a space of 10 doubles to array (of course). 
	array = new double[capacity];
	//Don't forget to initialize each element on array to 0.00.
	for (int i = 0; i < capacity; i++)
	{
		array[i] = 0.00;
		//size++;
	}
}

VectorADT::~VectorADT()
{
	if (array != nullptr)
	{
		delete[]array;
		array = nullptr;
	}
}

VectorADT::VectorADT(const VectorADT& copy)
{
	try
	{
		size = copy.size;
		capacity = copy.capacity;

		array = new double[capacity];

		for (int i = 0; i < capacity; i++)
			array[i] = copy.array[i];

	}
	catch (const char* error)
	{
		cerr << error << endl;
	}
}


VectorADT&  VectorADT::operator=(const VectorADT& rhs)
{
	//from lecture notes
	//	(1)this->coeff doesn't have any memory: allocate memory and transfer data from the rhs
	//	(2)this->coeff has its own memory space but with a different size of the rhs's:  deallocate the memory,allocate memory; and transfer data from the rhs
	//	(3)this->coeff has its own memory space but with the smae size of the rhs's:   transfer data from rhs

	//(1)
	if (this->array != nullptr || this->array)
	{
		for (int i = 0; i < capacity; i++)
			array[i] = rhs.array[i];
	}
	//(2)
	else if (this->capacity != rhs.capacity)
	{
		delete[] this->array;
		this->array = new double[rhs.capacity];
		//Don't forget to initialize each element on array to 0.00.
		for (int i = 0; i < rhs.capacity; i++)
		{
			array[i] = rhs.array[i];
		}
	}
	//(3)
	else
	{
		array = new double[rhs.capacity];
		for (int i = 0; i < rhs.capacity; i++)
			array[i] = rhs.array[i];
	}

	return *this;
}

int VectorADT::length() const
{
	return size;
}
int VectorADT::curr_capacity()const
{
	return capacity;
}


//void push_back(double val ); This member function inserts the value 'val' to the end of the dynamic array
void VectorADT::push_back(double val)
{
	
	if (size < capacity)
	{
		array[size] = val;
		size++;
	}

	else if (size = capacity) {

		this->resize(size + 1);
			array[size-1] = val;
	}


	else if (size > capacity)
	{
		this->resize(size + 1);

		array[size-1] = val;
		size++;
	}
	
}


void VectorADT::resize(int newSize)
{
	
	//If newSize is greater than the current container size,
	//For example, if the current value of capacity is 100 and newSize is 150, your program is going to reallocate
	//memory to increase the capacity of array to 300.
	if (newSize < this->size)
	{
		double * tempArray;
		tempArray = new double[capacity];
		this->size = newSize;
		for (int i = 0; i < capacity; i++)
		{
			if (i < newSize)
				tempArray[i] = this->array[i];
			else
				tempArray[i] = 0.0;
		}
		
		delete[] this->array;
		this->array = tempArray;
	}
	/*else if (newSize > capacity)
	{
	//the content is expanded by inserting at the end as many elements as needed to reach a size of newSize.
	for (int i = 0; i < size; i++)
	tempArray[i] = array[i];
	for (int i = size; size < capacity; i++)
	tempArray[i] = 0.00;
	}*/

	else if (newSize > this->size)
	{
		this->capacity = newSize * 2;
		double * tempArray;
		tempArray = new double[this->capacity];
		
		for (int i = 0; i < newSize; i++)
		{
			if (i < this->size){
				tempArray[i] = this->array[i];
				
			}
			else
			{
				tempArray[i] = 0.0;
			
			}
		}
		size = newSize;
		//size = newSize; //  1.  it doesn't change the size to 30 ?????
		//size = newSize;
		delete[] this->array;
		this->array = tempArray;

		//this->capacity = newSize * 2;
		//double *tempArray = new double[this->capacity];
		//memcpy(tempArray, this->array, size * sizeof(int));
		
		//delete[] this->array;
		//this->array = tempArray;

	}



}


//void pop_back(); This member function deletes the last number from the array, i.e., it decreases the size of the container by 1.
void VectorADT::pop_back()
{
	size = size - 1;
}

//Overload the operator[ ] as a read-only member function to return the i-th element in array. Assume v1 is a VectorADT object, 
//this operator allows one to retrieve the i-th element on array if i is valid using the statement v1[ i ];.
double VectorADT::operator[](int i)const
{
	if (i < size)
		return array[i];
	else
		return 1;//error
}

//Overload the addition operator (operator+) as a member function to add two VectorADT objects, say v1 and v2 if they are of the same size. 
//This member function is not allowed to change either of its two operands. It returns a VectorADT object corresponding to the sum of v1 and v2. 
//With this operator, one can add v1 and v2 as follows: v3 = v1+v2;
VectorADT VectorADT::operator+(const VectorADT& rhs)
{
	VectorADT sum;
	try
	{

		if (this->length() == rhs.length())
		{
			for (int i = 0; i < this->length(); i++)
				sum.array[i] = this->array[i] + rhs.array[i];
				//sum.push_back(this->array[i] + rhs.array[i]);
		}
		else
		{
			cerr << "different size! cant not add up" << endl;
		}
		
		
		

	}
	catch (const char* error)
	{
		cerr << error << endl;
	}

	sum.size = rhs.size;
	sum.size = this->length();
	return sum;
}

//Overload the put operator (i.e., operator<<) as a friend function to print out all the elements stored in a VectorADT object.For example,
//assume the VectorADT object v1 contains the following numbers 1.10, 21.12, -0.81.One can write cout << v1; to print out a comma - 
//separated list of these three numbers on the screen.
ostream & operator<<(ostream & out, const VectorADT & vecObject)
{
	for (int i = 0; i < vecObject.length(); i++)
	{
		out << vecObject[i];
		if (i < vecObject.length() - 1)
			out << ", ";
		else
			out << ".";

	}
	return out;
}