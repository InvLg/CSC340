#include<iostream>
using namespace std;


class ListADT {

private:
	class Node {
	public:
		Node() { value = 0; next = nullptr; };
		//implement this default constructor as an inline function using an initialization section. 0->value, nullptr->next 
		Node(int val) { value = val; next = nullptr;};
		//implement this constructor as an inline function using an initialization section. val->value, nullptr->next   
		int value;
		Node *next;	
	};

	Node * head; //point to the first node on the linked list
	int size;  //number of nodes on the linked list

public:
	//a default constructor to initialize the linked list: 0->size, nullptr->head
	ListADT();

	//the "big-3": destructor, copy constructor and overloaded assignment operator
	ListADT& operator = (ListADT& rhs);
	~ListADT();
	ListADT(const ListADT& copy);

	//void push_back(int val); This member function inserts the value 'val' to the end of the linked list.
	void push_back(int val);
	//void push_front(int val); This member function inserts the value 'val' to the front of the linked list.
	void push_front(int val);

	//void pop_back(); This member function deletes the last number from the linked list.
	void pop_front();
	//void pop_front(); This member function deletes the first number from the linked list.
	void pop_back();
	//Overload the operator[ ] as a read - only member function to return the i - th element on the linked list.
	//Assume list1 is a ListADT object, this operator allows one to retrieve the i - th element on the list if i is valid using the statement list1[i]; 
	//Note that this operator is not included in the STL list.We include it here to showcase how flexible operator overloading can be.
	double operator[] (int i)const;

	
	//an overloaded put operator (i.e., operator<<) as a friend to print out all the data items on the linked list as a comma - separated list.
	//For example, if a list l1 contains the following list of numbers 2->4-> - 1->10. The statement cout << l1; will produce 2, 4, -1, 10 on the standard output.
	friend ostream& operator<<(ostream&, ListADT&);


	//int length() const; This read - only member function returns the current size of the list container(i.e., the number of integers in the container).
	int length() const;

};

