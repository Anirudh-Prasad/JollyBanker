#ifndef ASS5_BANK_H
#define ASS5_BANK_H

#include "account.h"
#include "accounttree.h"
#include "deposit.h"
#include "opening.h"
#include "transaction.h"
#include "transfer.h"
#include "withdraw.h"
#include <fstream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

class Bank {

	// Insertion Operator overload that outputs the Bank's data
	friend ostream& operator<<(ostream& Out, const Bank& Bank);

public:
	// Default Constructor
	Bank();
	// Default Destructor
	~Bank();
	// Reads file and puts all lines in a queue
	void processTransactions(const string &FileName);
	// Displays all account balances
	void displayAllBankBalances() const;
  
private:
	Account* AccountToOpen;
	AccountTree Accounts;
	queue<string> TransactionList;

	// Copies Queue without altering param Queue
	queue<string> qCopy(const queue<string> &Queue); 

	// Assigns each transaction line to appropiate method
	void assignTransactions();
};
#endif // ASS5_BANK_H
