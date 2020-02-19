
#include "List342.h"
#include "Child.h"


////==================================================================//
////                                                                  //
////                                                                  //
////                     FUNCTION DEFINITIONS                         //
////                                                                  //
////                                                                  //
////==================================================================//
//
////==================================================================//
////                     Default constructor                          //
////                                                                  //
////==================================================================//
//template <class ItemType>
//List342<ItemType>::List342()
//{
//	head = NULL;
//}
//
////==================================================================//
////              Constructor get input from file                     //
////                                                                  //
////==================================================================//
//template <class ItemType>
//List342<ItemType>::List342(string fileName)
//{
//	BuildList(fileName);
//}
//
////==================================================================//
////                       Destructor                                 //
////                                                                  //
////==================================================================//
//template<class ItemType>
//List342<ItemType>::~List342()
//{
//	DeleteList();
//}
//
////==================================================================//
////                    Copy Constructor                              //
////                                                                  //
////==================================================================//
//template<class ItemType>
//List342<ItemType>::List342(List342<ItemType> & obj)
//{
//	this->head = NULL;
//	*this = obj;
//}
//
////==================================================================//
////                         Build List                               //
////                                                                  //
////==================================================================//
//template <class ItemType>
//bool List342<ItemType>::BuildList(string fileName)
//{
//	ifstream inFile;
//	inFile.open(fileName);
//	if (!inFile.is_open())
//	{
//		cout << "File " << fileName << " can't be found!" << endl;
//		return false;
//	}
//	else
//	{
//		bool reachedEndOfFile = false;
//		ItemType* obj = new ItemType;
//		while (!reachedEndOfFile)
//		{
//			inFile >> *obj;
//			Insert(obj);
//			if (inFile.eof())
//			{
//				delete obj;
//				obj = NULL;
//				reachedEndOfFile = true;
//			}
//		}
//		inFile.close();
//		return true;
//	}
//}
//
////==================================================================//
////                         Insert                                   //
////                                                                  //
////==================================================================//
//template <class ItemType>
//bool List342<ItemType>::Insert(ItemType* obj)
//{
//	Node *preNode, *curNode;
//
//	//return false if obj isn't pointing to anything.
//	if (obj == NULL)
//	{
//		return false;
//	}
//
//
//	Node* temp = new Node();
//	temp->data = new ItemType(*obj);
//
//
//	//place item in order.
//	if (head == NULL || *temp->data < *head->data)
//	{
//		temp->next = head;
//		head = temp;
//		temp = NULL;
//		return true;
//	}
//
//	preNode = head;
//	curNode = preNode->next;
//	//travel through the list with two pointers 
//	while ((curNode != NULL) && (*curNode->data <= *temp->data))
//	{
//		preNode = curNode;
//		curNode = curNode->next;
//	}
//
//	//return false if duplicates found
//	if (*preNode->data == *temp->data)
//	{
//		delete temp;
//		temp = NULL;
//		return false;
//	}
//
//	temp->next = curNode;
//	preNode->next = temp;
//
//	temp = NULL;
//	preNode = NULL;
//	curNode = NULL;
//
//	return true;
//}
//
////==================================================================//
////                         Remove                                   //
////                                                                  //
////==================================================================//
//template <class ItemType>
//bool List342<ItemType>::Remove(ItemType target, ItemType & result)
//{
//	//Remove unsuccessfully if the list is empty.
//	if (isEmpty())
//	{
//		return false;
//	}
//	Node *temp, *desNode;
//	ItemType *dItem;
//	if (*head->data == target)
//	{
//		result = target;
//		desNode = head;
//		dItem = head->data;
//		head = head->next;
//		delete dItem;
//		delete desNode;
//		dItem = NULL;
//		desNode = NULL;
//		return true;
//	}
//	else
//	{
//		temp = head;
//		while (temp->next != NULL && *temp->next->data != target)
//		{
//			temp = temp->next;
//		}
//		if (temp->next == NULL)
//		{
//			return false;
//		}
//		else
//		{
//			result = target;
//			desNode = temp->next;
//			dItem = desNode->data;
//			temp->next = temp->next->next;
//			delete dItem;
//			delete desNode;
//			dItem = NULL;
//			desNode = NULL;
//			return true;
//		}
//	}
//}
//
////==================================================================//
////                           Peek                                   //
////                                                                  //
////==================================================================//
//template <class ItemType>
//bool List342<ItemType>::Peek(ItemType target, ItemType & result) const
//{
//	//check if empty list.
//	if (head == NULL)
//	{
//		return false;
//	}
//
//	if (*head->data == target)
//	{
//		result = target;
//		return true;
//	}
//	Node* curNode = head;
//	while (curNode->next != NULL)
//	{
//		if (*curNode->next->data == target)
//		{
//			result = *curNode->next->data;
//			return true;
//		}
//		curNode = curNode->next;
//	}
//	return false;
//}
//
////==================================================================//
////                          isEmpty                                 //
////                                                                  //
////==================================================================//
//template <class ItemType>
//bool List342<ItemType>::isEmpty() const
//{
//	return (head == NULL);
//}
//
////==================================================================//
////                         Delete List                              //
//// Goes through the list and delete nodes.                          //
////==================================================================//
//template <class ItemType>
//void List342<ItemType>::DeleteList()
//{
//	if (head == NULL)
//	{
//		return;
//	}
//	else
//	{
//		while (head != NULL)
//		{
//			Node* temp = head;
//			head = head->next;
//			delete temp->data;
//			delete temp;
//		}
//
//		head = NULL;
//		return;
//	}
//}
//
////==================================================================//
////                       Merge two list                             //
////                                                                  //
////==================================================================//
//template <class ItemType>
//bool List342<ItemType>::Merge(List342 & list1)
//{
//	//return false if both lists are empty or duplicated.
//	if ((list1.head == NULL) || (this == &list1))
//	{
//		return false;
//	}
//	//make list1 the new list and return false if the current list is empty
//	if ((head == NULL) && (list1.head != NULL))
//	{
//		head = list1.head;
//		list1.head = NULL;
//		return true;
//	}
//	Node* list2 = head;
//	head = NULL;
//	Node* mergedList = list1.head;
//	list1.head = NULL;
//	Node temp;
//	Node* curNode = &temp;
//	//merging while sorting two lists.
//	while ((list2 != NULL) && (mergedList != NULL))
//	{
//		//go to list 2, pick and compare to the merged list.
//		if ((*list2->data) < (*mergedList->data))
//		{
//			curNode->next = list2;
//			list2 = list2->next;
//		}
//
//		//skip node when seeing duplicate
//		else if ((*list2->data) == (*mergedList->data))
//		{
//			curNode->next = list2;
//			list2 = list2->next;
//			//delete and eallocate the dangling pointer to duplicated node. 
//			Node* dupNode = mergedList;
//			mergedList = mergedList->next;
//			delete dupNode->data;
//			delete dupNode;
//		}
//		else
//		{
//			curNode->next = mergedList;
//			mergedList = mergedList->next;
//		}
//		curNode = curNode->next;
//	}
//	if (list2 != NULL)
//	{
//		curNode->next = list2;
//	}
//	if (mergedList != NULL)
//	{
//		curNode->next = mergedList;
//	}
//	head = temp.next;
//	return true;
//}
//
////==================================================================//
////                   Assignment operator                            //
////                                                                  //
////==================================================================//
//template <class ItemType>
//const List342<ItemType>& List342<ItemType>::operator=(const List342<ItemType> &obj)
//{
//	Node *sNode, *desNode, *insNode;
//	ItemType insItem;
//	//check for self-assignment
//	if (this == &obj) {
//		return *this;
//	}
//	DeleteList();
//	if (obj.head == NULL) {
//		return *this;
//	}
//	sNode = obj.head;
//	insItem = *(sNode->data);
//
//	//allocate new memory for a deep copy
//	desNode = new Node;
//	desNode->data = new ItemType(insItem);
//	this->head = desNode;
//	sNode = sNode->next;
//
//	while (sNode != NULL)
//	{
//		insItem = *(sNode->data);
//		insNode = new Node;
//		insNode->data = new ItemType(insItem);
//		desNode->next = insNode;
//		desNode = desNode->next;
//		sNode = sNode->next;
//	}
//	desNode->next = NULL;
//	return *this;
//}
//
//
////==================================================================//
////                 Overloading Operator+=                           //
////                                                                  //
////==================================================================//
//template<class ItemType>
//List342<ItemType>& List342<ItemType>::operator+=(const List342& rhs)
//{
//	if ((this->head == NULL) && (rhs.head == NULL))
//	{
//		cout << "Both lists are empty!" << endl;
//		return *this;
//	}
//	//check if right hand side is the empty list.
//	if (rhs.head == NULL)
//	{
//		return *this;
//	}
//	Node* insNode = rhs.head;
//	while (insNode != NULL)
//	{
//		Insert(insNode->data);
//		insNode = insNode->next;
//	}
//	return *this;
//}
//
////==================================================================//
////                   Overloading Operator+                          //
////                                                                  //
////==================================================================//
//template<class ItemType>
//List342<ItemType> List342<ItemType>::operator+(const List342<ItemType>& rhs) const
//{
//	ItemType insNode;
//	insNode = *this;
//	insNode += rhs;
//	return insNode;
//}
//
////==================================================================//
////                  Overloading Operator==                          //
////                                                                  //
////==================================================================//
//template<class ItemType>
//bool List342<ItemType>::operator==(const List342& source) const
//{
//	Node* lhs = this->head;
//	Node* rhs = source.head;
//	if (lhs == NULL && rhs == NULL)
//	{
//		return true;
//	}
//	if ((lhs == NULL && rhs != NULL)
//		|| (lhs != NULL && rhs == NULL))
//	{
//		return false;
//	}
//	if (*lhs->data != *rhs->data)
//	{
//		return false;
//	}
//	if (lhs->next != NULL || rhs->next != NULL)
//	{
//		return false;
//	}
//	while ((lhs->next != NULL) && (rhs->next != NULL))
//	{
//		if (*lhs->data != *rhs->data)
//		{
//			return false;
//		}
//		else
//		{
//			lhs = lhs->next;
//			rhs = rhs->next;
//		}
//	}
//	if (lhs->next != NULL || rhs->next != NULL)
//	{
//		return false;
//	}
//	lhs = NULL;
//	rhs = NULL;
//	return true;
//}
//
////==================================================================//
////                 Overloading Operator!=                           //
////                                                                  //
////==================================================================//
//template<class ItemType>
//bool List342<ItemType>::operator!=(const List342& rhs)const
//{
//	Node* lhs = this->head;
//	Node* lhs = this->head;
//	if (lhs == rhs)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}