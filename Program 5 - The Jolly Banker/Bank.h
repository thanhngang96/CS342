#pragma once
#include "Transaction.h"
#include "BSTree.h"
#include <queue>

class Bank
{
public:
	
	Bank();
	~Bank();
	Bank(const Bank &bank);

	bool ReadTransactions(string fileName);
	void ExecuteTransactions();
	void DisplayTransactions();
private:
	queue<Transaction> transactionQueue;
	BSTree accountData;
};


