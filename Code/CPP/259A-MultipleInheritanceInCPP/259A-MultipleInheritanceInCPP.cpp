


// 259A-MultipleInheritanceInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-20



#include<iostream>

// Superclass 1.
class A {
	public:
		A() { std::cout << "Constructor A() called." << std::endl; }
		~A() { std::cout << "Destructor ~A() called." << std::endl; }
};

// Superclass 2.
class B {
	public:
		B() { std::cout << "Constructor B() called." << std::endl; }
		~B() { std::cout << "Destructor ~B() called." << std::endl; }
};

// "Multiple inheritance" is a feature of C++ where a class can inherit from multiple classes.
// Note: Constructors are called in SAME order of inheritance (here: first B(), then A(), and finally C()).
// Note: Destructors are called in REVERSE order of inheritance (here: first C(), then A(), and finally B()).
// See: https://www.geeksforgeeks.org/multiple-inheritance-in-c/
class C : public B, public A {
	public:
		C() { std::cout << "Constructor C() called." << std::endl; }
		~C() { std::cout << "Destructor ~C() called." << std::endl; }
};

// ...
int main() {
    C myObj1; // Create an object using multiple inheritance.
    return 0; // Normal exit.
}


