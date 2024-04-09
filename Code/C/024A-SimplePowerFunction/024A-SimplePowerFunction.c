


// 024A-SimplePowerFunction.c
// Giuseppe Turini
// CS-231
// 2024-04-09

#include <stdio.h>

int power(int base, int exp); // Simple power function (declaration).

// Testing power function.
int main() {
	// Testing.
	printf("Testing simple power function:\n");
	for(int i = 0; i < 10; i++) {
		printf("i = %d, \t2^i = %d, \t-3^i = %d\n", i, power(2, i), power(-3, i)); }
	// Exit.
	return 0; // Normal exit.
}

// Simple power function (definition).
// Note: Only supports positive exponents, and small integer values.
int power(int base, int exp) {
	int res = 1; // Init result.
	// Iteratively multiplications to compute power (base^exp).
	for(int i = 1; i <= exp; i++) { res = res * base; }
	return res; // Return result (base^exp).
}


