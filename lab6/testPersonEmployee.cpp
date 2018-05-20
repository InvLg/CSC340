#include <iostream>
#include "Person.h"
#include "Employee.h"

int main(int argc, char *argv[])
{
	Person per1,per2;
	Employee emp1,emp2;
	
	per1.setEmail("my@email.com");
	cout << per1.getEmail() << endl;
	cout << per1.getPlace(3) << endl;
	cout << per1.getPlace(20) << endl;
	cout << per1.getTypeOfObj() << endl;
	per2 = per1;
	
	emp1.setEmail("clerk@163.com");
	cout << emp1.getEmail() << endl;
	cout << emp1.getChangeRate(8) << endl;
	cout << emp1.getChangeRate(15) << endl;
	cout << emp1.getTypeOfObj() << endl;
	emp2 = emp1;
	
	Person per3(per1);
	cout << per3.getEmail() << endl;
	cout << per3.getPlace(3) << endl;
	cout << per3.getPlace(20) << endl;
	cout << per3.getTypeOfObj() << endl;	
	Employee emp3(emp1);
	cout << emp3.getEmail() << endl;
	cout << emp3.getChangeRate(8) << endl;
	cout << emp3.getChangeRate(15) << endl;
	cout << emp3.getTypeOfObj() << endl;
		
	Person** arrayPersonEmp;
	mixedArray(arrayPersonEmp, 12, 10);
	deleteMixedArray(arrayPersonEmp, 22);
	
	//system("pause");
	return 0;
}
