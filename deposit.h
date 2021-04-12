#ifndef ASS5_DEPOSIT_H
#define ASS5_DEPOSIT_H

#include "transaction.h"

using namespace std;

class Deposit : public Transaction {
	// Overloaded Insertion Operator to display Deposits
	friend ostream& operator<<(ostream& Out, const Deposit& Deposit);

public:
	// Default Constructor
	explicit Deposit(int AccountID = -1, int Amount = -1, 
		int FundID = -1, bool TransactionStatus = false);
	// Overriden Default Destructor
	~Deposit() override;
	ostream& display(ostream& Out) const override;

private:
	int Amount;
	int FundID;
};
#endif

