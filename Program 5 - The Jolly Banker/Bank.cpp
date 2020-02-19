#include "Bank.h"
#include "Transaction.h"
#include "Account.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>


Bank::Bank()
{

}


Bank::~Bank()
{
}

Bank::Bank(const Bank & bank)
{
	transactionQueue = bank.transactionQueue;
	accountData = bank.accountData;
}

//=============================================================================
//                               ReadTransactions
//reads through the text file and adds transactions to the queue
//=============================================================================
bool Bank::ReadTransactions(string fileName)
{
	ifstream inFile;
	string readLine;
	inFile.open(fileName);

	if (!inFile)
	{
		cerr << "ERROR: Cannot open file." << endl;
		return false;
	}
	else
	{
		while (!inFile.eof())
		{
			getline(inFile, readLine);
			if (readLine.empty())
			{
				break;
			}
			istringstream parseLine(readLine);
			char transType;
			parseLine >> transType;

			//reading open
			if (transType == 'O')
			{
				string lastName, firstName;
				int accountID;

				parseLine >> firstName >> lastName >> accountID;

				//creates and pushes the transaction into queue
				Transaction addTrans(transType, firstName, lastName, 
									accountID);
				transactionQueue.push(addTrans);

			}

			//reading withdraw
			else if (transType == 'D' || transType == 'W')
			{
				int accountFundNum, accountID, fundID;
				int amount;

				parseLine >> accountFundNum >> amount;
				accountID = accountFundNum / 10;
				fundID = accountFundNum % 10;

				//creates and pushes the transaction into queue
				Transaction addTrans(transType, accountID, fundID, amount);
				transactionQueue.push(addTrans);
			}

			//reading transaction
			else if (transType == 'T')
			{
				int accountID, fundID, amount, trasnferAccountID, 
					transferFundID;
				parseLine >> accountID >> amount >> trasnferAccountID;
				fundID = accountID % 10;
				accountID = accountID / 10;
				transferFundID = trasnferAccountID % 10;
				trasnferAccountID = trasnferAccountID / 10;
				Transaction addTrans(transType, accountID, fundID, amount,
									trasnferAccountID, transferFundID);
				transactionQueue.push(addTrans);
			}
			
			//reading history
			else if (transType == 'H')
			{
				int accountFundNum;
				parseLine >> accountFundNum;
				
					//creates and pushes the transaction into queue
					Transaction addTrans(transType, accountFundNum);
					transactionQueue.push(addTrans);
				
			}
			else
			{
				cout << "ERROR: Invalid input." << endl;
			}
		}
		return true;
	}
}

//=============================================================================
//                            ExecuteTransactions
//executes all transactions in the queue
//=============================================================================
void Bank::ExecuteTransactions()
{
	while (!transactionQueue.empty())
	{
		//take the transaction from the transaction list.
		Transaction trans = transactionQueue.front();

		//opening new account process
		if (trans.getTransType() == 'O')
		{		
			//check if accountID is available for open a new account
			if (accountData.isAvailable(trans.getAccountID()))
			{
				Account* account = new Account(trans.getFirstName(),
									trans.getLastName(),
									trans.getAccountID());
				accountData.Insert(account);
			}
			else
			{
				cerr << "ERROR: Account " << trans.getAccountID() <<
					" is already opened. Transaction refused.";
			}
		}

		//depositing process
		else if (trans.getTransType() == 'D')
		{
			Account* account;
			int accountID, fundID, amount;
			accountID = trans.getAccountID();
			fundID = trans.getFundID();
			amount = trans.getTransAmount();

			//deposit to the account if found in account database.
			if (accountData.Retrieve(accountID, account))
			{
				account->deposit(amount, fundID);
				account->addTransHistory(trans, fundID);
			}
			else
			{
				cout << "ERROR: Failed at excecuting deposit process" << endl;
			}
		}
		//withdrawing process
		else if (trans.getTransType() == 'W')
		{
			Account* account;
			int accountID, fundID, amount;
			accountID = trans.getAccountID();
			fundID = trans.getFundID();
			amount = trans.getTransAmount();

			//withdraw to the account if found in account database.
			if (accountData.Retrieve(accountID, account))
			{
				account->withdraw(fundID, amount, trans);
			}
			else
			{
				cout << "ERROR: Failed at excecuting withdrawing process"
					<< endl;
			}
		}

		//transfering process
		else if (trans.getTransType() == 'T')
		{
			Account *toAccount, *fromAccount;
			int fromAccountID, fromFundID, amount, toAccountID, toFundID;
			fromAccountID = trans.getAccountID();
			fromFundID = trans.getFundID();
			toAccountID = trans.getTransferAccountID();
			toFundID = trans.getTransferFundID();
			amount = trans.getTransAmount();	
			if (accountData.Retrieve(fromAccountID, toAccount) 
				&& accountData.Retrieve(toAccountID, fromAccount))
			{
				//withdraw money from fromFunID and deposit to toAccount
				if (toAccount->withdraw(fromFundID, amount, trans))
				{
					toAccount->deposit(amount, toFundID);
					toAccount->addTransHistory(trans, toFundID);
				}
				else
				{
					cerr << "ERROR: Not enought funds to transer  " 
						<< amount << " from " << fromAccount->getAccountID()
						<< fromFundID << " to " << toAccount->getAccountID()
						<< toFundID << endl;
					Transaction failedTrans('T', fromAccountID, fromFundID,
						amount, toAccountID, toFundID,
						"(Failed)");
				}
			}
			
		}
		
		//history process
		else if (trans.getTransType() == 'H')
		{
			//check if accountID has 5 or 4 digits
			if (trans.getAccountID() >= 10000)
			{
				Account* account;
				int accountID, fundID;
				accountID = trans.getAccountID() / 10;
				fundID = trans.getAccountID() % 10;

				if (accountData.Retrieve(accountID, account))
				{
					account->printFundHistory(fundID);
					cout << endl;
				}
			}	
			else
			{
				Account* account;
				int accountID;
				accountID = trans.getAccountID();

				if (accountData.Retrieve(accountID, account))
				{
					account->printTransHistory();
					cout << endl;
				}

			}	
		}
		//proceeds to next transaction
		transactionQueue.pop();
	}
}

//=============================================================================
//                            DisplayTransactions
//displays all funds in the account
//=============================================================================
void Bank::DisplayTransactions()
{
	cout << endl << endl;
	cout << "Processing Done. Final Balances" << endl;
	accountData.Display();
}


