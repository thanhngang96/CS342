#include "BSTree.h"



BSTree::BSTree()
{
	root = NULL;
}


BSTree::~BSTree()
{
	Empty();
}

//=============================================================================
//                            copy constructor
//
//=============================================================================
BSTree::BSTree(const BSTree &tree)
{
	root = NULL;
	copy(tree.root);
}

//=============================================================================
//                            copy(Node * node)
//recursively copy all node
//=============================================================================
void BSTree::copy(Node * node)
{
	if (node)
	{
		Insert(node->pAcct);
		copy(node->left);
		copy(node->right);
	}
}

//=============================================================================
//                            Insert(Account *pAcct)
//Insert an account to the tree
//=============================================================================
bool BSTree::Insert(Account *pAcct)
{
	if (pAcct->getAccountID() < 1000 || pAcct->getAccountID() > 9999)
	{
		cerr << "ERROR: Account ID is invalid" << endl;
		return false;
	}
	return Insert(this->root, pAcct);
}

//=============================================================================
//                            Insert(Node *&root, Account *pAcct)
//recursively find the right place to insert the account in the tree
//=============================================================================
bool BSTree::Insert(Node *&root, Account *pAcct)
{	
	if (root == NULL)
	{
		Node *temp = new Node;
		temp->pAcct = pAcct;
		root = temp;
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	else if (pAcct->getAccountID() < root->pAcct->getAccountID())
	{
		return Insert(root->left, pAcct);
	}
	else
	{
		return Insert(root->right, pAcct);
	}
}

bool BSTree::Retrieve(const int &accID, Account * &pAcct) const
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		Node *temp = this->root;
		return Retrieve(temp, accID, pAcct);
	}
}

//=============================================================================
//           Retrieve(Node *&root, const int &accID, Account * &pAcct)
//recursive call to find the account
//=============================================================================
bool BSTree::Retrieve(Node *&root, const int &accID, Account * &pAcct) const
{	

	if (root == NULL)
	{
		cerr << "ERROR: Account " << accID << " not found. Transferal refused." << endl;
		return false;
	}
	else
	{
		//stop looking when found the account
		if (accID == root->pAcct->getAccountID())
		{
			pAcct = root->pAcct;
			return true;
		}
		//go to the left branches to find the account
		else if (accID < root->pAcct->getAccountID())
		{
			return Retrieve(root->left, accID, pAcct);
		}
		//go to the left branches to find the account
		else
		{
			return Retrieve(root->right, accID, pAcct);
		}
	}

	return false;
}

//=============================================================================
//                            Empty()
//empties the tree
//=============================================================================
void BSTree::Empty()
{
	delete root;
	root = NULL;
}

//=============================================================================
//                             isEmpty() 
//checks if the tree is empty
//=============================================================================
bool BSTree::isEmpty() const
{
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//=============================================================================
//                     isAvailable(const int & accID) 
//checks if accountID is available to open new account
//=============================================================================
bool BSTree::isAvailable(const int & accID) const
{
	if (root != NULL)
	{
		Node *temp = new Node;
		temp = root;
		while ((temp->pAcct->getAccountID() != accID))
		{
			if (temp->pAcct->getAccountID() < accID)
			{
				if (temp->right != NULL)
				{
					temp = temp->right;
				}
				else
				{
					return true;
				}
			}
			else if (temp->pAcct->getAccountID() > accID)
			{
				if (temp->left != NULL)
				{
					temp = temp->left;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		return true;
	}
}

//=============================================================================
//                            Display()
//display the root of the tree
//=============================================================================
void BSTree::Display() const
{
	Node *temp = root;
	Display(temp);
}

//=============================================================================
//                            Display(Node* current)
//display the root of the tree
//=============================================================================
void BSTree::Display(Node* node) const
{
	//If node has children
	if (node->right != NULL && node->left != NULL)
	{
		//go to the right until node->right has no child on the right side.
		Display(node->right);

		//print out the account if can't go further.
		cout << *(node->pAcct) << endl;

		//go to the left until node->left has no child on the left side.
		Display(node->left);
	}

	//go to the left and print out the account if can't go further.
	else if (node->left != NULL)
	{
		cout << *(node->pAcct) << endl;
		Display(node->left);
	}

	//go to the right and print out the account if can't go further.
	else if (node->right != NULL)
	{
		cout << *(node->pAcct) << endl;
		Display(node->right);
	}

	//Display account node.
	else
	{
		cout << *(node->pAcct) << endl;
	}
}

//=============================================================================
//                            Remove(Account * pAcct)
//recursive call to find the account
//=============================================================================
bool BSTree::Remove(Account * pAcct)
{
	//check if the tree is empty
	if (isEmpty())
	{
		cout << " This Tree is empty! " << endl;
		return false;
	}

	Node* curNode;
	Node* parent = nullptr;
	curNode = root;
	bool found = false;

	//find the account to remove
	while (curNode != NULL)
	{
		if (curNode->pAcct == pAcct)
		{
			found = true;
			break;
		}
		else
		{
			parent = curNode;
			if (pAcct > curNode->pAcct)
			{
				curNode = curNode->right;
			}
			else
			{
				curNode = curNode->left;
			}
		}
	}
	if (!found)
	{
		cout << " Account not found! " << endl;
		return false;
	}

// removing a node with a single child
	if ((curNode->left == NULL && curNode->right != NULL)
		|| (curNode->left != NULL && curNode->right == NULL))
	{
		if (curNode->left == NULL && curNode->right != NULL)
		{
			if (parent->left == curNode)
			{
				parent->left = curNode->right;
				delete curNode;
				curNode = nullptr;
				return true;
			}
			else
			{
				parent->right = curNode->right;
				delete curNode;
				curNode = nullptr;
				return true;
			}
			return true;
		}
		// left child present, no right child
		else 
		{
			if (parent->left == curNode)
			{
				parent->left = curNode->left;
				delete curNode;
				curNode = nullptr;
				return true;
			}
			else
			{
				parent->right = curNode->left;
				delete curNode;
				curNode = nullptr;
				return true;
			}
			return true;
		}
		return true;
	}

	//removing a leaf node
	if (curNode->left == NULL && curNode->right == NULL)
	{
		if (parent->left == curNode)
		{
			parent->left = NULL;
			return true;
		}
		else
		{
			parent->right = NULL;
			return true;
		}
		delete curNode;
		curNode = nullptr;
		return true;
	}


	//removing a node with 2 children
	// replace node with smallest value in right subtree
	if (curNode->left != NULL && curNode->right != NULL)
	{
		Node* chkr;
		chkr = curNode->right;
		if ((chkr->left == NULL) && (chkr->right == NULL))
		{
			curNode = chkr;
			delete chkr;
			curNode->right = NULL;
			return true;
		}
		// right child has children
		else 
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element

			if ((curNode->right)->left != NULL)
			{
				Node* lcurNode;
				Node* lcurNodep;
				lcurNodep = curNode->right;
				lcurNode = (curNode->right)->left;
				while (lcurNode->left != NULL)
				{
					lcurNodep = lcurNode;
					lcurNode = lcurNode->left;
				}
				curNode->pAcct = lcurNode->pAcct;
				delete lcurNode;
				lcurNodep->left = NULL;
				return true;
			}
			else
			{
				Node* tmp;
				tmp = curNode->right;
				curNode->pAcct = tmp->pAcct;
				curNode->right = tmp->right;
				delete tmp;
				tmp = nullptr;
				return true;
			}
			return false;
		}
		return false;
	}

}
