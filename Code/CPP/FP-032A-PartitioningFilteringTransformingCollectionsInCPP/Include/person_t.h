


// person_t.h
// Giuseppe Turini
// CS-231
// 2024-05-30



#ifndef INCLUDE_PERSON_T_H_
#define INCLUDE_PERSON_T_H_



#include <string> // For string class.
#include <iostream> // For ostream class.



// ...
class person_t {

	public:

		enum gender_t {female, male, other}; // ...
		enum output_format_t {name_only, full_name}; // ...

	private:

		std::string m_name; // ...
		std::string m_last_name; // ...
		gender_t m_gender; // ...
		int m_age; // ...

	public:

		// Constructors (default, version 1, definition).
		person_t() {
			this->m_name = "John";
			this->m_last_name = "Doe";
			this->m_gender = other;
			this->m_age = 0;
		}

		// Constructor (version 2, definition).
		person_t(std::string name, gender_t gender, int age = 0) {
			this->m_name = name;
			this->m_last_name = "Doe";
			this->m_gender = gender;
			this->m_age = age;
		}

		// Constructor (version 3, definition)
		person_t(std::string name, const std::string& last_name, gender_t gender, int age = 0) {
			this->m_name = name;
			this->m_last_name = last_name;
			this->m_gender = gender;
			this->m_age = age;
		}

		// Getters.
		std::string name() const { return this->m_name; }
		std::string last_name() const { return this->m_last_name; }
		gender_t gender() const { return this->m_gender; }
		int age() const { return this->m_age; }

		// ...
		void print(std::ostream &out, person_t::output_format_t format) const {
			if (format == person_t::name_only) {
				out << name(); }
			else if (format == person_t::full_name) {
				out << name() << " " << last_name(); }
		} // End print.

};



#endif // End INCLUDE_PERSON_T_H_


