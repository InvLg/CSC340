#include "Employee.h"

Employee::~Employee()
{
	delete []sal_change_rates;
	sal_change_rates = NULL;
}

Employee::Employee()
{
	salary = 0.0;
	cnt_sal_changes = 10;
	work_email = "work@";
	
	sal_change_rates = new double[cnt_sal_changes];
	for(int i=0; i<cnt_sal_changes; i++)
	{
		sal_change_rates[i] = 0.0;
	}
}

Employee::Employee( const Employee& clone)
{
	salary = clone.salary;
	work_email = clone.work_email;
	cnt_sal_changes = clone.cnt_sal_changes;
	
	sal_change_rates = new double[cnt_sal_changes];
	for(int i=0; i<cnt_sal_changes; i++)
	{
		sal_change_rates[i] = clone.sal_change_rates[i];
	}       	
}

Employee& Employee::operator=(const Employee& rhs )
{
	if(this != &rhs)
	{
	 	salary = rhs.salary;
		work_email = rhs.work_email;
		
		if(sal_change_rates != NULL)
		{
			delete []sal_change_rates;
			sal_change_rates = NULL;
		}
		
		cnt_sal_changes = rhs.cnt_sal_changes;		
		sal_change_rates = new double[cnt_sal_changes];
		for(int i=0; i<cnt_sal_changes; i++)
		{
			sal_change_rates[i] = rhs.sal_change_rates[i];
		}  			
    }
    return *this;    	    	
}

double Employee::getChangeRate( int i) const
{
	if(i>=0 && i<cnt_sal_changes)
	{
		return sal_change_rates[i];
	}
	return -1.00;
}

string Employee::getEmail() const
{
	return work_email;
}

void Employee::setEmail( string new_email)
{
	work_email = new_email;
}
	
string Employee::getTypeOfObj() const
{
	return "Employee";
}

void mixedArray( Person** &arrayPersonEmp, int numPersons, int numEmployees)
{
	int i,j;
	if(numPersons < 0 || numEmployees < 0)
	{
		arrayPersonEmp = NULL;
		return;
	}
	int n;
	n = numPersons + numEmployees;
	arrayPersonEmp = new Person*[n];
	//arrayPersonEmp = (Person**)new unsigned long[numPersons+numEmployees];
	for(i=0; i<numPersons; i++)
	{
		arrayPersonEmp[i] = new Person;
		arrayPersonEmp[i]->setEmail("personal@gmail.com");
	}
	for(j=0; j<numEmployees; j++)
	{
		arrayPersonEmp[i+j] = new Employee;
		arrayPersonEmp[i+j]->setEmail("work@gmail.com");
	}	
}

void deleteMixedArray(Person** &arrayPersonEmp, int size )
{
	for(int i=0; i<size; i++)
	{
		delete arrayPersonEmp[i];
		
	}
	delete []arrayPersonEmp;
	arrayPersonEmp = NULL;
}
