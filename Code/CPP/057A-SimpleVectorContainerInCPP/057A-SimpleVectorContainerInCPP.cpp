


// 057A-SimpleVectorContainerInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-13



#include "./Include/Vector.h"

int main() {

	Vector v1(10); // v1, implicitly allocated here, and implicitly/automatically deallocated at end of main.

	Vector* v2p = new Vector(100); // v2p points to a Vector, explicitly allocated here, and not automatically deallocated at end of main.

	delete v2p; // v2p points to a Vector, explicitly deallocated here (delete calls destructor of Vector.

	return 0; // Normal exit.
}


