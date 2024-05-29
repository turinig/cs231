


// GP-000B-GenericArrayListInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-29



#include <iostream> // For cout stream.



template <typename T>
class generic_array_list {
private:
	T* array_ptr; // Pointer to dynamically allocated array.
    int array_size; // Physical size of internal array.
public:
    generic_array_list(T a[], int s); // Constructor declaration.
    void print(); // Print method declaration.
};



// Constructor definition.
template <typename T>
generic_array_list<T>::generic_array_list(T a[], int s) {
	this->array_size = s; // Initialize physical size of internal array.
	this->array_ptr = new T[ this->array_size ]; // Allocate internal array.
	// Transfer data (shallow copy) from input array to internal array.
    for(int i = 0; i < this->array_size; i++) { this->array_ptr[i] = a[i]; }
}



// Print method definition.
template <typename T>
void generic_array_list<T>::print() {
	std::cout << "Array list:";
	for(int i = 0; i < this->array_size; i++) {
		std::cout << " " << *(this->array_ptr + i); // Note: Pointer arithmetics.
	} // End for.
    std::cout << std::endl;
}



// Main function.
int main() {
	// Testing generic array list...
	int tmp_array[5] = {10, 20, 30, 40, 50};
	generic_array_list<int> my_list(tmp_array, 5);
	my_list.print();
	return 0; // Normal exit.
}


