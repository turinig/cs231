


// 096A-SwapFunction.c
// Giuseppe Turini
// CS-231
// 2024-04-16

#include <stdio.h> // For printf function.

void swap(int *ap, int *bp); // Swap function prototype (declaration).

// Testing a simple swap function.
int main() {
	int x = 123; // Value to be swapped.
	int y = 456; // Value to be swapped.
	printf("Values before swap: %d %d\n", x, y); fflush(stdout); // Printing values before swapping them.
	swap(&x, &y); // Swapping values passing pointers as arguments.
	printf("Values after swap: %d %d\n", x, y); fflush(stdout); // Printing values after swapping them.
	return 0; // Normal exit.
}

// Swap function (definition).
void swap(int *ap, int *bp) {
	// Swapping values (a,b) pointed by input pointers (ap,bp).
	int temp = *ap; // temp stores value pointed by ap.
	*ap = *bp; // Value pointed by ap, now stores value pointed by bp.
	*bp = temp; // Value pointed by bp, now stores value stored in temp.
}


