


// Complex.h
// Giuseppe Turini
// CS-231
// 2024-05-13



#ifndef INCLUDE_COMPLEX_H_
#define INCLUDE_COMPLEX_H_



// See: en.wikipedia.org/wiki/complex_number
class Complex {

	double real; // Real part.
	double imaginary; // Imaginary part.

public:

	Complex(double r, double i) : real{r}, imaginary{i} {} // Constructor 1.

	// Constructor 1 same as: Complex(double r, double i) { this->real = r; this->imaginary = i; }

	Complex(double r) : real{r}, imaginary{0} {} // Constructor 2.
	Complex() : real{0}, imaginary{0} {} // Constructor default.

	double getReal() const { return this->real; } // Getter/accessor.
	void setReal(double r) { this->real = r; } // Setter/modifier.

	double getImaginary() const { return this->imaginary; } // Getter/accessor.
	void setImaginary(double i) { this->imaginary = i; } // Setter/modifier.

	// Operator += (inline).
	Complex& operator +=(Complex other) {
		this->real += other.real;
		this->imaginary += other.imaginary;
		return *this;
	}

	// Operator -= (inline).
	Complex& operator -=(Complex other) {
		this->real -= other.real;
		this->imaginary -= other.imaginary;
		return *this;
	}

	// Operator *= (inline).
	Complex& operator *=(Complex other) {
		this->real *= other.real;
		this->imaginary *= other.imaginary;
		return *this;
	}

	// Operator /= (inline).
	Complex& operator /=(Complex other) {
		this->real /= other.real;
		this->imaginary /= other.imaginary;
		return *this;
	}

};



// Operators (inline) not using direct-access to class-type representation (defined outside class)
Complex operator +(Complex a, Complex b) { return a += b; }
Complex operator -(Complex a, Complex b) { return a -= b; }
Complex operator -(Complex a) { return {-a.getReal(), -a.getImaginary()}; }
Complex operator *(Complex a, Complex b) { return a *= b; }
Complex operator /(Complex a, Complex b) { return a /= b; }
bool operator ==(Complex a, Complex b) { return ((a.getReal() == b.getReal()) && (a.getImaginary() == b.getImaginary())); }
bool operator !=(Complex a, Complex b) { return !(a == b); }



#endif // End INCLUDE_COMPLEX_H_


