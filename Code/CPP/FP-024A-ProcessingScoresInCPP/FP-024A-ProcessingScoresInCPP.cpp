


// FP-024A-ProcessingScoresInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-30



#include <vector> // For vector class.
#include <iostream> // For cout stream.
#include <algorithm> // For copy and for_each functions.
#include <iterator> // For ostream_iterator class.
#include <numeric> // For accumulate and reduce functions.
#include <execution> // For std::execution::par constant.
#include <functional> // For multiplies function object.



// Function to calculate the average score of an list of scores in input.
// Note: version 1, imperative programming.
double scores_average_v1(const std::vector<int>& scores) {
	int sum = 0; // Initialization of accumulation variable.
	// Iterate the scores in input list (range-based for).
	for(int score : scores) {
		sum += score; // Compound assignment of accumulation variable.
	} // End range-based for.
	return sum / (double) scores.size(); // Compute average and return result.
}


// Function to calculate the average score of an list of scores in input.
// Note: version 2, functional programming.
// See: en.cppreference.com/w/cpp/algorithm/accumulate
double scores_average_v2(const std::vector<int>& scores) {
	// Note: std::accumulate guarantees that items are accumulated sequentially.
	return std::accumulate(scores.begin(), scores.end(), 0) / (double) scores.size(); // Compute average and return result.
}



// Function to calculate the average score of an list of scores in input.
// Note: version 3, functional programming.
// See: en.cppreference.com/w/cpp/algorithm/reduce
// See: en.cppreference.com/w/cpp/header/execution
double scores_average_v3(const std::vector<int>& scores) {
	// Note: std::reduce allows for accumulation to be parallelized.
	return std::reduce(std::execution::par, scores.begin(), scores.end(), 0) / (double) scores.size(); // Compute average and return result.
}



// Function to calculate the product of all scores in input list.
// Note: version 1, functional programming.
// See: en.cppreference.com/w/cpp/algorithm/accumulate
// See: en.cppreference.com/w/cpp/utility/functional/multiplies
double scores_product_v1(const std::vector<int>& scores) {
	// Note: std::accumulate guarantees that items are accumulated sequentially.
	return std::accumulate(scores.begin(), scores.end(), 1, std::multiplies<int>()); // Compute product and return it.
}


/*
// Overloading "<<" operator as template function.
// Note: version 1, range-based for.
// See: learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes
template <typename T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& v) {
	// Iterate input vector items (range-based for).
	for(auto item : v) {
		os << item << " "; } // Printing input vector item using output stream in input.
	return os; // Operator "<<" returns an output stream.
}
*/

/*
// Overloading "<<" operator as template function.
// Note: version 2, std::copy.
// See: en.cppreference.com/w/cpp/algorithm/copy
template <typename T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& v) {
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
	return os; // Operator "<<" returns an output stream.
}
*/


// Overloading "<<" operator as template function.
// Note: version 3, std::for_each and lambda function.
// See: en.cppreference.com/w/cpp/algorithm/for_each
// See: learn.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp
template <typename T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& v) {
	// Note: lambda expression/function capturing "os" by reference, with signature of function object required by for_each.
	std::for_each(v.begin(), v.end(), [&os] (const auto& item) { os << item << " "; } );
	return os; // Operator "<<" returns an output stream.
}


// Main function.
int main() {
	// Initialize a container of file names.
	std::vector<int> scores{77, 32, 80, 68, 82, 72, 26, 22, 36, 59}; // Universal initialization.
	double result1 = scores_average_v1(scores);
	double result2 = scores_average_v2(scores);
	double result3 = scores_average_v3(scores);
	// Print results on console.
	std::cout << "The scores are: " << scores << "\n";
	std::cout << "The average score (1) is: " << result1 << "\n";
	std::cout << "The average score (2) is: " << result2 << "\n";
	std::cout << "The average score (3) is: " << result3 << "\n";
	// Exiting.
	return 0; // Normal exit.
}


