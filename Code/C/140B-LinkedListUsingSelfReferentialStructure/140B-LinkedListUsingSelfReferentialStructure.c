


// 140B-LinkedListUsingSelfReferentialStructure.c
// Giuseppe Turini
// CS-231
// 2024-04-22

#include <stdio.h> // For printf function.

#include "./Include/LinkedList.h" // C implementation of a singly linked list.

// Testing linked list.
int main() {
	// Example of usage of the LinkedList
	LinkedList l;
	linkedListInit(&l);
	linkedListInsertAtFront(&l, 12);
	linkedListInsertAtFront(&l, 34);
	linkedListInsertAtBack(&l, 56);
	linkedListInsertAtFront(&l, 78);
	linkedListInsertAtBack(&l, 90);

	linkedListPrint(&l);
	//fflush(stdout); // Force printf to print (otherwise is buffered).

	linkedListDeleteAtFront(&l);
	linkedListDeleteAtBack(&l);

	linkedListPrint(&l);
	//fflush(stdout); // Force printf to print (otherwise is buffered).

	linkedListDelete(&l);

	linkedListPrint(&l);
	//fflush(stdout); // Force printf to print (otherwise is buffered).

	return 0; // Default return value for successful execution.
}


