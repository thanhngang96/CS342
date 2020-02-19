#include "Account.h"

class BSTree
{
public:
	BSTree();
	~BSTree();
	BSTree(const BSTree &tree);
	bool Insert(Account *pAcct);
	bool Retrieve(const int & accID, Account * &pAcct) const;
	void Display() const;
	void Empty();
	bool isEmpty() const;
	bool isAvailable(const int & accID) const;
	bool Remove(Account* pAcct);

private:
	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;
	};
	Node *root = NULL;

	void copy(Node * node);
	bool Insert(Node *&root, Account *pAcct);
	bool Retrieve(Node *&root, const int &accID, Account * &pAcct) const;
	void Display(Node * current) const;
};
