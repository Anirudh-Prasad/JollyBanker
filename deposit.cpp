#include "deposit.h"

// Insertion Operator that calls overidden display method
ostream& operator<<(ostream& Out, const Deposit& Deposit) {
	return Deposit.display(Out);
}

// Default Constructor, initalizes all private data members
Deposit::Deposit(int AccountID, int Amount, int FundID, 
	bool TransactionStatus) 
	: Transaction::Transaction(AccountID, TransactionStatus),
	Amount{ Amount }, FundID{ FundID } {}

// Default Destructor
Deposit::~Deposit() = default;

// Overriden display method that displays all properties
// of a Deposit Transaction
ostream& Deposit::display(ostream& Out) const {
	Out << "Deposit Transaction: ";
	Out << "AccountID: " << AccountID;
	Out << " Amount: " << Amount;
	Out << " Fund Index: " << FundID;
	if (!TransactionStatus) {
		Out << " (Failed) ";
	}
	return Out;
}

