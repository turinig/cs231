


// Vector.h
// Giuseppe Turini
// CS-231
// 2024-05-13



#ifndef INCLUDE_VECTOR_H_
#define INCLUDE_VECTOR_H_



// ...
class Vector {

private:
	double* elems; // Pointer to an array of doubles (dynamically allocated).
	int size; // Size (physical) of internal array.

public:

	// Constructor (memory allocation).
	Vector(int s) {
		// Initialize class members.
		this->size = s;
		this->elems = new double[this->size];
		// Initialize array items.
		for(int i = 0; i < this->size; i++) {
			this->elems[i] = 0;
		}
	}

	// Destructor (memory deallocation).
	~Vector() { delete[] this->elems; }

	double& operator [](int i) { return this->elems[i]; } // ...
	int getSize() { return this->size; } // ...

};



#endif // End INCLUDE_VECTOR_H_


