#include "account.h"

// Displays account infor and all funds
ostream& operator<<(ostream& Out, const Account& Account) {
	Out << "Account ID: " << Account.getAccountInfo().getAccountID() 
		<< endl;
	Out << "Account First: " << Account.getAccountInfo().getFirstName() 
		<< endl;
	Out << "Account Last: " << Account.getAccountInfo().getLastName() 
		<< endl;

	for (int Index = 0; Index < 10; Index++) {
		Out << Account.FundList[Index] << endl;
	}
	return Out;
}

// Default account opening with an Opening object
Account::Account(const Opening& OpeningAccount) 
	: AccountInfo{ OpeningAccount } {}

// Default destructor
Account::~Account() = default;

// Returns AccountInfo Opening object
Opening Account::getAccountInfo() const{
	return AccountInfo;
}

// Adds a given amount to a given fund
bool Account::addToFund(int FundNum, int Amount) {
	if (FundNum < 0 || FundNum > 9) {
		cout << "ERROR: Invalid Fund number" << endl;
		return false;
	}
	
	FundList[FundNum].Balance += Amount;

	return true;
}

// Removes a given amount from a given fund
bool Account::removeFromFund(int FundNum, int Amount) {
	if (FundNum < 0 || FundNum > 9) {
		cout << "ERROR: Invalid Fund " << endl << endl;;
		return false;
	}

	if ((FundList[FundNum].Balance - Amount) >= 0) {
		FundList[FundNum].Balance -= Amount;
		return true;
		//if withdrawal fails, but in Money Market
	} if (FundNum == 1 || FundNum == 0) {
		int RemAmount = Amount - FundList[FundNum].Balance;
		//NOLINTNEXTLINE
		for (int I = 0; I < FundList.size(); I++) {
			if (FundList[I].Balance - RemAmount >= 0) {
				FundList[FundNum].Balance = 0;
				FundList[I].Balance -= RemAmount;
				return true;
			}
		}
		return false;
	}

	cout << "ERROR: Overdraft" << endl << endl;
	return false;
}

// Removes from this Fund's Balance and adds to other Fund's Balance
bool Account::transferFunds(Account* Acc2, int FundNum1, 
	int FundNum2, int Amount) {
	if ((FundNum1 < 0 || FundNum1 > 9) ||
		(FundNum2 < 0 || FundNum2 > 9)) {
		cout << "ERROR: Invalid Fund " << endl << endl;
		return false;
	}
	bool Continue = true;
	if (FundList[FundNum1].Balance - Amount < 0) Continue = false;

	if (Continue) {
		FundList[FundNum1].Balance -= Amount;
		Acc2->addToFund(FundNum2, Amount);
		return true;
	}

	cout << "ERROR: Amount could not be withdrawn from Account" << endl;
	return false;
}

// Adds a transaction to a given fund's History
void Account::addFundTransaction(int FundNum, Transaction* Transaction) {
	FundList[FundNum].History.push_back(Transaction);
}

// Displays all funds' Histories
void Account::getAccountHistory() const {
	//NOLINTNEXTLINE
	for (int FundNum = 0; FundNum < FundList.size(); 
		FundNum++) {
		cout << FundList[FundNum] << endl;
		//NOLINTNEXTLINE
		for (int Index = 0; Index < FundList[FundNum].History.size();
			Index++) {
			cout << "		" << *(FundList[FundNum].History[Index]) << endl;
		}
	}
}

// Displays a given fund's History
void Account::getFundHistory(int FundNum) const {
	cout << FundList[FundNum] << endl;
	//NOLINTNEXTLINE
	for (int Index = 0; Index < FundList[FundNum].History.size();
		Index++) {
		cout << "	" << *(FundList[FundNum].History[Index]);
	}
}






