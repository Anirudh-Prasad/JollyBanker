#ifndef ASS5_OPENING_H
#define ASS5_OPENING_H

#include "transaction.h"

using namespace std;

class Opening : public Transaction {
	// Overloaded Insertion Operator to display Opening objects
	friend ostream& operator<<(ostream& Out, const Opening& Opening);

public:
	// Default Constructor
	explicit Opening(string Last = "ERROR", 
		string First = "ERROR", int AccountNumber = -1);
	// Default Destructor
	~Opening() override;
	// Getter for LastName
	string getLastName() const;
	// Getter for FirstName
	string getFirstName() const;
	// Overridden display method to display Opening object contents
	ostream& display(ostream& Out) const override;

private:
	string LastName;
	string FirstName;
};

#endif

