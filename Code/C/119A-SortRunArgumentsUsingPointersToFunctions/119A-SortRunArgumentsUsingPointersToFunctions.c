


// 119A-SortRunArgumentsUsingPointersToFunctions.c
// Giuseppe Turini
// CS-231
// 2024-04-18

#include <stdio.h> // For printf function etc.
#include <string.h> // For strcmp function etc.
#include <stdbool.h> // For bool macro.
#include <stdlib.h> // For atof function.

#define MAXLINES 5000 // Macro: max num of run arguments to be sorted.

// Function declarations (prototypes).
void writeLines(char *linesPointers[], int numLines); // ...
void quickSort(char *linesPointers[], int left, int right, int (*comp)(void *v1, void *v2)); // Note: Pointer to function among inputs.
void swap(char *v[], int i, int j); // ...
int numcmp(char *s1, char *s2); // ...

// External variables.
char *linesPointers[MAXLINES]; // Array of pointers to text lines to be sorted.

// Sorting run arguments using quicksort and custom comparison function.
int main(int argc, char *argv[]) {
	// Check if run arguments are 2 or more (skip 1st run argument).
	if(argc > 1) {
		// Transfer run arguments from argv into linesPointers.
		int numLines = 0;
		for(int i = 1; i < argc; i++) {
			linesPointers[i - 1] = argv[i];
			numLines++;
		}
		// Sort linesPointers array using quicksort with custom comparison function.
		bool numericComparison = true; // Change this flag to select numeric/string comparison used by quicksort.
		if(numericComparison) {
			printf("Sorting run arguments using numeric comparison...\n");
			fflush(stdout);
			quickSort(linesPointers, 0, numLines - 1, (int (*)(void*, void*)) numcmp); } // Casting pointer to function (numcmp).
		else {
			printf("Sorting run arguments using lexicographic comparison...\n");
			fflush(stdout);
			quickSort(linesPointers, 0, numLines - 1, (int (*)(void*, void*)) strcmp); } // Casting pointer to function (numcmp).
		// Write content of sorted array linesPointers on console.
		writeLines(linesPointers, numLines);
		return 0; } // Normal exit.
	else {
		// Here, run arguments are less than 2, nothing to process...
		printf("ERROR: Nothing to process...\n");
		fflush(stdout);
		return 1; } // Abnormal exit.
}

// Write input text lines on console (function definition).
void writeLines(char *linesPointers[], int numLines) {
	// Iteration to print text lines on console
	for(int i = 0; i < numLines; i++) { printf("%s\n", linesPointers[i]); }
	fflush(stdout);
}

// Sort input array increasingly (function definition).
// Note: Recursive implementation, divide-by-2-and-conquer.
void quickSort(char *linesPointers[], int left, int right, int (*comp)(void *v1, void *v2)) {
	// Check if input array partition contains less than 2 items, then do nothing.
	if(left >= right) { return; }
	else {
		// Here, input array partition stores 2 or more items.
		swap(linesPointers, left, ((left + right) / 2));
		int last = left;
		for(int i = left + 1; i <= right; i++) {
			// Perform custom comparison of items.
			if((*comp)(linesPointers[i], linesPointers[left]) < 0) { // Using pointer to function.
				swap(linesPointers, ++last, i);
			}
		}
		// ...
		swap(linesPointers, left, last);
		// Recursive calls, divide-by-2-and-conquer.
		quickSort(linesPointers, left, last - 1, comp);
		quickSort(linesPointers, last + 1, right, comp);
	}
}

// Swap v[i] with v[j] (function definition).
void swap(char *v[], int i, int j) {
	char *temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

// Compares input strings with a leading numeric value.
int numcmp(char *s1, char *s2) {
	// Converting strings to numbers.
	double v1 = atof(s1); // Converts an ASCII string into a floating-point value.
	double v2 = atof(s2); // Converts an ASCII string into a floating-point value.
	// Numeric comparison (3-way comparison).
	if(v1 < v2) { return -1; } // Return -1 if comparison is less-than.
	else if(v1 > v2) { return 1; } // Return 1 if comparison is greater-than.
	else { return 0; } // Return 0 if comparison is equal.
}


