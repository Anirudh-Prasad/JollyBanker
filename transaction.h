#ifndef ASS5_TRANSACTION_H
#define ASS5_TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

class Transaction {
	// Overloaded Insertion Operator to display Transaction objects
	friend ostream& operator<<(ostream& Out, const Transaction& Transaction);

public:
	// Defualt Constructor
    explicit Transaction(int AccountID = -1, bool TransactionStatus = false);
	// Virtual Default Destructor
	virtual ~Transaction();
	// Virtual display method to display all contents of a Transaction object
	virtual ostream& display(ostream& Out) const;
	// Getter for AccountID
	int getAccountID() const;
	// Getter for TransactionStatus
	bool getTransactionStatus();
	
protected:
	int AccountID;
	bool TransactionStatus;
};

#endif

