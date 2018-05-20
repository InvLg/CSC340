#include <iostream>
#include "VectorADT.h"
#include "ListADT.h"


using namespace std;

int main()
{
	VectorADT v1, v2, v3, v4;
	
	cout << "check first element of v1" << endl;
	cout << v1[1] << endl;

	v1.push_back(1.0);
	v1.push_back(2.0);
	v1.push_back(3.0);
	v1.push_back(4.0);
	v1.push_back(5.0);
	v1.push_back(6.0);
	v1.push_back(7.0);
	v1.push_back(8.0);
	v1.push_back(9.0);
	v1.push_back(10.0);
	v1.push_back(11.0);
	v1.push_back(12.0);
	v1.push_back(13.0);
	v1.push_back(14.0);
	v1.push_back(15.0);
	v1.push_back(16.0);
	v1.push_back(17.0);
	v1.push_back(18.0);
	v1.push_back(19.0);
	v1.push_back(20.0);
	cout << v1 << endl;
	v2.push_back(2.0);
	v3.push_back(2.0);
	v4.push_back(2.0);
	v3 = v2 + v4;
	cout << "print LHS of v3 sum " << v2 <<"next ele  " <<v2[2]<<" next ele  "<<v2[3]<< endl;
	cout << "capa" << v2.curr_capacity() << endl;
	cout << "size" << v2.length() << endl;

	cout << "print RHS of v4 sum " << v4 <<"next ele  " <<v4[2]<<" next ele  "<<v4[3]<<endl;
	cout << "capa" << v4.curr_capacity() << endl;
	cout << "size" << v4.length() << endl;
	cout <<"print sum "<< v3 <<"next ele"<<v4[2]<<endl;
	cout << "capa" << v3.curr_capacity() << endl;
	cout << "size" << v3.length() << endl;

	cout << "capa" << v1.curr_capacity() << endl;
	cout << "size" << v1.length() << endl;

	cout << "calling resize from 15 to 25" << endl;
	cout << "now is 15" << endl;
	v2.resize(15);
	cout << "now priting v2" << v2 << endl;
	cout << "capa" << v2.curr_capacity() << endl;
	cout << "size" << v2.length() << endl;
	cout << "calling resize from 15 to 25" << endl;
	cout << "now is 25, size should be 25, capacity should be 50" << endl;
	v2.resize(25);
	cout << "capa" << v2.curr_capacity() << endl;
	cout << "size" << v2.length() << endl;

	//cout << "calling resize from 14 to 24" << endl;
	//cout << "now is 14" << endl;
	//v3.resize(15)


	/*
	cout << "print initiliazed v1 by constructor" << endl;
	cout << v1 << endl;

	//cout << "test push_Back" << endl;
	//v1.push_back(1);
	//cout << v1 << endl;

	//v4 = v2 + v3;
	//cout << v4 << endl;
	
	ListADT l1;

	l1.push_front(1);
	l1.push_front(3);
	l1.push_back(5);
	cout << l1 << endl;
	ListADT l2 = l1;
	cout << l2 << endl;

	l1 .pop_back();
	cout << l1;
	*/
	system("pause");

}