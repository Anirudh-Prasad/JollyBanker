#ifndef ASS5_WITHDRAW_H
#define ASS5_WITHDRAW_H

#include "transaction.h"

using namespace std;

class Withdraw : public Transaction {
	// Overloaded Insertion Operator to display Withdraw objects
	friend ostream& operator<<(ostream& Out, const Withdraw& Withdraw);

public:
	// Default Constructor
	explicit Withdraw(int Amount = -1, int AccountID = -1, 
		int FundID = -1, bool TransactionStatus = false);
	// Default Destructor
	~Withdraw() override;
	// Overridden display method to display Withdraw object contents
	ostream& display(ostream& Out) const override;
	
private:
	int Amount;
	int FundID;
};
#endif

