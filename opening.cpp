#include "opening.h"

// Insertion Operator that calls overidden display method
ostream& operator<<(ostream& Out, const Opening& Opening){
	return Opening.display(Out);
}

// Default Constructor that initalizes all private data members
Opening::Opening(string Last, string First, int AccountNumber) : 
	// NOLINTNEXTLINE
	Transaction::Transaction(AccountNumber), LastName{ Last }, 
	// NOLINTNEXTLINE
	FirstName{ First } {} 

// Default Destructor
Opening::~Opening() = default;

// Returns LastName
string Opening::getLastName() const{
	return LastName;
}

// Returns FirstName
string Opening::getFirstName() const{
	return FirstName;
}

// Display method that displays all properties of a
// Opening Transaction
ostream& Opening::display(ostream& Out) const {
	Out << "Opening Transaction: ";
	Out << FirstName << " " << LastName << " " << AccountID;
	return Out;
}

