


// GP-000C-GenericPairInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-29



#include <iostream> // For cout stream.
#include <string> // For string class.



// Generic non-homogeneous pair class.
template <class T1, class T2>
class generic_pair {
private:
	T1 first; // First item in pair.
	T2 second; // Second item in pair.
public:
	// Default constructor definition.
	generic_pair() {
		std::cout << "Constructor: called..." << std::endl;
		std::cout << "type param. 1 (" << typeid(T1).name() << "), ";
		std::cout << "type param. 2 (" << typeid(T2).name() << ").";
		std::cout << std::endl;
	}
};



// Main function.
int main() {
	// Testing generic pair class.
	generic_pair<int, double> pair_a;
	generic_pair<char, std::string> pair_b;
    return 0; // Normal exit.
}


