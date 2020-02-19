#include "Transaction.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Fund
{
public:
	Fund();
	~Fund();
	Fund(string fName, int bal);
	
	vector<Transaction> getTransHistory();
	int getBalance() const;
	string getFundName() const;
	void setFundName(string fName);
	void setBalance(const int & bal);

	bool deposit(const int & amount);
	bool withdrawOk(const int & amount);
	bool withdraw(const int & amount);
	bool transDone(const Transaction &theTransaction);

	void printHistoryOfAFund();
	void printHistoryOfAllFund();
private:
	string fundName;
	int balance;
	vector<Transaction> TransHistory;
};

