


// 012A-FahrenheitCelsiusTableWithFloatsAndFormatting.c
// Giuseppe Turini
// CS-231
// 2024-04-05

#include <stdio.h>

// Print Fahrenheit-Celsius table for fahr = 0, 20, ... , 300
int main() {
	float fahr, celsius; // Fahrenheit and Celsius temperature floating-point values.
	int lower = 0; // Lower limit of temperature table.
	int upper = 300; // Upper limit of temperature table.
	int step = 20; // Step/increment size.
	fahr = lower; // Initialization.
	// Iterative generation of Fahrenheit temperature values (lower to upper).
	while(fahr <= upper) {
		celsius = (5.0F / 9.0F) * (fahr - 32.0F);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
