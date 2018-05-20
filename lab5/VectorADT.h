#include <iostream>
using namespace std;
const int MAX_ARRAY_CAPACITY = 10;
class VectorADT
{

private:
	double *array;
	int size;
	int capacity;

public:
	//a default constructor to initialize the data members as follows: 0-->size, 10->capacity,
	VectorADT();
	//and allocating a space of 10 doubles to array (of course). 
	//Don't forget to initialize each element on array to 0.00.


	//the "big-3": destructor, copy constructor and overloaded assignment operator
	~VectorADT();
	VectorADT(const VectorADT& copy);
	VectorADT& operator=(const VectorADT& rhs);


	//void push_back(double val ); This member function inserts the value 'val' to the end of the dynamic array
	void push_back(double val);

	//void resize(int newSize); This member function Resizes the container so that it contains newSize elements.
	//If newSize is smaller than the current container size, the content is reduced to its first newSize elements. 
	//You don't have to reduce the capacity in this case. If newSize is greater than the current container size, 
	//the content is expanded by inserting at the end as many elements as needed to reach a size of newSize. 
	//You are required to initialize all the new elements to 0.00. If newSize is also greater than the current 
	//container capacity, make sure you increase the capacity to 2*newSize, i.e., double the value of newSize. 
	//For example, if the current value of capacity is 100 and newSize is 150, your program is going to reallocate 
	//memory to increase the capacity of array to 300.
	void resize(int newSize);



	//void pop_back(); This member function deletes the last number from the array, i.e., it decreases the size of the container by 1.
	void pop_back();

	//Overload the operator[ ] as a read-only member function to return the i-th element in array. Assume v1 is a VectorADT object, 
	//this operator allows one to retrieve the i-th element on array if i is valid using the statement v1[ i ];.
	double operator[](int i) const;

	//Overload the addition operator (operator+) as a member function to add two VectorADT objects, say v1 and v2 if they are of the same size. 
	//This member function is not allowed to change either of its two operands. It returns a VectorADT object corresponding to the sum of v1 and v2. 
	//With this operator, one can add v1 and v2 as follows: v3 = v1+v2;
	VectorADT operator+(const VectorADT& rhs);

	//Overload the put operator (i.e., operator<<) as a friend function to print out all the elements stored in a VectorADT object.For example,
	//assume the VectorADT object v1 contains the following numbers 1.10, 21.12, -0.81.One can write cout << v1; to print out a comma - 
	//separated list of these three numbers on the screen.
	friend ostream& operator<<(ostream&, const VectorADT&);

	//int length() const; This read-only member function returns the current size of the array (i.e., the number of doubles in the container).
	int length() const;
	//int curr_capacity() const; This read-only member function returns the current capacity of the array 
	int curr_capacity() const;
	//(i.e., the maximum number of doubles that can be stored in the container).
};