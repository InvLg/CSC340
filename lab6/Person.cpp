#include "Person.h"

Person::~Person()
{
	delete []placesVisited;
	placesVisited = NULL;
}
 
Person::Person()
{		
	SSN = 0;
	name = "na";
	personalEmail = "personal@";
	cntPlaces = 10;
	
	placesVisited = new string[cntPlaces];
	for(int i=0; i<cntPlaces; i++)
	{
		placesVisited[i] = "unknown";
	}
}
Person& Person::operator=(const Person& rhs )
{
	if(this != &rhs)
	{
	 	SSN = rhs.SSN;
		name = rhs.name;
		personalEmail = rhs.personalEmail;
		
		if(placesVisited != NULL)
		{
			delete []placesVisited;
			placesVisited = NULL;
		}
		
		cntPlaces = rhs.cntPlaces;			
		placesVisited = new string[cntPlaces];
		for(int i=0; i<cntPlaces; i++)
		{
			placesVisited[i] = rhs.placesVisited[i];
		}  			
    }
    return *this;
}

Person::Person( const Person &clone )
{
	SSN = clone.SSN;
	name = clone.name;
	personalEmail = clone.personalEmail;
	cntPlaces = clone.cntPlaces;
	
	placesVisited = new string[cntPlaces];
	for(int i=0; i<cntPlaces; i++)
	{
		placesVisited[i] = clone.placesVisited[i];
	}    	
}

string Person::getPlace(int i) const
{
	if(i>=0 && i<cntPlaces)
	{
		return placesVisited[i];
	}
	return "out-of-boundary";
}

string Person::getEmail() const
{
	return personalEmail;
}

void Person::setEmail( string new_email)
{
	personalEmail = new_email;
}

string Person::getTypeOfObj() const
{
	return "Person";
}
