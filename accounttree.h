
#ifndef ASS5_ACCOUNTTREE_H
#define ASS5_ACCOUNTTREE_H

//NOLINTNEXTLINE
#include "account.h"
#include "deposit.h"
#include "opening.h"
#include "transfer.h"
#include "withdraw.h"
#include <iostream>

using namespace std;

class AccountTree {

	// Insertion operator displays all nodes in tree
	friend ostream& operator<<(ostream& Out, const AccountTree& AccountTree);

private:

	// Node struct for BinaryTree
	struct Node {

		// Node constructor that takes in Account pointer
		explicit Node(Account* Account)
			: Account{ Account }, Right{ nullptr }, Left{ nullptr } {};

		Account* Account;
		Node* Right;
		Node* Left;
	};

	Node* Root;

	// Recursively destory each tree Node
	void destroyRecursive(Node* Node);

	// Resursively inserts new account
	bool recInsert(Account* Account, Node* Leaf);

public:
	// Create BST
	AccountTree();

	// Delete all nodes in BST
	~AccountTree();

	// Insert new account
	bool insert(Account* Account);

	// Retrieve account
	// returns true if successful AND *Account points to account
	// NOLINTNEXTLINE
	bool retrieve(const int& AccountNumber, Account*& Account) const;

	// Display information on all accounts
	void display() const;

	// Traverses tree in order of root, left, right
	ostream& inOrderWalk(Node* Item, ostream& RetOst) const;

	// Delete all information in AccountTree
	void clear();

	// Check if tree is empty
	bool isEmpty() const;

};
#endif // ASS5_ACCOUNTTREE_H
