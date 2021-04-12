#include "transaction.h"

// Calls display to output Transaction data
ostream& operator<<(ostream& Out, const Transaction& Transaction) {
	return Transaction.display(Out);
}

// 2 arg Constructor takes int and boolean value  
// initializes AccountID and TransactionStatus
Transaction::Transaction(int AccountID, bool TransactionStatus) : 
	AccountID{ AccountID }, TransactionStatus{ TransactionStatus } {}

// Default Destructor
Transaction::~Transaction() = default;

// Returns AccountID
int Transaction::getAccountID() const{
	return AccountID;
}

// Returns status of the Transaction
bool Transaction::getTransactionStatus() {
	return TransactionStatus;
}

// Outputs AccountID and TransactionStatus
ostream& Transaction::display(ostream& Out) const {
	Out << "Transaction: "<< AccountID;
	Out << " " << TransactionStatus;
	return Out;
}


