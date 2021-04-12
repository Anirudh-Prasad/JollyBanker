#include "accounttree.h"

// Insertion Opertator that calls inOrderWalk and goes through prints tree
ostream& operator<<(ostream& Out, const AccountTree& AccountTree) {
	return AccountTree.inOrderWalk(AccountTree.Root, Out);
}

// Default Constructor for BST
AccountTree::AccountTree() : Root{ nullptr } {}

// Delete all nodes in BST
AccountTree::~AccountTree() {
	clear();
}

// Traverses tree and adds Account Data to RetOst
// Returns RetOst ostream object once end of tree is reached
ostream& AccountTree::inOrderWalk(Node* Item, ostream& RetOst) const {
	if (Item == nullptr) {
		return RetOst;
	}

	inOrderWalk(Item->Left, RetOst);
	RetOst << *(Item->Account) << endl;
	inOrderWalk(Item->Right, RetOst);

	return RetOst;
}

// If the tree is empty, sets Root to new Node with Account item
// Else, calls RecInsert function to navigate tree and insert
bool AccountTree::insert(Account* Account) {
	if (isEmpty()) {
		Root = new Node(Account);
		return true;
	}

	return recInsert(Account, Root);
}

// Recusrively navigates tree and inserts new account
// No duplicates
bool AccountTree::recInsert(Account* Account, Node* Leaf) {
	int LeafAccountID =
		Leaf->Account->getAccountInfo().getAccountID();
	int TheAccountID =
		Account->getAccountInfo().getAccountID();

	if (TheAccountID < LeafAccountID) {
		if (Leaf->Left != nullptr) {
			return recInsert(Account, Leaf->Left);
		}
		Leaf->Left = new Node(Account);
		return true;
	// NOLINTNEXTLINE
	} else if (TheAccountID > LeafAccountID) {
		if (Leaf->Right != nullptr) {
			return recInsert(Account, Leaf->Right);
		}
		Leaf->Right = new Node(Account);
		return true;
		
	}

	cout << "Account " << TheAccountID 
		 << " is already open. Transaction refused." << endl;
	return false;
}

// Retrieve account
// returns true if successful AND *Account points to account
// NOLINTNEXTLINE
bool AccountTree::retrieve(const int& AccountNumber, Account*& Account) 
	const {

	Node* Currentptr = Root;

	while (Currentptr != nullptr) {
		int CurrAccountID =
			Currentptr->Account->getAccountInfo().getAccountID();

		if (AccountNumber == CurrAccountID) {
			Account = Currentptr->Account;
			return true;
		}

		if (AccountNumber > CurrAccountID) {
			Currentptr = Currentptr->Right;
		} else  {
			Currentptr = Currentptr->Left;
		}
	}

	return false;
}

// Goes through the AccountTree and deletes each Node
void AccountTree::destroyRecursive(Node* Node) {
	if (Node != nullptr) {
		destroyRecursive(Node->Left);
		destroyRecursive(Node->Right);
		delete Node->Account;
		delete Node;
	}
}

// Display information on all accounts
void AccountTree::display() const {
	inOrderWalk(Root, cout);
}

// Delete all information in AccountTree
void AccountTree::clear() {
	destroyRecursive(Root);
	Root = nullptr;
}

// Check if tree is empty
bool AccountTree::isEmpty() const {
	return Root == nullptr;
}
