#pragma once
#ifndef CHILD_H
#define CHILD_H
#include <iostream> 
#include <string>
#include <fstream>
using namespace std;

class Child
{
public:

	//Constructors-Destructor.
	Child();
	~Child();
	Child(const Child& child);
	Child(string firstName, string lastName, int age);

	//Getters.
	string getFirstName() const;
	string getLastName() const;
	int getAge() const;

	//Setters.
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setAge(int age);
	
	//Operator overloads.
	bool operator=(const Child& source);
	bool operator ==(const Child& source) const;
	bool operator !=(const Child& source) const;
	bool operator<(const Child& source) const;
	bool operator<=(const Child& source) const;
	bool operator>(const Child& source) const;
	bool operator>=(const Child& source) const;

	//Input-output overloads.
	friend ostream& operator<<(ostream& outStream, const Child& source);
	friend istream& operator>>(istream& outStream, Child& source);

private:
	string firstName;
	string lastName;
	int age;
};

#endif