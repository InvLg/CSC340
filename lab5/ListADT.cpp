#include <iostream>
#include "ListADT.h"

using namespace std;

//a default constructor to initialize the linked list: 0->size, nullptr->head
ListADT::ListADT() :head(0), size(0) {}


//the "big-3": destructor, copy constructor and overloaded assignment operator

ListADT& ListADT::operator = (ListADT& rhs)
{
	ListADT sum;
	for (int i = 0; i < rhs.length(); i++)
		sum.push_back(rhs[i]);
	return sum;
}
ListADT::~ListADT()
{
	Node *temp;
	temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}
ListADT::ListADT(const ListADT& copy)
{
	head = new Node(copy.head->value);
	size = copy.size;
	Node* curr = copy.head->next;
	//curr->next = nullptr;
	Node* nCurr = head;
	while (curr != nullptr)
	{
		nCurr->next = new Node(curr->value);
		curr = curr->next;
		nCurr = nCurr->next;
	}
}

//void push_back(int val); This member function inserts the value 'val' to the end of the linked list.
void ListADT::push_back(int val)
{
	Node* newNode = new Node(val);//newnode
	newNode->next = nullptr;
	Node* curr = head;
	if (head == nullptr)
	{
		head = newNode;
		size++;
	}
	else
	{
		while (curr->next != nullptr)
			curr = curr->next;
		curr->next = newNode;
		size++;
	}
}

//void push_front(int val); This member function inserts the value 'val' to the front of the linked list.
void ListADT::push_front(int val)
{
	Node*newNode = new Node(val);
	newNode->next = nullptr;//fix runtime error
	if (head == 0)
	{
		head = newNode;
		size++;
	}
	else
	{
		newNode->next = head;
		head = newNode;
		size++;
	}
}

//void pop_back(); This member function deletes the last number from the linked list.
void ListADT::pop_front()
{
	Node* pfront = head->next;
	delete head;
	head = pfront;
	size=size-1;
}
//void pop_front(); This member function deletes the first number from the linked list.
void ListADT::pop_back()
{
	if (head == nullptr)
		cerr << "size =0" << endl;
	Node* curr = head;
	if (head != nullptr)
	{
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			size--;
		}
		else
		{
			while (curr->next != nullptr)
				curr = curr->next;//runtime error?
			size--;
		}
	}
	//else
	//{
	//	Node* nodeToDelete = head;
	//	while (nodeToDelete->next != nullptr)
	//	
	//		nodeToDelete = nodeToDelete->next;
		
	//	delete nodeToDelete;
	//	nodeToDelete = nullptr;
	//	--size;
	
}
//Overload the operator[ ] as a read - only member function to return the i - th element on the linked list.
//Assume list1 is a ListADT object, this operator allows one to retrieve the i - th element on the list if i is valid using the statement list1[i]; 
//Note that this operator is not included in the STL list.We include it here to showcase how flexible operator overloading can be.
double ListADT::operator[] (int i)const
{
	Node* curr = head;
	int j = 0;
	if (i < size)
	{
		for (int j=0; j < i; j++)
			curr = curr->next;
		return curr->value;
	} 
	else
		return 0;
}


//an overloaded put operator (i.e., operator<<) as a friend to print out all the data items on the linked list as a comma - separated list.
//For example, if a list l1 contains the following list of numbers 2->4-> - 1->10. The statement cout << l1; will produce 2, 4, -1, 10 on the standard output.
ostream& operator<<(ostream& out, ListADT& listObject)
{

	for (int i=0; i < listObject.length(); i++)
	{
		out << listObject[i];
		if (i < listObject.length() - 1)
			cout << ",";
	}
	out << ".";
	return out;
}


//int length() const; This read - only member function returns the current size of the list container(i.e., the number of integers in the container).
int ListADT::length() const
{
	return size;
}



