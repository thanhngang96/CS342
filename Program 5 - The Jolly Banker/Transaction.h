#pragma once
#include <iostream>
#include <string>

using namespace std;
class Transaction
{
	friend ostream & operator<<(ostream &theStream, const Transaction &trans);

public:

	Transaction();
	Transaction(char transType, string lName, string fName, int accID); 
	Transaction(char transType, int accID, int fID, int amount);
	Transaction(char transType, int fromAccID, int fromFundID, int amount,
				int toAccID, int toFID); 
	Transaction(char transType, int accID); 
	Transaction(char transType, int accID, int fID);
	Transaction(char transType, int fromAccID, int fromFundID, int amount,
				int toAccID, int toFID, string failed);
	Transaction(char transType, int accID, int fID, int amount, string failed);
	~Transaction();

	char getTransType() const;
	string getLastName() const;
	string getFirstName() const;
	int getAccountID() const;
	int getFundID() const;
	int getTransAmount() const;
	int getTransferAccountID() const;
	int getTransferFundID() const;


	void setTransType(char transType);
	void setLastName(string lName);
	void setFirstName(string fName);
	void setAccountID(int accID);
	void setFundID(int fID);
	void setTransAmount(int amount);
	void setTransferAccountID(int transferAccID);
	void setTransferFundID(int transferFID);
	


private:
	char transactionType;
	string lastName;
	string firstName;
	int accountID;
	int fundID;
	int transAmount;
	int transferAccountID;
	int transferFundID;
	string failTransCheck;
};

