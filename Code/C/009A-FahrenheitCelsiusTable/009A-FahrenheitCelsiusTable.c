


// 009A-FahrenheitCelsiusTable.c
// Giuseppe Turini
// CS-231
// 2023-12-01

#include <stdio.h>

// Print Fahrenheit-Celsius table for fahr = 0, 20, ... , 300
int main() {
	int fahr; // Fahrenheit temperature value.
	int celsius; // Celsius temperature value.
	int lower = 0; // Lower limit of temperature table.
	int upper = 300; // Upper limit of temperature table.
	int step = 20; // Step/increment size.
	fahr = lower; // Initialization.
	// Iterative generation of Fahrenheit temperature values (lower to upper).
	while(fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}


