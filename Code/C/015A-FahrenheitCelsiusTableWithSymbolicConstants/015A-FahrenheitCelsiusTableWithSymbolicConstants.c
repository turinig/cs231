


// 015A-FahrenheitCelsiusTableWithSymbolicConstants.c
// Giuseppe Turini
// CS-231
// 2023-12-01

#include <stdio.h>

// Symbolic constants (macros).
#define		LOWER	0		// Lower limit of temperature table.
#define		UPPER	300		// Upper limit of temperature table.
#define		STEP	20		// Step/increment size.

// Print Fahrenheit-Celsius table for fahr = 0, 20, ... , 300
int main() {
	int fahr; // Fahrenheit temperature integer value.
	// Iterative (for) generation of Fahrenheit temperature values (lower to upper).
	for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
		printf("%3d\t%6.1f\n", fahr, (5.0F / 9.0F) * (fahr - 32));
	}
	return 0;
}


