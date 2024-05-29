


// GP-000D-GenericOverloadedSumFunctionInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-29



#include <iostream> // For cout stream.



// Note: Same name as non-generic function for overloading.
template<class T>
void sum(T a, T b) { std::cout << "Generic function result: " << a + b << std::endl; }



// Note: Same name as generic function for overloading.
void sum(int a, int b) { std::cout << "Non-generic function result: " << a + b << std::endl; }



// Main function.
int main() {
	// Testing generic function overloading.
	sum(1.23, 4.56); // Call to generic function.
	sum(7, 8); // Call to non-generic function.
	return 0; // Normal exit.
}


