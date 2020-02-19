#ifndef CHILD_CPP
#define CHILD_CPP
#include "Child.h"
Child::Child()
{
	firstName = "";
	lastName = "";
	age = 0;
}

Child::~Child()
{
}

Child::Child(const Child & child)
{
	this->firstName = child.firstName;
	this->lastName = child.lastName;
	this->age = child.age;
}

Child::Child(string fName, string lName, int a)
{
	setFirstName(fName);
	setLastName(lName);
	setAge(a);
}



ostream& operator<<(ostream& outStream, const Child& source)
{
	outStream << source.getFirstName() << source.getLastName()
		<< source.getAge();
	return outStream;
}

istream& operator>>(istream& inStream, Child& source)
{
	inStream >> source.firstName >> source.lastName >> source.age;
	return inStream;
}

string Child::getFirstName() const
{
	return firstName;
}

string Child::getLastName() const
{
	return lastName;
}

int Child::getAge() const
{
	return age;
}

void Child::setFirstName(string fName)
{
	this->firstName = fName;
}

void Child::setLastName(string lName)
{
	this->lastName = lName;
}

void Child::setAge(int a)
{
	this->age = a;
}

bool Child::operator=(const Child& source)
{
	if (*this == source) return false;
	firstName = source.firstName;
	lastName = source.lastName;
	age = source.age;
	return true;
}

bool Child::operator==(const Child & source) const
{
	return ((firstName==source.firstName)&&(lastName==source.lastName)
		&&(age==source.age));
}

bool Child::operator!=(const Child & source) const
{
	return !(*this == source);
}

bool Child::operator<(const Child & source) const
{
	if (lastName.compare(source.lastName) < 0)
		return true;
	if ((lastName.compare(source.lastName) == 0)
		&& firstName.compare(source.firstName) < 0)
		return true;
	else if ((firstName.compare(source.firstName) == 0) && (age < source.age))
		return true;
	return false;
}

bool Child::operator<=(const Child & source) const
{
	return ((*this < source) || (*this == source));
}

bool Child::operator>(const Child & source) const
{

	if (lastName.compare(source.lastName) > 0)
		return true;
	else if ((lastName.compare(source.lastName) == 0) 
		&& firstName.compare(source.firstName) > 0)
		return true;
	else if ((lastName.compare(source.lastName) == 0)
		&& (firstName.compare(source.firstName) == 0) &&(age > source.age))
		return true;
	else
		return false;
}

bool Child::operator>=(const Child & source) const
{
	return ((*this > source) || (*this == source));
}

#endif