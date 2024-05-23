


// 004A-FunctionOverloadingInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-05


#include <string> // For string class.
#include <iostream> // For I/O functions.

using namespace std; // Make names from namespace std visible without requiring std::.

void print(int i) { cout << i << "\n"; } // Print function with an integer argument.
void print(double d)  { cout << d << "\n"; } // Print function with a floating-point argument.
void print(string s) { cout << s << "\n"; } // Print function with a string argument.

void print(int a, double b) { cout << a << " - " << b << " (int-double)\n"; } // Print function with int-double arguments.
void print(double a, int b) { cout << a << " - " << b << " (double-int)\n"; } // Print function with double-int arguments.

int main() {
   print(42); // Function call to print(int).
   print(9.65); // Function call to print(double).
   print("D is for Digital"); // Function call to print(string).

   //print(0, 0); // ERROR: Ambiguous function call!
   print(0.0, 0); // Non-ambiguous function call!

   fflush(stdout); // Force print on console (otherwise is buffered).
   return 0; // Normal exit.
}


