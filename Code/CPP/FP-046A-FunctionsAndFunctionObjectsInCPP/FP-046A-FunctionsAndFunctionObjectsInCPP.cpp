


// FP-046A-FunctionsAndFunctionObjectsInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-06-03



#include <string> // For string class.
#include <iostream> // For cout stream.



// Max function definition (old C-like syntax).
int max_v1(int a, int b) { return a > b ? a : b; }

// Max function definition (new C++ syntax, with a trailing return type).
auto max_v2(int a, int b) -> int { return a > b ? a : b; }



int answer = 42; // Global variable to test automatic return type deduction.

// Ask function to test automatic return type deduction.
// Note: return type is "int".
auto ask_v1() { return answer; }

// Ask function to test automatic return type deduction.
// Note: return type is "const int &".
const auto & ask_v2() { return answer; }

// Ask function to test automatic return type deduction.
// Note: error inconsistent return type deduction.
/*auto ask_v3(bool flag) {
	if(flag) { return 42; }
	else { return std::string("42"); }
}*/

// Factorial function to test automatic return type deduction.
// Note: OK, return type deduced by base case, and ready to be used when recursive call happens.
auto fact_v1(int n) {
	if(n == 0) { return 1; } // Base case.
	else { return fact_v1(n - 1) * n; } // Recursive call.
}

// Factorial function to test automatic return type deduction.
// Note: error because return type cannot be deduced before recursive call.
/*auto fact_v2(int n) {
	if(n > 0) { return fact_v2(n - 1) * n; } // Recursive call.
	else { return 1; } // Base case.
}*/



// Ask function to test automatic return type deduction.
// Note: "auto" uses template argument type deduction rules.
// Note: "decltype(auto)" uses declaration return type of the returned expression.
// Note: this function returns an int.
// See: en.cppreference.com/w/cpp/language/decltype
decltype(auto) ask_v4() { return answer; }

// Ask function to test automatic return type deduction.
// Note: "auto" uses template argument type deduction rules.
// Note: "decltype(auto)" uses declaration return type of the returned expression.
// Note: this function returns a reference to int.
// See: en.cppreference.com/w/cpp/language/decltype
decltype(auto) ask_v5() { return (answer); }

// Ask function to test automatic return type deduction.
// Note: "auto" uses template argument type deduction rules.
// Note: "decltype(auto)" uses declaration return type of the returned expression.
// Note: this function returns an int.
// See: en.cppreference.com/w/cpp/language/decltype
decltype(auto) ask_v6() { return 42 + answer; }



// "Call on object" function to test perfect forwarding of arguments and internal results.
// Note: the "&&" operator marks an r-value reference, and here is used as a forwarding reference.
// Note: std::forward forwards l-values as either l-values or r-values, depending on template type argument (T).
// See: en.cppreference.com/w/cpp/language/reference
// See: en.cppreference.com/w/cpp/utility/forward
template <typename Object, typename Function>
decltype(auto) call_on_object(Object&& o, Function f) { // Forwarding reference.
	return f( std::forward<Object>(o) ); // Perfect forwarding using std::forward.
}



typedef decltype(ask_v1)* function_ptr; // Declaring a new type for function pointer (see signature of ask_v1).

// Example of class convertible to a function pointer.
class convertible_to_function_ptr {
	public:
		operator function_ptr() const { return ask_v1; } // Casting operator "()" returns a function pointer (function_ptr).
};



// Main function.
int main() {

	// Testing function pointers.

	auto ask_v1_ptr = &(ask_v1); // Function pointer.
	std::cout << ask_v1_ptr() << "\n";

	auto& ask_v1_ref = ask_v1; // Function reference.
	std::cout << ask_v1_ref() << "\n";

	convertible_to_function_ptr ask_v1_wrapper; // Object (implicitly) convertible to function pointer.
	std::cout << ask_v1_wrapper() << "\n";

	// Exiting.
	return 0; // Normal exit.

} // End main.


