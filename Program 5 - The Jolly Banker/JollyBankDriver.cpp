#include <iostream>
#include "Bank.h"
using namespace std;

int main(int argc,const char* argv[])
{
	Bank jollyBank;
	jollyBank.ReadTransactions(argv[1]);
	//jollyBank.ReadTransactions("BankTransIn.txt");
	jollyBank.ExecuteTransactions();
	jollyBank.DisplayTransactions();
	system("pause");
	return 0;
}