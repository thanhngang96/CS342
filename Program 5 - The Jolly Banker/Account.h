#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
#include "Fund.h"
using namespace std;

 const int numFunds = 10;
class Account
{
	friend ostream& operator<<(ostream & theStream, Account &acc);
public:
	Account();
	~Account();
	Account(string fName, string lName, int accID);

	string getLastName() const;
	string getFirstName() const;
	int getAccountID() const;
	string getFundName(int fID) const;
	int getFundBalance(int fID) const;
	void setLastName(string lName);
	void setFirstName(string fName);
	void setAccountID(int accID);

	void printTransHistory();
	void printFundHistory(int fID);

	bool deposit(int amount, int fID);
	bool withdraw(int fID, int amount, Transaction trans);
	void withdrawLinkedAccount(int firstFundID, int secondFundID, int amount);
	void insufficientFund(int amount, string fName, string lName, int fundNumber);
	void addTransHistory(Transaction trans, int fID);
	bool operator==(const Account &rhs) const;
	bool operator<(const Account &rhs) const;
	bool operator>(const Account &rhs) const;

private:
	string lastName;
	string firstName;
	int accountID;
	Fund funds[numFunds];
};

