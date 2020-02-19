#include "Account.h"



Account::Account()
{
	 lastName ="";
	 firstName = "";
	 accountID = -1;
	 string fundNames[numFunds] = { "Money Market", "Prime Money Market",
								 "Long-Term Bond", "Short-Term Bond",
								 "500 Index Fund", "Capital Value Fund",
								 "Growth Equity Fund", "Growth Index Fund",
								 "Value Fund", "Value Stock Index" };
}


Account::~Account()
{
}

Account::Account(string fName, string lName, int accID)
{	
	firstName = fName;
	lastName = lName;
	accountID = accID;
	string fundNames[numFunds] = { "Money Market", "Prime Money Market",
									"Long-Term Bond", "Short-Term Bond",
									"500 Index Fund", "Capital Value Fund",
									"Growth Equity Fund", "Growth Index Fund",
									"Value Fund", "Value Stock Index" };
	for (int i = 0; i < 10; i++)
	{
		funds[i].setFundName(fundNames[i]);
	}
}

string Account::getLastName() const
{
	return lastName;
}

string Account::getFirstName() const
{
	return firstName;
}

int Account::getAccountID() const
{
	return accountID;
}

string Account::getFundName(int fID) const
{
	return funds[fID].getFundName();
}

int Account::getFundBalance(int fID) const
{
	return funds[fID].getBalance();
}

void Account::setLastName(string lName)
{
	lastName = lName;
}

void Account::setFirstName(string fName)
{
	firstName = fName;
}

void Account::setAccountID(int accID)
{
	accountID = accID;
}

//=============================================================================
//                            printTransHistory 
//prints the transaction history of all funds
//=============================================================================
void Account::printTransHistory()
{
	cout << "Transaction History for " << firstName << " " << lastName 
		<< " by fund." << endl;
	for (int i = 0; i < numFunds; i++)
	{
		funds[i].printHistoryOfAFund();
	}
}

//=============================================================================
//                          printFundHistory
//print the transaction history of a fund given its id
//=============================================================================
void Account::printFundHistory(int fID)
{
	cout << "Transaction History for " << firstName << " " << lastName << " " 
		<< getFundName(fID) << ": $" << getFundBalance(fID) << endl;
	funds[fID].printHistoryOfAllFund();
}

//=============================================================================
//                                     deposit 
//deposit to a fund. 
//=============================================================================
bool Account::deposit(int amount, int fID)
{
	funds[fID].deposit(amount);
	return true;
}

//=============================================================================
//                              withdrawLinkedAccount 
//withdraw from two linked funds.  
//=============================================================================
void Account::withdrawLinkedAccount(int firstFundID, int secondFundID, int amount)
{
		//withdraw the owed money from the first fund 
		int owedAmount = funds[firstFundID].getBalance();
		funds[firstFundID].withdraw(owedAmount);
		Transaction succeedTrans('W', getAccountID(), firstFundID, owedAmount);
		funds[firstFundID].transDone(succeedTrans);

		//withdraw the leftover amount using the second fund
		amount -= owedAmount;
		funds[secondFundID].withdraw(amount);
		Transaction succeedTrans2('W', getAccountID(), secondFundID, amount);
		funds[secondFundID].transDone(succeedTrans2);
}

//=============================================================================
//                               insufficientFund
//fund balance is insufficient to make the withdrawal 
//=============================================================================
void Account::insufficientFund(int amount, string fName, string lName, int fID)
{
	cerr << "ERROR: Not enought funds to withdraw " << amount << " from " 
		<< firstName << " " << lastName << " " << getFundName(fID)
		<< endl;
	Transaction failedTrans('W', getAccountID(), fID,  amount, "Failed");
	funds[fID].transDone(failedTrans);
}

//=============================================================================
//                                     withdraw
//withdraw money from a fund given the transaction order 
//=============================================================================
bool Account::withdraw(int fID, int amount, Transaction trans)
{
	if (fID == 0 || fID == 1 || fID == 2 || fID == 3)
	{
		if (fID == 0 || fID == 1)
		{
			if (funds[fID].withdrawOk(amount))
			{
				funds[fID].withdraw(amount);
				funds[fID].transDone(trans);
				return true;
			}
			else if (((funds[0].getBalance() + funds[1].getBalance()) >= amount))
			{
				if (fID == 0)
				{
					withdrawLinkedAccount(0, 1, amount);
				}
				else
				{
					withdrawLinkedAccount(1, 0, amount);
				}
			}
			else
			{
				insufficientFund(amount, getFirstName(), getLastName(), fID);				
				return false;
			}
		}
		else if (fID == 2 || fID == 3)
		{
			if (funds[fID].withdrawOk(amount))
			{
				funds[fID].withdraw(amount);
				funds[fID].transDone(trans);
				return true;
			}
			else if (((funds[2].getBalance() + funds[3].getBalance()) >= amount))
			{
				if (fID == 2)
				{
					withdrawLinkedAccount(2, 3, amount);
				}
				else
				{
					withdrawLinkedAccount(3, 2, amount);
				}
			}
			else
			{
				insufficientFund(amount, getFirstName(), getLastName(), fID);
				return false;
			}
		}
	}
	else
	{
		if (funds[fID].withdrawOk(amount))
		{
			funds[fID].withdraw(amount);
			funds[fID].transDone(trans);
			return true;
		}
		else
		{
			insufficientFund(amount, getFirstName(), getLastName(), fID);
			return false;
		}
	}
}


//=============================================================================
//                              addTransHistory
//add the transaction to transaction history of a fund
//=============================================================================
void Account::addTransHistory(Transaction trans, int fID)
{
	funds[fID].transDone(trans);
}

//=============================================================================
//                             operator==
//compare two accounts by their IDs
//=============================================================================

bool Account::operator==(const Account & rhs) const
{
	if (rhs.accountID == this->accountID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//=============================================================================
//                             operator<
//compare two accounts by their IDs
//=============================================================================
bool Account::operator<(const Account & rhs) const
{
	if (rhs.accountID < this->accountID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//=============================================================================
//                             operator>
//compare two accounts by their IDs
//=============================================================================
bool Account::operator>(const Account & rhs) const
{
	if (rhs.accountID > this->accountID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//=============================================================================
//                             operator<<
//overloads operator << to display account fund's information
//=============================================================================
 ostream & operator<<(ostream & outStream, Account & acc)
{
	outStream << acc.getFirstName() << " " << acc.getLastName() 
				<< " ID: " << acc.getAccountID() << endl;
	for (int i = 0; i < 10; i++)
	{
		outStream << " " << acc.getFundName(i) << " :$"
			<< acc.getFundBalance(i) << endl;
	}
	return outStream;
}
