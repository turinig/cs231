


// FP-032A-PartitioningFilteringTransformingCollectionsInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-30



#include <vector> // For vector class.
#include <algorithm> // For copy_if and transform functions.
#include <string> // For string class.
#include <iostream> // For cout stream.



#include "./Include/person_t.h"



// ...
std::string name(const person_t &person) { return person.name(); }

// ...
bool is_female(const person_t &person) { return person.gender() == person_t::female; }

// ...
bool is_not_female(const person_t &person) { return !is_female(person); }

// ...
int main(int argc, char *argv[]) {

	// Initialize original (non-filtered) collection.
	std::vector<person_t> people {
		{ "David"  , person_t::male   },
		{ "Jane"   , person_t::female },
		{ "Martha" , person_t::female },
		{ "Peter"  , person_t::male   },
		{ "Rose"   , person_t::female },
		{ "Tom"    , person_t::male   } };

	std::vector<person_t> females; // Collection to store filtering results.

	// Filtering the collection by copying.
	// std::copy_if function copies input collection items that satisfy input predicate into destination collection.
	// See: en.cppreference.com/w/cpp/algorithm/copy
	std::copy_if(people.cbegin(), people.cend(), std::back_inserter(females), is_female);

	std::vector<std::string> female_names(females.size()); // Collection to store transformation results.

	// Transforming collection to get only the names.
	// See: en.cppreference.com/w/cpp/algorithm/transform
	std::transform(females.cbegin(), females.cend(), female_names.begin(), name);

	// Priting filtering/transformation results.
	std::cout << "People names are:";
	for(const auto& person : people) {
		std::cout << " ";
		person.print(std::cout, person_t::full_name); }
	std::cout << "\n";
	std::cout << "Female names are:";
	for(const auto& female_name : female_names) { std::cout << " " << female_name; }
	std::cout << "\n";
	// Exiting.
	return 0; // Normal exit.

} // End main.


