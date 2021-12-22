#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include "Node.h"
class DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void addNewNodeToFront(Node* newNode);
	void addNewNodeToBack(Node* newnNde);
	Node* removeNodeFromFront();
	void removeNodeFromBack();
	void addNewNodeBeforeTargetNode(Node* newNode, int v);
	void displayDoublyLinkedList();
	bool isPalindrome();
	DoublyLinkedList* split(int i);
	void drawDoublyLinkedList();
private:
	Node* head;
	Node* tail;
};
#endif 
