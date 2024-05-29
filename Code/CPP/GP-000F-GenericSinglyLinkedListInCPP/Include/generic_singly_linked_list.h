


// generic_singly_linked_list.h
// Giuseppe Turini
// CS-231
// 2024-05-29



#ifndef INCLUDE_GENERIC_SINGLY_LINKED_LIST_H_
#define INCLUDE_GENERIC_SINGLY_LINKED_LIST_H_



#include <cstddef> // For size_t macro.
#include <iostream> // For cout stream.



// ...
template<typename T1>
class generic_singly_linked_list {

private:

	// Nested class/struct.
	// Note: struct because we want simple direct access to members (no information hiding).
	// Note: different type parameter name to avoid shadowing outer class type parameter.
	template<typename T2>
	struct node {
		T2 item; // List node item.
		struct node<T2>* next; // Link to next list node.
	};

	node<T1>* head; // ...
	std::size_t num_nodes; // ...

public:

	generic_singly_linked_list(); // Default constructor declaration.
	virtual ~generic_singly_linked_list(); // Virtual (non-pure) destructor declaration.
	void add(const T1& new_item); // ...
	void remove(std::size_t index); // ...
	bool empty() const; // ...
	std::size_t size() const; // ...
	void print() const; // ...

	// "= delete" instructs compiler to not generate these methods (only copy-constructors and = operator).
	generic_singly_linked_list(const generic_singly_linked_list& list) = delete;
	generic_singly_linked_list(generic_singly_linked_list&& list) = delete;
	generic_singly_linked_list& operator =(generic_singly_linked_list list) = delete;
};



// Default constructor definition.
template<class T>
generic_singly_linked_list<T>::generic_singly_linked_list() {
	this->head = nullptr;
	this->num_nodes = 0;
}



// Destructor definition.
template<class T>
generic_singly_linked_list<T>::~generic_singly_linked_list() {
	while(this->head != nullptr) {
		const auto curr_node_ptr = this->head;
		this->head = this->head->next;
		delete curr_node_ptr;
	} // End while.
}



// ...
template<class T>
bool generic_singly_linked_list<T>::empty() const { return this->head == nullptr; }



// ...
template<class T>
size_t generic_singly_linked_list<T>::size() const { return this->num_nodes; }



// Method to insert (append) input item at end of list.
template<class T>
void generic_singly_linked_list<T>::add(const T& new_item) {
	if(empty()) {
		this->head = new struct node<T>;
		this->head->item = new_item;
		this->head->next = nullptr;
	}
	else {
		auto curr_node = this->head; // "auto" to avoid "struct node<T>*".
		// Iterate to end of list.
		while(curr_node->next != nullptr) { curr_node = curr_node->next; }
		auto new_node = new struct node<T>; // "auto" to avoid "struct node<T>*".
		new_node->item = new_item;
		new_node->next = nullptr;
		curr_node->next = new_node;
	}
	this->num_nodes++;
}



// Remove list item at input index (array-like).
template<class T>
void generic_singly_linked_list<T>::remove(size_t index) {
	if(this->num_nodes > index) {
		struct node<T>* prev_node = nullptr;
		auto curr_node = this->head;// "auto" to avoid "struct node<T>*".
		// Move curr_node to target node (index), properly updating prev_node.
		for(size_t i = 0; i < index; i++) {
			prev_node = curr_node;
			curr_node = curr_node->next;
		} // End for.
		// Check special case (removal at front).
		if(curr_node == this->head) { this->head = curr_node->next; }
		else { prev_node->next = curr_node->next; }

		delete curr_node; // Deallocate memory of removed node.
		this->num_nodes--; // Update number of nodes.
	} // End if.
}



// Print list content on console.
template<class T>
void generic_singly_linked_list<T>::print() const {
	std::cout << "List:";
	auto curr_node = this->head;
	while(curr_node != nullptr) {
		std::cout << " " << curr_node->item;
		curr_node = curr_node->next;
	} // End while.
	std::cout << std::endl;
}



#endif // End INCLUDE_GENERIC_SINGLY_LINKED_LIST_H_


