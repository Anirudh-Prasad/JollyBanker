#include "withdraw.h"

// Insertion Operator that calls overidden display method
ostream& operator<<(ostream& Out, const Withdraw& Withdraw) {
	return Withdraw.display(Out);
}

// Default Constructor that initalizes all private data members
Withdraw::Withdraw(int Amount, int AccountID, int FundID, 
	bool TransactionStatus)
	: Transaction::Transaction(AccountID, TransactionStatus),
	Amount{ Amount }, FundID{ FundID } {}

// Default Destructor
Withdraw::~Withdraw() = default;

// Display method that displays all properties of a
// Withdraw Transaction
ostream& Withdraw::display(ostream& Out) const {
	Out << "Withdraw Transaction: ";
	Out << "AccountID: " << AccountID;
	Out << " Amount: " << Amount;
	Out << " Fund Index: " << FundID;
	if (!TransactionStatus) {
		Out << " (Failed) ";
	}
	return Out;
}



