#include "Transaction.h"


Transaction::Transaction()
{
	
}

//constructor for opening a new account with an ID.
Transaction::Transaction(char transType, string lName, string fName, int accID)
{
	 transactionType = transType;
	 lastName = lName;
	 firstName = fName;
	 accountID = accID;
}

//constructor for depositing or withdrawing from an account.
Transaction::Transaction(char transType, int accID, int fID, int amount)
{
	transactionType = transType;
	accountID = accID;
	fundID = fID;
	transAmount = amount;
}

//constructor for transferring money from an account to another account.
Transaction::Transaction(char transType, int accID, int fID, int amount,
							int transferAccID, int transferFID)
{
	transactionType = transType;
	accountID = accID;
	fundID = fID;
	transAmount = amount;
	transferAccountID = transferAccID;
	transferFundID = transferFID;
}

//constructor for transaction history of all funds from an account.
Transaction::Transaction(char transType, int accID)
{
	transactionType = transType;
	accountID = accID;
}

//constructor for transaction history of a specific fund from an account.
Transaction::Transaction(char transType, int accID, int fID)
{
	transactionType = transType;
	accountID = accID;
	fundID = fID;
}

//constructor for failed transfering money from an account to another
Transaction::Transaction(char transType, int accID, int fID, int amount,
						int transferAccID, int transferFID, string failed)
{
	transactionType = transType;
	accountID = accID;
	fundID = fID;
	transAmount = amount;
	transferAccountID = transferAccID;
	transferFundID = transferFID;
	failTransCheck = failed;
}

//constructor for failed depositing or withdrawing from an account.
Transaction::Transaction(char transType, int accID, int fID, int amount,
						string failed)
{
	transactionType = transType;
	accountID = accID;
	fundID = fID;
	transAmount = amount;
	failTransCheck = failed;
}

Transaction::~Transaction()
{
}

char Transaction::getTransType() const
{
	return transactionType;
}

string Transaction::getLastName() const
{
	return lastName;
}

string Transaction::getFirstName() const
{
	return firstName;
}

int Transaction::getAccountID() const
{
	return accountID;
}

int Transaction::getFundID() const
{
	return fundID;
}

int Transaction::getTransAmount() const
{
	return transAmount;
}

int Transaction::getTransferAccountID() const
{
	return transferAccountID;
}

int Transaction::getTransferFundID() const
{
	return transferFundID;
}

void Transaction::setTransType(char transType)
{
	transactionType = transType;
}

void Transaction::setLastName(string lName)
{
	lastName = lName;
}

void Transaction::setFirstName(string fName)
{
	firstName = fName;
}

void Transaction::setAccountID(int accID)
{
	accountID = accID;
}

void Transaction::setFundID(int fID)
{
	fundID = fID;
}

void Transaction::setTransAmount(int amount)
{
	transAmount = amount;
}

void Transaction::setTransferAccountID(int transferAccID)
{
	transferAccountID = transferAccID;
}

void Transaction::setTransferFundID(int transferFID)
{
	transferFundID = transferFID;
}

//=============================================================================
//                            operator<<
//overloads operator << to display transaction info.
//=============================================================================
ostream & operator<<(ostream & outStream, const Transaction & trans)
{
	//check if transaction succeed or failed.
	if (trans.failTransCheck.empty())
	{
		if (trans.getTransType() == 'D' || trans.getTransType() == 'W')
		{
			outStream << " " << trans.getTransType() << " " 
					<< trans.getAccountID() << trans.getFundID() << " " 
					<< trans.getTransAmount() << endl;
		}
		else if (trans.getTransType() == 'T')
		{
			outStream << " " << trans.getTransType() << " " 
					<< trans.getAccountID() << trans.getFundID() << " "
					<< trans.getTransAmount() << " " 
					<< trans.getTransferAccountID() 
					<< trans.getTransferFundID() << endl;
		}
	}
	else
	{
		if (trans.getTransType() == 'D'  || trans.getTransType() == 'W' )
		{
			outStream << " " << trans.getTransType() << " " 
					<< trans.getAccountID() << trans.getFundID() << " " 
					<< trans.getTransAmount() << " (Failed)" << endl;
		}
		else if (trans.getTransType() == 'T')
		{
			outStream << " " << trans.getTransType() << " " << trans.getAccountID()
					<< trans.getFundID() << " " << trans.getTransAmount() << " " 
					<< trans.getTransferAccountID() << trans.getTransferFundID()
					<< " (Failed)" << endl;
		}
	}
	return outStream;
}
