


// GP-000G-GenericCustomIteratorInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-06-05



#include "./Include/generic_singly_linked_list.h"



// Main function.
int main() {

	// Testing generic singly-linked list.
	generic_singly_linked_list<int> list1;
	list1.add(11); // Appending some items.
	list1.add(22);
	list1.add(33);
	list1.add(44);
	list1.add(55);
	list1.print(); // Printing list.
	list1.remove(4); // Removing some items.
	list1.remove(0);
	list1.print(); // Printing list.

	// Testing iterator.
	// we can get an iterator that can be incremented
	std::cout << "List items:";
	auto list1_iter = list1.begin();
	std::cout << " " << *(++list1_iter); // Testing prefix increment.
	while(list1_iter != list1.end()) {
	    std::cout << " " << *(list1_iter++); // Testing postfix increment.
	} // End while.
	std::cout << "\n";

	return 0; // Normal exit.
}


