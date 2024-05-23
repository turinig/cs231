


// 259B-MultipleInheritanceDiamondProblemInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-20



#include<iostream>


// Shared super-super-class.
class Person {
	public:
		Person(int x)  { std::cout << "Constructor Person(int) called." << std::endl; }
		~Person()  { std::cout << "Destructor ~Person() called." << std::endl; } // Note: Only constructors take member initializers.
};

// Superclass 1.
class Faculty : virtual public Person {
	public:
		Faculty(int x) : Person(x) { std::cout<< "Constructor Faculty(int) called."<< std::endl; }
		~Faculty() { std::cout<< "Destructor ~Faculty() called."<< std::endl; } // Note: Only constructors take member initializers.
};


// Superclass 2.
class Student : virtual public Person {
	public:
		Student(int x) : Person(x) { std::cout << "Constructor Student(int) called." << std::endl; }
		~Student() { std::cout << "Destructor ~Student() called." << std::endl; } // Note: Only constructors take member initializers.
};

// The "diamond problem" in "multiple inheritance" occurs when 2 super-classes of a class have a common super-class.
// In this case, the class using multiple inheritance will inherit 2 copies of all attributes of the super-super-class (causing ambiguity).
// Also, the constructor/destructor of the super-super-class will be called multiple times.
// The solution is making super-classes "virtual" base classes (preventing multiple instances in an inheritance hierarchy).
// See: https://www.geeksforgeeks.org/multiple-inheritance-in-c/
// See: https://www.geeksforgeeks.org/virtual-base-class-in-c/
class TeachingAssistant : public Faculty, public Student  {

	public:

		// Constructor (see warnings on initialization order).
		TeachingAssistant(int x) : Student(x), Faculty(x) ,Person(x) { std::cout<< "Constructor TeachingAssistent(int) called." << std::endl; }

		// Destructor (only constructors take member initializers).
		~TeachingAssistant() { std::cout<< "Destructor ~TeachingAssistent() called." << std::endl; }

};

// ...
int main()  {
    TeachingAssistant ta1(30); // Creating an object using multiple inheritance (and having the diamond problem).
    return 0; // Normal exit.
}


