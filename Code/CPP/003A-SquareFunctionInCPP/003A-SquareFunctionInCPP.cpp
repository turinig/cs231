


// 003A-SquareFunctionInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-05



#include <iostream> // For I/O functions.

using namespace std; // Make names from namespace std visible without requiring std::.

// Squares a double precision floating-point number.
double square(double x) { return x * x; }

// ...
void print_square(double x) {
	cout << "The square of " << x << " is " << square(x) << "\n";
}

// ...
int main() {
	print_square(1.234); // print: the square of 1.234 is 1.52276.
	fflush(stdout); // Force print on console (otherwise is buffered).
	return 0; // Normal exit.
}


