


// 104A-TemplateFunctionUsingConceptsInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-20



#include <vector> // For vector class.
#include <type_traits> // For enable_if.



// Note: S is type of input sequence, V is type of input/output value.
// Note: template with no requirements on type parameters (partial specifications) is (template<typename S, typename V>).
// Note: template with requirements on type parameters (full specifications, see below in C++17 and concepts in C++20).
template<typename S, typename V,
	typename = typename std::enable_if<
		std::is_same<decltype(&S::size), int (S::*)() const>::value &&
		std::is_same<decltype(&S::getAt), V (S::*)(int) const>::value >::type >
class MySummator {
	public:
		static V sum(const S& sequence, V value) {
			for(int i = 0; i < sequence.size(); i++) {
				value += sequence.getAt(i); }
			return value;
		};
};



// ...
template<typename V>
class MyVector {
	public:
		std::vector<V> items; // Dynamically resizable array-based list.
		unsigned int numItems; // Logical size.
		int size() const { return this->numItems; }
		V getAt(int i) const { return this->items[i]; }
};



// ...
int main() {

	// Init a vector.
	MyVector<int> v;
	v.items = { 1, 2, 3};
	v.numItems = 3;

	// Call generic summation function with specifications on type parameters.
	int res = 0;
	res = MySummator<MyVector<int>, int>::sum(v, res);

	return 0; // Normal exit.
};


