


// LinkedList.h
// Giuseppe Turini
// CS-231
// 2024-04-22

#ifndef INCLUDE_LINKEDLIST_H_
#define INCLUDE_LINKEDLIST_H_

#include <stddef.h> // For NULL macro.
#include <stdlib.h> // For malloc function.
#include <stdio.h> // For printf function.

// Type definition (LinkedListNode) based on declaration of another type (LinkedListNodeStruct, defined later).
typedef struct LinkedListNodeStruct LinkedListNode;

// Structure representing a node of the linked list (definition).
struct LinkedListNodeStruct {
	int data;
	LinkedListNode* next;
};

// Structure representing a linked list.
typedef struct LinkedListStruct {
	LinkedListNode* head;
	int size;
} LinkedList;

// Initializes the linked list in input.
void linkedListInit(LinkedList* llp) {
	llp->head = NULL;
	llp->size = 0;
}

// Prints the linked list on the console.
// Note: Assuming input pointer valid.
void linkedListPrint(LinkedList* llp) {
	LinkedListNode* p = llp->head;
	printf("\n[ ");
	// Iterate list nodes.
	while(p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	//for(int i = 1; i <= llp->size; i++) {
	//	printf("%d ", p->data);
	//	p = p->next;
	//}
	printf("]");
	//fflush(stdout);
}

// Inserts input item at front of input linked list.
// Note: Assuming input pointer valid.
void linkedListInsertAtFront(LinkedList* llp, int i) {
	// Create a new node: allocate memory, and initialize its data.

	LinkedListNode* newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));

	//LinkedListNode newNodeStruct; // ERROR: Local var auto-destroyed at end, undetermined behavior!
	//LinkedListNode* newNode = &newNodeStruct;

	newNode->data = i;
	newNode->next = NULL; // Optional.
	// Link new node to rest of input list, and update input list.
	newNode->next = llp->head;
	llp->head = newNode;
	llp->size++;
}

// Inserts input item at back of input linked list.
// Note: Assuming input pointer valid.
void linkedListInsertAtBack(LinkedList* llp, int i) {
	// Create a new node: allocate memory, and initialize its data.
	LinkedListNode* newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
	newNode->data = i;
	newNode->next = NULL;
	if(llp->size == 0) {
		llp->head = newNode;
		llp->size++;
	}
	else {
		// Iterate list nodes.
		LinkedListNode* currNode = llp->head;
		while(currNode->next != NULL) {
			currNode = currNode->next;
		}
		currNode->next = newNode;
		llp->size++;
	}
}

// Deletes item at front of input linked list, and returns it.
// Note: Assuming input pointer valid AND input list not empty.
int linkedListDeleteAtFront(LinkedList* llp) {
	int res = llp->head->data;
	LinkedListNode* toBeDeletedNode = llp->head;
	llp->head = llp->head->next;
	llp->size--;
	free(toBeDeletedNode);
	return res;
}

// Deletes item at back of input linked list, and returns it.
// Note: Assuming input pointer valid AND input list not empty.
int linkedListDeleteAtBack(LinkedList* llp) {
	// Check special case: list size =1, head affected.
	if(llp->size == 1) {
		int res = llp->head->data;
		LinkedListNode* toBeDeletedNode = llp->head;
		llp->head = NULL;
		llp->size--;
		free(toBeDeletedNode);
		return res;
	}
	else {
		// List size >1, head NOT affected.
		// Iterate list nodes.
		LinkedListNode* currNode = llp->head;
		LinkedListNode* prevNode = NULL;
		while(currNode->next != NULL) {
			prevNode = currNode;
			currNode = currNode->next;
		}
		// currNode is last list node.
		int res = currNode->data;
		LinkedListNode* toBeDeletedNode = currNode;
		free(toBeDeletedNode);
		prevNode->next = NULL;
		llp->size--;
		return res;
	}
}

// Deletes the linked list in input.
void linkedListDelete(LinkedList* llp) {
	while(llp->size != 0) {
		linkedListDeleteAtFront(llp);
	}
}

#endif // End INCLUDE_LINKEDLIST_H_


