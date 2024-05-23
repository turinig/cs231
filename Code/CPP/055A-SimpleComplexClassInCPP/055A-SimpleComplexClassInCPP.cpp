


// 055A-SimpleComplexClassInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-13



#include "./Include/Complex.h"

int main() {

	Complex a {2.3};

	//a.setReal(1.2).setImaginary(3.4);

	Complex b {1/a};
	Complex c {a + Complex{1, 2.3}};
	if(c != b) {
		c = -(b/a)+2*b; }


	return 0; // Normal exit.
}


