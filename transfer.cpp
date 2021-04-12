#include "transfer.h"

// Insertion Operator that calls overidden display method
ostream& operator<<(ostream& Out, const Transfer& Transfer) {
	return Transfer.display(Out);
}

// Default Constructor that initalizes all private data members
Transfer::Transfer(int Acct1, int FundID1, int Amount,
	int Acct2, int FundID2, bool TransactionStatus) :
	Transaction::Transaction(Acct1, TransactionStatus), FundID1{ FundID1 },
	Amount{ Amount }, AccountID2{ Acct2 }, FundID2{ FundID2 } {};

// Default Destructor
Transfer::~Transfer() = default;

// Display method that displays all properties of a
// Transfer Transaction
ostream& Transfer::display(ostream& Out) const {
	Out << "Transfer Transaction: ";
	Out << "From AccountID: " << AccountID;
	Out << " Amount: " << Amount;
	Out << " From Fund Index: " << FundID1;
	Out << " To AccountID: " << AccountID2;
	Out << " To Fund Index: " << FundID2;
	if (!TransactionStatus) {
		Out << " (Failed) ";
	}
	return Out;
}

