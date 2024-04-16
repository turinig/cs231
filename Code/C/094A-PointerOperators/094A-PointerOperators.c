


// 094A-PointerOperators.c
// Giuseppe Turini
// CS-231
// 2024-04-16

#include <stdio.h> // For printf function.

// Testing basic pointer operators.
int main() {
	// Defining few local variables to test pointers.
	int x =1;
	int y = 2;
	int z[10]; // z is an array of 10 int (declaration).
	int *intp; // intp is a pointer to int (declaration).
	intp = &x; // intp now points to x (definition).
	y = *intp; // y now stores the int value pointed by intp (x).
	*intp = 0; // The int variable pointed by intp is now assigned 0.
	intp = &z[1]; // intp now points to second int element in array of int z;
	*intp = y; // The int array item pointed by intp is now assigned the value of y.
	// Print array z. Note: expect some "trash" because array z is not fully initialized.
	printf("Array: ");
	for(int i = 0; i < 10; i++) { printf("%i ", z[i]); }
	printf("\n");
	fflush(stdout); // Force printf to print (otherwise is buffered).
	// Normal exit.
	return 0;
}


