


// GP-000A-GenericMaxFunctionInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-29



#include <iostream> // For cout stream.
#include <string> // For string class.



// Generic "max" function, designed to work for all data types.
// Note: Type parameter T must include operator ">" (must be overloaded for user-defined types).
template <typename T>
T generic_max(T a, T b) { return (a > b) ? a : b; }

// Main function.
int main()  {
    std::cout << generic_max<int>(3, 7) << std::endl; // Calling generic function for int.
    std::cout << generic_max<double>(3.0, 7.0) << std::endl; // Calling generic function for double.
    std::cout << generic_max<char>('g', 'e') << std::endl; // Calling generic function for char.
    std::cout << generic_max<std::string>("abc", "def") << std::endl; // Calling generic function for char.
    return 0;
}


