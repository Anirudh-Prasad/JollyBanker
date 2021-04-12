#ifndef ASS5_TRANSFER_H
#define ASS5_TRANSFER_H

#include "transaction.h"

using namespace std;

class Transfer : public Transaction {
	// Overloaded Insertion Operator to display Transfer objects
	friend ostream& operator<<(ostream& Out, const Transfer& Transfer);

public:
	// Default Constructor
	explicit Transfer(int Acct1 = -1, int FundID1 = -1, int Amount = -1,
		int Acct2 = -1, int FundID2 = -1, bool TransactionStatus = false);
	// Default Destructor
	~Transfer() override;
	// Overridden display method to display Transfer object contents
	ostream& display(ostream& Out) const override;

private:
	int AccountID2;
	int Amount;
	int FundID1;
	int FundID2;
};
#endif

