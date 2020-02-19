#include "Fund.h"



Fund::Fund()
{
	balance = 0;
}


Fund::~Fund()
{
}

Fund::Fund(string fName, int bal)
{
	fundName = fName;
	balance = bal;
}

vector<Transaction> Fund::getTransHistory()
{
	return TransHistory;
}

int Fund::getBalance() const
{
	return balance;
}

string Fund::getFundName() const
{
	return fundName;
}

void Fund::setFundName(string fName)
{
	fundName = fName;
}

void Fund::setBalance(const int & bal)
{
	balance = bal;
}


//=============================================================================
//                            deposit
//deposit money to the fund
//=============================================================================
bool Fund::deposit(const int & amount)
{
		balance += amount;
		return true;
}
//=============================================================================
//                            withdrawOk
//check if the balance in fund is enough to make withdrawal.
//=============================================================================
bool Fund::withdrawOk(const int & amount)
{
	if (balance >= amount)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//=============================================================================
//                            withdraw
//withdraw money from the fund
//=============================================================================
bool Fund::withdraw(const int & amount)
{
		balance -= amount;
		return true;
}

//=============================================================================
//                            transDone
//take the transaction out of the transaction queue.
//=============================================================================
bool Fund::transDone(const Transaction & theTransaction)
{
	TransHistory.push_back(theTransaction);
	return true;
}
//=============================================================================
//                            printHistoryOfAFund
//prints the history of a specific fund
//=============================================================================
void Fund::printHistoryOfAFund()
{
	if (TransHistory.size() == 0)
	{
		return;
	}
	else
	{
		cout << fundName << ": $" << balance << endl;
		for (size_t i = 0; i < TransHistory.size(); i++)
		{
			cout << "  " << TransHistory[i];
		}
	}
}
//=============================================================================
//                            printHistoryOfAFund
//prints the history of all funds
//=============================================================================
void Fund::printHistoryOfAllFund()
{

	for (size_t i = 0; i < TransHistory.size(); i++)
	{
		cout << " " << TransHistory[i];
	}
}



