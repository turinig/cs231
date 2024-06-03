


// company_t.h
// Giuseppe Turini
// CS-231
// 2024-06-03



#ifndef INCLUDE_COMPANY_T_H_
#define INCLUDE_COMPANY_T_H_



#include <string> // For string class.
#include <vector> // For vector class.
#include <algorithm> // For count_if function.

#include "person_t.h" // For person_t class.



// ...
class company_t {

	public:
		std::string team_name_for(const person_t& employee) const;
		int count_team_members(const std::string& team_name) const;

	private:
		std::vector<person_t> m_employees;

};



// Returns the team name of the input employee.
// Note: dummy implementation just for testing purposes.
std::string company_t::team_name_for(const person_t & employee) const {
    return "Team 1"; // Dummy return value.
}



// Example of lambda function.
// Note: lambda has to "capture" "this" to be able to call member function "team_name_for".
// Note: lambda has to "capture" "team_name" to be able to perform the string-comparison.
// Note: lambda represents the unary predicate (returning ​true for items counted) used by std::count_if.
// See: en.cppreference.com/w/cpp/algorithm/count
int company_t::count_team_members(const std::string& team_name) const {
	// Counting number of members in the specified team using std::count_if and a lambda function.
	return std::count_if( 	this->m_employees.cbegin(),
							this->m_employees.cend(),
							[this, &team_name] (const person_t & employee) { return this->team_name_for(employee) == team_name; } // Lambda function.
						); // End count_if.
}



// Example of the generated lambda-class.
// Note: this class is automatically generated by the compiler to represent the lambda function.
// Note: a member for each variable "captured" by the lambda function.
// Note: a call operator "()" with same arguments and body of lambda function.
// Note: in evaluating a lambda, the compiler also creates 1 instance of this class, called a "closure".
class lambda_implementation {

	private:

		const company_t* m_this;
		const std::string& m_team_name;

	public:

		lambda_implementation(const company_t* _this, const std::string& team_name) : m_this(_this), m_team_name(team_name) {}

		bool operator () (const person_t& employee) const {
			return m_this->team_name_for(employee) == m_team_name;
		}

};


#endif // End INCLUDE_COMPANY_T_H_


