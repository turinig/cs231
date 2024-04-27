


// 140C-SimpleMinHeapUsingStructure.c
// Giuseppe Turini
// CS-231
// 2024-04-25

#include <stdio.h> // Importing standard input/output library (for "printf" etc.).
#include <stdbool.h> // For bool macro.

#include "./Include/SimpleMinHeap.h"


// Testing a simple min-heap implemented using a structure.
int main() {
	SimpleMinHeap h; // Declaring a SMH variable.

	// Initialize the SMH, then print SMH.
	smhInit(&h);
	smhPrint(&h, true);

	// Perform few insertions in SMH, then print SMH.
	smhInsert(&h, 77);
	smhInsert(&h, 27);
	smhInsert(&h, 42);
	smhInsert(&h, 30);
	smhInsert(&h, 17);
	smhPrint(&h, true);

	// Perform few extractions from SMH, then print SMH.
	int res1 = smhExtractMin(&h);
	printf("MIN-HEAP: extracted value %i\n", res1);
	smhPrint(&h, true);
	int res2 = smhExtractMin(&h);
	printf("MIN-HEAP: extracted value %i\n", res2);
	smhPrint(&h, true);

	return 0; // Normal exit.
}


