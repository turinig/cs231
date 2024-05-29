


// GP-000E-GenericClassWithStaticFieldInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-29



#include <iostream> // For cout stream.



// ...
template <class T>
class generic_class {
private:
	T data; // Instance variable.
public:
	static int count; // Class variable.
	// Default constructor definition.
	generic_class() { generic_class::count++; }

	// Static method to print class variable.
    static void printCount() {
    	std::cout << "Printing generic_class<";
    	std::cout << typeid(T).name(); // Note: compiler-dependent mangled type name.
    	std::cout << ">: ";
    	std::cout << generic_class::count << std::endl;
    } // End printCount.
};



// Initialization of class variable
template <class T>
int generic_class<T>::count = 0;



// Main function.
int main() {
	// Testing generic class with static field.
	generic_class<int> obj1;
	generic_class<float> obj2;
	generic_class<int> obj3;
	generic_class<int>::printCount();
	generic_class<float>::printCount();
	// Note: generic_class<int> and generic_class<float> are 2 different types.
	return 0; // Normal exit.
}


