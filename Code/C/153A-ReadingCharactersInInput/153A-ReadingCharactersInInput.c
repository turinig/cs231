


// 153A-ReadingCharactersInInput.c
// Giuseppe Turini
// CS-231
// 2024-05-02

#include <stdio.h> // For getchar, putchar, printf, and fflush functions.
#include <ctype.h> // For tolower function.

// Entry point (no command-line arguments, run arguments).
int main() {
	int c; // Local variable to store result of getchar.
	while((c = getchar()) != 'a') { // Reading a character from stdin, storing it in c, and checking if it is different than 'a'.
		putchar(tolower(c)); // Converting c to lowercase, and write it to stdout.
		fflush(stdout); // Force putchar to print to stdout (otherwise is buffered).
	}
	printf("\nEnd main.\n");
	return 0; // Normal exit.
}


