#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP
#include "doublylinkedlist.h"
DoublyLinkedList::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
}
DoublyLinkedList::~DoublyLinkedList()
{
	// CODE TO BE ADDED for Project 1 - Done!
	while (head != tail->next) {
		removeNodeFromFront();
	}
}
void DoublyLinkedList::addNewNodeToFront(Node * newNode) {
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}
void DoublyLinkedList::addNewNodeToBack(Node * newNode) {
	if (head == NULL && tail == NULL) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}
Node* DoublyLinkedList::removeNodeFromFront()
{
	Node *tempNode;
	tempNode = head;
	head = head->next;
	return tempNode;
}
void DoublyLinkedList::displayDoublyLinkedList()
{
	Node *tempNode;
	tempNode = head;
	while (tempNode != NULL)
	{
		cout << tempNode->value << " ";
		tempNode = tempNode->next;
	}
}
void DoublyLinkedList::drawDoublyLinkedList()
{
	// CODE TO BE ADDED for Project 1 - Done!
	// Reuse displayDoublyLinkedList()
	Node *tempNode;
	tempNode = head;
	while (tempNode != nullptr)
	{
		cout << "address: " << tempNode << ", prev: " << tempNode->prev << ", value: " << tempNode->value << ", next: " << tempNode->next << "]\n";
		tempNode = tempNode->next;
	}
}
bool DoublyLinkedList::isPalindrome()
{
	// CODE TO BE ADDED for Project 1 - Done!
	Node *tempNode;
	tempNode = head;

	if (tempNode == NULL)
		return true;
	//while (tail->next != NULL)
		//tail = tail->next;

	while (head != tail)
	{
		if (head->value != tail->value)
			return false;

		head = head->next;
		tail = tail->prev;
	}

	return true;
}
DoublyLinkedList* DoublyLinkedList::split(int i)
{
	// CODE TO BE ADDED for Project 1 - Done!
	DoublyLinkedList* temp;
	temp = new DoublyLinkedList;

	for (int iter = 0; iter <= i; iter++)
	{
		Node* tempNode;
		tempNode = new Node;
		if (head != nullptr)
		{
			tempNode->value = head->value;
			removeNodeFromFront();
			temp->addNewNodeToBack(tempNode);
		}
	}
	return temp;
}
void DoublyLinkedList::addNewNodeBeforeTargetNode(Node* newNode, int v)
{
	Node *tempNode;
	tempNode = head;

	while (tempNode != NULL)
	{
		if (tempNode->value == v)
			break;
		else
			tempNode = tempNode->next;
	}

	if (tempNode == head)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else
	{
		if (tempNode != NULL)
		{
			newNode->prev = tempNode->prev;
			tempNode->prev->next = newNode;
			newNode->next = tempNode;
			tempNode->prev = newNode;
		}
	}
}
#endif 