


// 009B-DataTypesInC.c
// Giuseppe Turini
// CS-231
// 2024-04-04

#include <stdio.h> // Importing external code for "printf" etc.
#include <limits.h> // Importing external code for integer types info etc.
#include <float.h > // Importing external code for floating-point types info etc.

// Lists all data types in C...
int main() {
	printf("\nLISTING ALL DATA TYPES IN C...\n\n");

	// char
	printf("TYPE: char\t\t");
	printf("BITSIZE: %u\t", CHAR_BIT);
	printf("RANGE: [%i, %i]\t", CHAR_MIN, CHAR_MAX);
	printf("NOTE: could be either signed/unsigned\n");
	// signed char
	printf("TYPE: signed char\t");
	printf("BITSIZE: %u\t", CHAR_BIT);
	printf("RANGE: [%i, %i]\t", SCHAR_MIN, SCHAR_MAX);
	printf("NOTE: guaranteed to be signed\n");
	// unsigned char
	printf("TYPE: unsigned char\t");
	printf("BITSIZE: %u\t", CHAR_BIT);
	printf("RANGE: [%u, %u]\t\t", 0, UCHAR_MAX);
	printf("NOTE: guaranteed to be unsigned\n\n");

	// short
	printf("TYPE: short\t\t\t");
	printf("BITSIZE: %llu\t", (sizeof(short) * 8));
	printf("RANGE: [%hi, %hi]\t\t", SHRT_MIN, SHRT_MAX);
	printf("NOTE: short signed integer type\n");
	// short int
	printf("TYPE: short int\t\t\t");
	printf("BITSIZE: %llu\t", (sizeof(short int) * 8));
	printf("RANGE: [%hi, %hi]\t\t", SHRT_MIN, SHRT_MAX);
	printf("NOTE: short signed integer type\n");
	// signed short
	printf("TYPE: signed short\t\t");
	printf("BITSIZE: %llu\t", (sizeof(signed short) * 8));
	printf("RANGE: [%hi, %hi]\t\t", SHRT_MIN, SHRT_MAX);
	printf("NOTE: short signed integer type\n");
	// signed short int
	printf("TYPE: signed short int\t\t");
	printf("BITSIZE: %llu\t", (sizeof(signed short int) * 8));
	printf("RANGE: [%hi, %hi]\t\t", SHRT_MIN, SHRT_MAX);
	printf("NOTE: short signed integer type\n");
	// unsigned short
	printf("TYPE: unsigned short\t\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned short) * 8));
	printf("RANGE: [%hu, %hu]\t\t", 0, USHRT_MAX);
	printf("NOTE: short unsigned integer type\n");
	// unsigned short int
	printf("TYPE: unsigned short int\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned short int) * 8));
	printf("RANGE: [%hu, %hu]\t\t", 0, USHRT_MAX);
	printf("NOTE: short unsigned integer type\n\n");

	// int
	printf("TYPE: int\t\t");
	printf("BITSIZE: %llu\t", (sizeof(int) * 8));
	printf("RANGE: [%i, %i]\t", INT_MIN, INT_MAX);
	printf("NOTE: basic signed integer type\n");
	// signed
	printf("TYPE: signed\t\t");
	printf("BITSIZE: %llu\t", (sizeof(signed) * 8));
	printf("RANGE: [%i, %i]\t", INT_MIN, INT_MAX);
	printf("NOTE: basic signed integer type\n");
	// signed int
	printf("TYPE: signed int\t");
	printf("BITSIZE: %llu\t", (sizeof(signed int) * 8));
	printf("RANGE: [%i, %i]\t", INT_MIN, INT_MAX);
	printf("NOTE: basic signed integer type\n");
	// unsigned
	printf("TYPE: unsigned\t\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned) * 8));
	printf("RANGE: [%u, %u]\t\t\t", 0, UINT_MAX);
	printf("NOTE: basic unsigned integer type\n");
	// unsigned int
	printf("TYPE: unsigned int\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned int) * 8));
	printf("RANGE: [%u, %u]\t\t\t", 0, UINT_MAX);
	printf("NOTE: basic unsigned integer type\n\n");

	// long
	printf("TYPE: long\t\t\t");
	printf("BITSIZE: %llu\t", (sizeof(long) * 8));
	printf("RANGE: [%li, %li]\t", LONG_MIN, LONG_MAX);
	printf("NOTE: long signed integer type\n");
	// long int
	printf("TYPE: long int\t\t\t");
	printf("BITSIZE: %llu\t", (sizeof(long int) * 8));
	printf("RANGE: [%li, %li]\t", LONG_MIN, LONG_MAX);
	printf("NOTE: long signed integer type\n");
	// signed long
	printf("TYPE: signed long\t\t");
	printf("BITSIZE: %llu\t", (sizeof(signed long) * 8));
	printf("RANGE: [%li, %li]\t", LONG_MIN, LONG_MAX);
	printf("NOTE: long signed integer type\n");
	// signed long int
	printf("TYPE: signed long int\t\t");
	printf("BITSIZE: %llu\t", (sizeof(signed long int) * 8));
	printf("RANGE: [%li, %li]\t", LONG_MIN, LONG_MAX);
	printf("NOTE: long signed integer type\n");
	// unsigned long
	printf("TYPE: unsigned long\t\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned long) * 8));
	printf("RANGE: [%u, %lu]\t\t\t", 0, ULONG_MAX);
	printf("NOTE: long unsigned integer type\n");
	// unsigned long int
	printf("TYPE: unsigned long int\t\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned long int) * 8));
	printf("RANGE: [%u, %lu]\t\t\t", 0, ULONG_MAX);
	printf("NOTE: long unsigned integer type\n\n");

	// long long
	printf("TYPE: long long\t\t\t");
	printf("BITSIZE: %llu\t", (sizeof(long long) * 8));
	printf("RANGE: [%lli, %lli]\t", LLONG_MIN, LLONG_MAX);
	printf("NOTE: long long signed integer type\n");
	// long long int
	printf("TYPE: long long int\t\t");
	printf("BITSIZE: %llu\t", (sizeof(long long int) * 8));
	printf("RANGE: [%lli, %lli]\t", LLONG_MIN, LLONG_MAX);
	printf("NOTE: long long signed integer type\n");
	// signed long long
	printf("TYPE: signed long long\t\t");
	printf("BITSIZE: %llu\t", (sizeof(signed long long) * 8));
	printf("RANGE: [%lli, %lli]\t", LLONG_MIN, LLONG_MAX);
	printf("NOTE: long long signed integer type\n");
	// signed long long int
	printf("TYPE: signed long long int\t");
	printf("BITSIZE: %llu\t", (sizeof(signed long long int) * 8));
	printf("RANGE: [%lli, %lli]\t", LLONG_MIN, LLONG_MAX);
	printf("NOTE: long long signed integer type\n");
	// unsigned long long
	printf("TYPE: unsigned long long\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned long long) * 8));
	printf("RANGE: [%u, %llu]\t\t\t", 0, ULLONG_MAX);
	printf("NOTE: long long unsigned integer type\n");
	// unsigned long long int
	printf("TYPE: unsigned long long int\t");
	printf("BITSIZE: %llu\t", (sizeof(unsigned long long int) * 8));
	printf("RANGE: [%u, %llu]\t\t\t", 0, ULLONG_MAX);
	printf("NOTE: long long unsigned integer type\n\n");

	// float
	printf("TYPE: float\t\t");
	printf("BITSIZE: %llu\t", (sizeof(float) * 8));
	printf("RANGE: [%g, %g]\t", FLT_MIN, FLT_MAX);
	printf("NOTE: single-precision floating-point type\n");
	// double
	printf("TYPE: double\t\t");
	printf("BITSIZE: %llu\t", (sizeof(double) * 8));
	printf("RANGE: [%lg, %lg]\t", DBL_MIN, DBL_MAX);
	printf("NOTE: double-precision floating-point type\n");
	// long double
	printf("TYPE: long double\t");
	printf("BITSIZE: %llu\t", (sizeof(long double) * 8));
	printf("RANGE: [%Lg, %Lg]\t", LDBL_MIN, LDBL_MAX);
	printf("NOTE: extended precision floating-point type\n");

	// Normal exit.
	return 0;
}


