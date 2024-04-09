


// 022A-CountingDigitsAndCharacters.c
// Giuseppe Turini
// CS-231
// 2024-04-09

#include <stdio.h>

// Counts digits and other characters.
int main() {
	// Initialization of local variables.
	int currChar; // Temporary variable to store current character being read (declaration).
	int numDigits[10]; // Array to store digit counters (declaration).
	int numNonDigits = 0; // Counter for non-digit characters (definition).
	// Initialization of array to store digit counters.
	for(int i = 0; i < 10; i++) { numDigits[i] = 0; }
	// Counting digits and non-digits until reaching newline character.
	while((currChar = getchar()) != '\n') {
		// Checking if current character is a digit or not, and update proper counter...
		if((currChar >= '0') && (currChar <= '9')) { ++numDigits[ currChar - '0' ]; }
		else { numNonDigits++; }
	}
	// Printing counters.
	printf("Digit counters:");
	for(int i = 0; i < 10; i++) { printf(" %d", numDigits[i]); }
	printf("\nNon-digit counter: %d\n", numNonDigits);
	// Exit.
	return 0; // Normal exit.
}


