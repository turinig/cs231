


// SimpleMinHeap.h
// Giuseppe Turini
// CS-231
// 2024-04-25



#ifndef INCLUDE_SIMPLEMINHEAP_H_
#define INCLUDE_SIMPLEMINHEAP_H_



#include <stdio.h> // For printf function.
#include <stdbool.h> // For bool macro.

// Symbolic constants (macros).
#define MIN_HEAP_PHYSICAL_SIZE 10

// Structures.
typedef struct SimpleMinHeapStruct {
	int array[MIN_HEAP_PHYSICAL_SIZE];
	int sizeLogical;
	int sizePhysical;
} SimpleMinHeap;

// Initializes input heap pointer.
// Note: Top min-heap item is at index 0.
void smhInit(SimpleMinHeap *hp) {
	// Check if input heap pointer is valid.
	if( hp != NULL) {
		// Init heap-array items, and sizes.
		for(int i = 0; i < MIN_HEAP_PHYSICAL_SIZE; i++) { hp->array[i] = 0; }
		hp->sizeLogical = 0;
		hp->sizePhysical = MIN_HEAP_PHYSICAL_SIZE;
	}
	else { return; } // Input heap pointer invalid, do nothing.
}

// Checks if input min-heap (pointer hp) is empty.
// Note: Assuming input heap pointer (hp) valid (not NULL).
bool smhIsEmpty(SimpleMinHeap *hp) { return (hp->sizeLogical == 0); }

// Checks if input min-heap (pointer hp) is full.
// Note: Assuming input heap pointer (hp) valid (not NULL).
bool smhIsFull(SimpleMinHeap *hp) { return (hp->sizeLogical == hp->sizePhysical); }

// Returns index of parent of heap node in input (index).
// Note: Top min-heap item is at index 0.
int smhGetParentIndex(int i) { return (i - 1) / 2; }

// Returns index of left child of heap node in input (index).
// Note: Top min-heap item is at index 0.
int smhGetLeftChildIndex(int i) { return (2 * i) + 1; }

// Returns index of right child of heap node in input (index).
// Note: Top min-heap item is at index 0.
int smhGetRightChildIndex(int i) { return (2 * i) + 2; }

// Inserts the input item (data) in the input heap (a) at the appropriate position (last heap index free is n).
// Note: Top min-heap item is at index 0.
// Note: Iterative implementation.
void smhInsert(SimpleMinHeap *hp, int v) {
	// Check if input heap pointer is valid.
	if(hp != NULL) {
		// Input heap pointer valid.
		// Check if input heap is full.
		if(smhIsFull(hp)) {
			// Heap full, print error, and exit.
			printf("MIN-HEAP: heap full, cannot insert!\n");
			return; }
		else {
			// Heap not full, perform insertion.
			// Insert input item (v) at last heap position (hp->sizeLogical).
			hp->array[ hp->sizeLogical ] = v;
			hp->sizeLogical++;
			// Swap up new item as needed.
			int indexNewItem = hp->sizeLogical - 1;
			int indexParent = smhGetParentIndex(indexNewItem);
			while( (indexNewItem > 0) &&
				   (hp->array[ indexParent ] > hp->array[indexNewItem]) ) {
				// Swap new item with its parent.
				int temp = hp->array[indexNewItem];
				hp->array[indexNewItem] = hp->array[ indexParent ];
				hp->array[ indexParent ] = temp;
				// Update indices (new item and its parent.
				indexNewItem = indexParent;
			    indexParent = smhGetParentIndex(indexNewItem);
			} // End while.
		} // End if-else.
	}
	else {
		// Input heap pointer invalid, print error, and exit.
		printf("MIN-HEAP: heap pointer invalid, cannot insert!\n");
		return;
	} // End if-else.
}

// Swaps up or down heap item at input index (i) in input min-heap (pointer hp), until appropriate position is reached.
// Note: Top min-heap item is at index 0.
// Note: Recursive implementation.
void smhHeapifyIndex(SimpleMinHeap *hp, int i){
	// Check if input heap pointer is valid.
	if(hp != NULL) {
		// Check if input index is valid.
		if((0 <= i) && (i < hp->sizeLogical)) {
			// Get indices of children and parent of input index (i).
			int indexParent = smhGetParentIndex(i);
			int indexLeftChild = smhGetLeftChildIndex(i);
			int indexRightChild = smhGetRightChildIndex(i);
			// Check if swap up is needed.
			if( (i > 0) && (hp->array[indexParent] > hp->array[i]) ) {
				// Here, i has a parent and its parent is smaller, swap i and its parent.
				int temp = hp->array[indexParent];
				hp->array[indexParent] = hp->array[i];
				hp->array[i] = temp;
				// Proceed swapping up recursively.
				smhHeapifyIndex(hp, indexParent); // Recursive call.
			}
			// Swap up NOT needed, check is swap down is needed.
			else {
				// Find the smallest child of i.
				if( indexRightChild < hp->sizeLogical ) {
					// Here, i has both children, determine smallest child.
					int indexSmallestChild = indexLeftChild;
					if(hp->array[indexLeftChild] > hp->array[indexRightChild]) { indexSmallestChild = indexRightChild; }
					// Check if swap down between i and its smallest child is needed.
					if(hp->array[indexSmallestChild] < hp->array[i]) {
						// Here, smallest child of i is smaller than i, swap i and its smallest child.
						int temp = hp->array[indexSmallestChild];
						hp->array[indexSmallestChild] = hp->array[i];
						hp->array[i] = temp;
						// Proceed swapping down recursively.
						smhHeapifyIndex(hp, indexSmallestChild); // Recursive call.
					}
					else { return; } // No swap down needed, do nothing.
				}
				else if( indexLeftChild < hp->sizeLogical ) {
					// Here, i has only left child, check if swap down between i and its left child is needed.
					if(hp->array[indexLeftChild] < hp->array[i]) {
						// Here, left child of i is smaller, swap i and its left child.
						int temp = hp->array[indexLeftChild];
						hp->array[indexLeftChild] = hp->array[i];
						hp->array[i] = temp;
						// Proceed swapping down recursively.
						smhHeapifyIndex(hp, indexLeftChild); // Recursive call.
					}
					else { return; } // No swap down needed, do nothing.
				}
				else { return; } // Here, i has no children, do nothing.
			} // End if-else.
		}
		else {
			// Input index invalid, print error, and exit.
			printf("MIN-HEAP: heap index invalid, cannot heapify index!\n");
			return;
		} // End if-else.
	}
	else {
		// Input heap pointer invalid, print error, and exit.
		printf("MIN-HEAP: heap pointer invalid, cannot heapify index!\n");
		return;
	} // End if-else.
}

// Returns the min item of input min-heap (pointer hp).
// Note: returns -1 (error code) if input heap is empty or invalid.
// Note: Top min-heap item is at index 0.
int smhGetMin(SimpleMinHeap *hp) {
	// Check if input heap pointer is valid.
	if(hp != NULL) {
		// Check if input index is valid.
		if(hp->sizeLogical > 0) {
			return hp->array[0];
		}
		else {
			// Input index invalid, print error, and exit.
			printf("MIN-HEAP: heap empty, no min item!\n");
			return -1;
		} // End if-else.
	}
	else {
		// Input heap pointer invalid, print error, and exit.
		printf("MIN-HEAP: heap pointer invalid, no min item!\n");
		return -1;
	} // End if-else.
}

// Extract (removal + return) the min item of input min-heap (pointer hp).
// Note: Top min-heap item is at index 0.
int smhExtractMin(SimpleMinHeap *hp) {
	// Check if input heap pointer is valid.
	if(hp != NULL) {
		// Check if input index is valid.
		if(hp->sizeLogical > 0) {
			// Extract min item.
			int result = hp->array[0]; // Get min item.
			// Replace topmost heap item (min) with last heap (array) item.
			hp->array[0] = hp->array[ hp->sizeLogical - 1 ];
			hp->array[ hp->sizeLogical - 1 ] = 0; // Optional.
			hp->sizeLogical--;
			// Swap down (recursively) new heap topmost item.
			smhHeapifyIndex(hp, 0);
			// Returning extracted min.
			return result;
		}
		else {
			// Input index invalid, print error, and exit.
			printf("MIN-HEAP: heap empty, no min item!\n");
			return -1;
		} // End if-else.
	}
	else {
		// Input heap pointer invalid, print error, and exit.
		printf("MIN-HEAP: heap pointer invalid, no min item!\n");
		return -1;
	} // End if-else.
}

// Prints heap on console, using input heap pointer (hp).
void smhPrint(SimpleMinHeap *hp, bool debug) {
	// Check if input heap pointer is valid.
	if( hp != NULL) {
		printf("MIN-HEAP: ");
		for(int i = 0; i < hp->sizeLogical; i++) { printf("%d ", hp->array[i]); }
		if(debug) { for(int i = hp->sizeLogical; i < hp->sizePhysical; i++) { printf("_ "); } }
		printf("\n");
	}
	else { printf("MIN-HEAP: invalid!\n"); }
}



#endif // End #ifndef INCLUDE_SIMPLEMINHEAP_H_


