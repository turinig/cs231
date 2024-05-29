


// FP-004A-CalculateLinesNumberInFilesInCPP.cpp
// Giuseppe Turini
// CS-231
// 2024-05-29



#include <vector> // For vector class.
#include <string> // For string class.
#include <fstream> // For ifstream class.
#include <iostream> // For cout stream.
#include <algorithm> // For count function.



// Function to calculate lines number of input files (file names).
// Note: version 1, imperative programming.
std::vector<int> count_lines_in_files_v1(const std::vector<std::string>& file_names){
	// Initialize local variables: output container, and character read.
	std::vector<int> results;
	char c = 0;
	// Iterate the file names in input (range-based for).
	for(const auto& file_name : file_names) {
		int line_count = 0; // Lines counter.
		std::ifstream in(file_name); // Input file defined on input file name.
		// Iteratively reading file content (1 character at time) until reaching a newline.
		while(in.get(c)) { // Read 1 character from input file stream.
			if(c == '\n') { line_count++; } // Check newline and increment counter.
		} // End while.
		results.push_back(line_count); // Append line counter to output container.
	} // End for.
	return results; // Return output container.
} // End count_lines_in_files_v1.



// Function to calculate lines number of input file (file name).
// Note: used by count_lines_in_files_v2.
int count_lines_in_file(const std::string& file_name){
	std::ifstream in(file_name); // Input file stream defined on input file name.
	// Calling the STL "count" algorithm.
	// See: en.cppreference.com/w/cpp/algorithm/count
	return std::count(
		std::istreambuf_iterator<char>(in), // Input iterator pointing to first element to examine.
		std::istreambuf_iterator<char>(), // Input iterator pointing to last element to examine.
		'\n' // Value to search for.
		); // End count.
} // End count_lines_in_file.



// Function to calculate lines number of input files (file names).
// Note: version 2, functional programming (using STL count function).
std::vector<int> count_lines_in_files_v2(const std::vector<std::string>& file_names){
	std::vector<int> results; // Output container.
	for(const auto& file_name : file_names) {
		results.push_back( count_lines_in_file(file_name) );
	}
	return results; // Return output container.
} // End count_lines_in_files_v2.



// Function to calculate lines number of input files (file names).
// Note: version 3, functional programming (using STL transform function).
std::vector<int> count_lines_in_files_v3(const std::vector<std::string>& file_names){
	std::vector<int> results( file_names.size() ); // Output container.
	// Calling the STL "transform" algorithm.
	// See: en.cppreference.com/w/cpp/algorithm/transform
	std::transform(
		file_names.cbegin(), // Const iterator pointing to first element to examine.
		file_names.cend(), // Const iterator pointing to last element to examine.
		results.begin(), // Iterator to beginning of destination range.
		count_lines_in_file // Unary operation function object.
		); // End transform.
	return results; // Return output container.
} // End count_lines_in_files_v3.



/*
// Function to calculate lines number of input files (file names).
// Note: version 4, functional programming (using ranges, only C++20).
std::vector<int> count_lines_in_files_v4(const std::vector<std::string>& file_names){
	// Using ranges and the "|" (pipe) operator to push a collection through a transformation.
	// Calling the STL "transform" algorithm.
	// See: en.cppreference.com/w/cpp/algorithm/transform
	return file_names | std::transform( count_lines_in_file );
} // End count_lines_in_files_v4.
*/



// Main function.
int main() {
	// Initialize a container of file names.
	std::vector<std::string> file_names;
	file_names.push_back("file1.txt");
	file_names.push_back("file2.txt");
	file_names.push_back("file3.txt");
	// Call function to count lines in input file names.
	std::vector<int> lines_numbers_1 = count_lines_in_files_v1(file_names);
	std::vector<int> lines_numbers_2 = count_lines_in_files_v2(file_names);
	std::vector<int> lines_numbers_3 = count_lines_in_files_v3(file_names);
	// Print results on console.
	std::cout << "The lines numbers (1) are:";
	for(const int ln : lines_numbers_1) { std::cout << " " << ln; }
	std::cout << "\n";
	std::cout << "The lines numbers (2) are:";
	for(const int ln : lines_numbers_2) { std::cout << " " << ln; }
	std::cout << "\n";
	std::cout << "The lines numbers (3) are:";
	for(const int ln : lines_numbers_3) { std::cout << " " << ln; }
	std::cout << "\n";
	// Exiting.
	return 0; // Normal exit.
}


