
#ifndef ASS5_ACCOUNT_H
#define ASS5_ACCOUNT_H

#include "deposit.h"
#include "opening.h"
#include "transfer.h"
#include "withdraw.h"
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

class Account {

	// Displays Account
	friend ostream& operator<<(ostream& Out, const Account& Account);

public:
	// Explicit Constructor with Opening Transaction
	explicit Account(const Opening& OpeningAccount = Opening());
	// Default Destructor
	~Account();

	// Gets Account Opening object
	Opening getAccountInfo() const;
	// Adds an amount to a given fund
	bool addToFund(int FundNum, int Amount);
	// Removes an amount from a given fund
	bool removeFromFund(int FundNum, int Amount);
	// Transfers an amount to a given account and fund
	bool transferFunds(Account* Acc2, int FundNum1, int FundNum2, int Amount);
	// Adds a Transfer, Deposit, and Withdraw to a given Fund
	void addFundTransaction(int FundNum, Transaction* Transaction);
	// Displays all Funds Histories
	void getAccountHistory() const;
	// Displays a given Funds History
	void getFundHistory(int FundNum) const;

private:
	// Private Fund Class
	// Stores a Name, Balance and History of Transactions
	 class Fund {

		 // Displays a Fund's Name and Balance
		 friend ostream& operator<<(ostream& Out, const Fund& Fund) {
			 Out << "Fund Name: " << Fund.Name << " - Fund Balance: $" 
				 << Fund.Balance;
			 return Out;
		 }

	public:
		string Name;
		int Balance;
		vector<Transaction*> History;

		// Start a Fund object with a name and a balance of 0
		//NOLINTNEXTLINE
		explicit Fund(string Name) : Name{ Name }, Balance{ 0 } {} 

		// Destroies dynamically allocated Transaction objects
		~Fund() { 
			//NOLINTNEXTLINE
			for (int Index = 0; Index < History.size(); ++Index) {
				delete History[Index];
			}
		}
	};
	
	Opening AccountInfo;
	vector<Fund> FundList { Fund("Money Market"), 
		Fund("Prime Money Market"),
		Fund("Long-Term Bond"), Fund("Short-Term Bond"),
		Fund("500 Index Fund"), Fund("Capital Value Fund"),
		Fund("Growth Equity Fund"), Fund("Growth Index Fund"),
		Fund("Value Fund"), Fund("Value Stock Index") };
};
#endif // ASS5_ACCOUNT_H
