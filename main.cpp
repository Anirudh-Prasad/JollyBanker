
#include "bank.h"
#include <iostream>
#include <string>


using namespace std;

// Used to test the Jolly Banker System
int main() {

    Bank Bank;
    // Note that tests were done in BankTransIn.txt
	Bank.processTransactions("BankTransIn.txt");
	cout << Bank << endl;

    cout << "Done" << endl;
    return 0;
}