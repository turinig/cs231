


// FP-032A-PartitioningFilteringTransformingCollectionsInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-31



#include <vector> // For vector class.
#include <algorithm> // For copy_if and transform functions.
#include <string> // For string class.
#include <iostream> // For cout stream.
#include <numeric> // For accumulate function.



#include "./Include/person_t.h"



// Function to get the name of a person.
std::string name(const person_t& person) { return person.name(); }

// Function to check if a person is female.
bool is_female(const person_t& person) { return person.gender() == person_t::female; }

// Function to check if a person is NOT female.
bool is_not_female(const person_t& person) { return !is_female(person); }



// Filtering with custom template higher-order function.
// Note: version 1, iterative implementation.
template <typename FilterFunction>
std::vector<std::string> names_for_v1(const std::vector<person_t>& people, FilterFunction filter) {
	std::vector<std::string> results; // Initialize output container.
	for(const person_t& person : people) { // Iterate items in input container.
		if(filter(person)) { // Use filter function.
			results.push_back(name(person)); } } // Insert filtered item in output container.
	return results; // Return output container.
}



// Function to return the "tail" (all items except first) of input container.
// Note: supporting function for recursion, inefficient implementation, only for demonstration purposes.
template <typename T>
T tail(const T& collection) { return T(collection.cbegin() + 1, collection.cend()); }

// Function to prepend input item to input container.
// Note: supporting function for recursion, inefficient implementation, only for demonstration purposes.
// Note: using reference to r-value (&& operator, forwarding reference) because item could be result of function.
// See: en.cppreference.com/w/cpp/language/reference
// See: en.cppreference.com/w/cpp/utility/forward
template <typename T, typename C>
C prepend(T&& item, C collection) {
    C results(collection.size() + 1); // Define output container with proper size.
    results[0] = std::forward<T>(item); // Set first item in output container using perfect forwarding (see also &&).
    std::copy(collection.cbegin(), collection.cend(), results.begin() + 1); // Transfer input container in output container.
    return results; // Return output container.
}



// Filtering with custom template higher-order function.
// Note: version 2, simple recursive implementation.
template <typename FilterFunction>
std::vector<std::string> names_for_v2(const std::vector<person_t>& people, FilterFunction filter) {
	if(people.empty()) { // Base case: input container empty.
		return {}; } // If input container empty, return empty output container.
	else { // Recurrence.
		const auto head = people.front(); // Store apart first item of input container.
		// Process "tail" (all items except first) of input container recursively.
		const auto processed_tail = names_for_v2(tail(people), filter); // Recursive call.
		// Processing recursion results.
		if(filter(head)) { return prepend(name(head), processed_tail); } // Prepend if filtering head succeeded.
		else { return processed_tail; } // Return only processed tail if filtering head failed.
	} // End if-else.
}



// Filtering with custom template higher-order function.
// Note: version 3, simple recursive implementation, using iterators.
// See: en.cppreference.com/w/cpp/iterator/iterator
template <typename FilterFunction, typename Iterator>
std::vector<std::string> names_for_v3(Iterator people_begin, Iterator people_end, FilterFunction filter) {
	if(people_begin == people_end) { // Base case: no items in iterators range.
		return {}; } // No items in iterators range, return empty output container.
	else { // Recurrence.
		const auto head = *people_begin; // Store apart first item of input container.
		// Process "tail" (all items except first) of input iterator range recursively.
		const auto processed_tail = names_for_v3(people_begin + 1, people_end, filter); // Recursive call.
		// Processing recursion results.
		if(filter(head)) { return prepend(name(head), processed_tail); } // Prepend if filtering head succeeded.
		else { return processed_tail; } // Return only processed tail if filtering head failed.
	} // End if-else.
}



// Filtering with custom template higher-order function.
// Note: supporting function to version 4, tail-recursive implementation, using iterators.
// See: en.cppreference.com/w/cpp/iterator/iterator
// See: en.cppreference.com/w/cpp/utility/move
template <typename FilterFunction, typename Iterator>
std::vector<std::string> names_for_v4_helper(	Iterator people_begin, Iterator people_end,
											FilterFunction filter,
											std::vector<std::string> results_previously_collected) {
	if(people_begin == people_end) { // Base case: no items in iterators range.
		return results_previously_collected; } // No items in iterators range, return results previously_collected.
	else { // Recurrence.
		const auto head = *people_begin; // Store apart first item of input container.
		if(filter(head)) { results_previously_collected.push_back(name(head)); } // Append head to results if filtering head succeeded.
		// Process "tail" (all items except first) of input iterator range recursively.
		return names_for_v4_helper(	people_begin + 1, people_end,
									filter,
									std::move(results_previously_collected)); // Recursive call.
	} // End if-else.
}

// Filtering with custom template higher-order function.
// Note: version 4, using supporting function based on tail-recursion and iterators.
// See: en.cppreference.com/w/cpp/iterator/iterator
template <typename FilterFunction, typename Iterator>
std::vector<std::string> names_for_v4(Iterator people_begin, Iterator people_end, FilterFunction filter) {
	return names_for_v4_helper(people_begin, people_end, filter, {}); // Call to supporting function.
}



// Filtering with custom template higher-order function.
// Note: version 5, using folding (std::accumulate) with lambdas and iterators.
// See: en.cppreference.com/w/cpp/language/lambda
// See: en.cppreference.com/w/cpp/algorithm/accumulate
// See: en.cppreference.com/w/cpp/iterator/iterator
template <typename FilterFunction>
std::vector<std::string> names_for_v5(const std::vector<person_t>& people, FilterFunction filter) {
	// Variable storing a lambda expression, to be used for folding (passed to std::accumulate as binary operator).
	auto append_name_if = [&filter] (std::vector<std::string>& results_previously_collected, const person_t& person) {
		if(filter(person)) { results_previously_collected.push_back(name(person)); }
		return results_previously_collected;
	};
	// Folding using std::accumulate passing binary operator (variable storing lambda expression.
	return std::accumulate(people.cbegin(), people.cend(), std::vector<std::string>{}, append_name_if);
}



// Main function.
int main(int argc, char* argv[]) {

	// Initialize original (non-filtered) collection.
	std::vector<person_t> people {
		{ "David"  , person_t::male   },
		{ "Jane"   , person_t::female },
		{ "Martha" , person_t::female },
		{ "Peter"  , person_t::male   },
		{ "Rose"   , person_t::female },
		{ "Tom"    , person_t::male   } };

	std::vector<person_t> females; // Collection to store filtering results.

	/*
	// Filtering the collection by copying.
	// std::copy_if function copies input collection items that satisfy input predicate into destination collection.
	// See: en.cppreference.com/w/cpp/algorithm/copy
	std::copy_if(people.cbegin(), people.cend(), std::back_inserter(females), is_female);

	std::vector<std::string> female_names(females.size()); // Collection to store transformation results.

	// Transforming collection to get only the names.
	// See: en.cppreference.com/w/cpp/algorithm/transform
	std::transform(females.cbegin(), females.cend(), female_names.begin(), name);
	*/

	// Filtering the collection by using custom template higher-order function.
	//std::vector<std::string> female_names = names_for_v1(people, is_female);
	//std::vector<std::string> female_names = names_for_v2(people, is_female);
	//std::vector<std::string> female_names = names_for_v3(people.begin(), people.end(), is_female);
	//std::vector<std::string> female_names = names_for_v4(people.begin(), people.end(), is_female);
	std::vector<std::string> female_names = names_for_v5(people, is_female);

	// Printing filtering/transformation results.
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


