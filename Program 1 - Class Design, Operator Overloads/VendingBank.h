#pragma once
#include <iostream>
#include <string>
using namespace std;

class VendingBank
{
private:
	string itemId;
	int numPennies, numNickels, numDimes, numQuarters;
	int totalMoney;
	int const penny = 1;
	int const nickel = 5;
	int const dime = 10;
	int const quarter = 25;
public:
	//constructors
	VendingBank();
	VendingBank(string itemId);
	VendingBank(int numPennies,int numNickels,int numDimes,int numQuarters);
	//destructor
	~VendingBank();
	//getter/setter
	double getItemPrice(string itemId);
	bool AddPennies(const int pennies);
	bool AddNickels(const int nickels);
	bool AddDimes(const int dimes);
	bool AddQuarters(const int quarters);
	//verbs
	bool validateCoin();
	bool transaction(int totalMoney, string itemId);
	bool cancelTransaction();
	bool exchange(int totalMoney);

	friend ostream & operator<<(ostream &output, const VendingBank &theBank);
	friend ostream & operator>>(istream &input, VendingBank &theBank);
};