#include "bank.h"

// Calls displayAllBankBalances to output AccountTree's data
ostream& operator<<(ostream& Out, const Bank& Bank) {
	Bank.displayAllBankBalances();
	return Out;
}
// Default constructor
Bank::Bank() : AccountToOpen{ nullptr } {}

// Default destructor
Bank::~Bank() {
	delete AccountToOpen;
}

// Reads input from a file, and stores the input in a Queue
void Bank::processTransactions(const string& FileName) {
	ifstream InFile;
	InFile.open(FileName);
	if (!InFile) {
		cout << "Unable to open file";
		// terminate with error
		exit(1); 
	}
	string StrToPush;
	while(getline(InFile, StrToPush)){
		TransactionList.push(StrToPush);
	}

	assignTransactions();
}

// Copy Constructor for Bank Class
// Makes copy of Queue without altering original
queue<string> Bank::qCopy(const queue<string> &Queue) { 
	queue<string> TheQueue = Queue;
	return TheQueue;
}

 
// Reads Transaction commands and info from a Queue, and performs
// actions based on Transaction type. 
// Pops Queue after each transaction 
void Bank::assignTransactions() {
	queue<string> CopyQueue = qCopy(TransactionList);
	while (!CopyQueue.empty()) {

		stringstream StringStream;
		string TransactionType;
		
		StringStream << CopyQueue.front();
		StringStream >> TransactionType;

		if (TransactionType == "O") { 
			string FirstName;
			string LastName;
			int AccountNumber;
			StringStream >> FirstName >> LastName >> AccountNumber;
			Opening OpeningInfo = Opening(FirstName, LastName, AccountNumber);
			AccountToOpen = new Account(OpeningInfo);
			Accounts.insert(AccountToOpen);

		} else if (TransactionType == "D") {

			int TotalNumber;
			int AccountNumber;
			int FundNumber;
			int Amount;
			StringStream >> TotalNumber >> Amount;
			FundNumber = TotalNumber % 10;
			AccountNumber = TotalNumber / 10;

			Account* ToDeposit;

			if (Accounts.retrieve(AccountNumber, ToDeposit)) {
				bool Status = ToDeposit->addToFund(FundNumber, Amount);
				ToDeposit->addFundTransaction(FundNumber, 
				new Deposit(AccountNumber, Amount, FundNumber, Status));
			} else {
				cout << "ERROR: Account not found" << endl;
			}
			
		} else if (TransactionType == "W") {

			int TotalNumber;
			int AccountNumber;
			int FundNumber;
			int Amount;
			StringStream >> TotalNumber >> Amount;
			FundNumber = TotalNumber % 10;
			AccountNumber = TotalNumber / 10;
			
			Account* ToWithdraw;

			if (Accounts.retrieve(AccountNumber, ToWithdraw)) {
 
				bool Status = ToWithdraw->removeFromFund(FundNumber, Amount);
				ToWithdraw->addFundTransaction(FundNumber, 
				new Withdraw(Amount, AccountNumber, FundNumber, Status));
			} else {
				cout << "ERROR: Account not found" << endl;
			}

		} else if (TransactionType == "T") {

			int TotalNumber1;
			int AccountNumber1;
			int FundNumber1;
			int Amount;
			int TotalNumber2;
			int AccountNumber2;
			int FundNumber2;
			StringStream >> TotalNumber1 >> Amount >> TotalNumber2;
			FundNumber1 = TotalNumber1 % 10;
			AccountNumber1 = TotalNumber1 / 10;
			FundNumber2 = TotalNumber2 % 10;
			AccountNumber2 = TotalNumber2 / 10;

			Account* Acc1;
			Account* Acc2;

			if (Accounts.retrieve(AccountNumber1, Acc1) && 
			Accounts.retrieve(AccountNumber2, Acc2)) {

				// output is different because 
				// transfer can remove funds from different accounts.
				bool Status = Acc1->transferFunds(Acc2, FundNumber1, 
				FundNumber2, Amount);
				Acc1->addFundTransaction(FundNumber1, 
				new Transfer(AccountNumber1, Amount, FundNumber1, 
				AccountNumber2, FundNumber2, Status));
				Acc2->addFundTransaction(FundNumber2,
				new Deposit(AccountNumber2, Amount, FundNumber2,
				Status));

			} else if (!Accounts.retrieve(AccountNumber1, Acc1) && 
			!Accounts.retrieve(AccountNumber2, Acc2)) {

				cout << "Could not find Accounts " << AccountNumber1 <<
					" and " << AccountNumber2 << " Transfer cancelled." 
					<< endl;

			} else if (!Accounts.retrieve(AccountNumber1, Acc1)) {

				cout << "Could not find Account " << AccountNumber1
					<< " Transfer cancelled." << endl;

			} else if (!Accounts.retrieve(AccountNumber2, Acc2)) {

				cout << "Could not find Account " << AccountNumber2
					<< " Transfer cancelled." << endl;
			}

		} else if (TransactionType == "H") {

			int TotalNumber;
			StringStream >> TotalNumber;

			if (TotalNumber > 9999) {

				int FundNumber = TotalNumber % 10;
				int AccountNumber = TotalNumber / 10;
				Account* AccountToDisplay;

				if (Accounts.retrieve(AccountNumber, AccountToDisplay)) {
					cout << " ----- History for Account: " << AccountNumber 
						<< " - Fund Number: " << FundNumber << " -----\n" 
						<< endl;
					AccountToDisplay->getFundHistory(FundNumber);
					cout << "\n" << endl;
				} else {
					cout << "ERROR: Account not found" << endl;
				}

			} else {

				int AccountNumber = TotalNumber;
				Account* AccountToDisplay;

				if (Accounts.retrieve(AccountNumber, AccountToDisplay)) {
					cout << " ----- History for Account: " << AccountNumber 
						<< " -----\n" << endl;
					AccountToDisplay->getAccountHistory();
					cout << "\n" << endl;
				} else {
					cout << "ERROR: Account not found" << endl;
				}
			}

		} else {
			cout << "ERROR: INVALID OPERATION" << endl;
		}

		CopyQueue.pop();
	}
}

// Calls AccountTree display function to output data from all stored Accounts
void Bank::displayAllBankBalances() const { this->Accounts.display(); }