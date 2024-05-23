


// 007A-VariablesDefinitionsUsingAutoKeywordInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-06

#include <cmath> // For sqrt function.
#include <iostream> // For I/O functions.

// ...
int main() {

	auto b = true; // A variable automatically typed as bool.
	auto ch = 'x'; // A variable automatically typed as char.
	auto i = 123; // A variable automatically typed as int.
	auto d = 4.5; // A variable automatically typed as double.
	double y {6.7}; // Initialize y using universal initialization form based on curly braces.
	auto z = sqrt(y); // A variable automatically typed as the return type of function sqrt.

	std::cout << "b: " << b << " (auto-bool)\n";
	std::cout << "ch: " << ch << " (auto-char)\n";
	std::cout << "i: " << i << " (auto-int)\n";
	std::cout << "d: " << d << " (auto-double)\n";
	std::cout << "y: " << y << " (initialized with universal syntax)\n";
	std::cout << "z: " << z << " (auto-funtion-return-type)\n";

	return 0; // Normal exit.
}


