


// 032A-ProcessingCharacterArraysUsingExternalVariables.c
// Giuseppe Turini
// CS-231
// 2024-04-09

#include <stdio.h>

// Symbolic constants (macros).
#define MAXLINE 1000 // Max number of characters in input line.

// External variables.
int max; // Max length seen so far...
char line[MAXLINE]; // Current input text line.
char longest[MAXLINE]; // Longest line seen so far.

// Function declarations (prototypes).
int getline(char l[]); // Store input line into external variable (line) and return line size.
void copy(void); // Copies external variable (line) into external variable (longest).

// Selects and prints longest text line among run (command line) arguments.
int main(int argc, char *argv[]) {
	// Local (automatic) variables.
	int len; // Length of current text line.
	// External variables.
	extern int max;
	extern char longest[];
	// Initialization.
	max = 0;
	// Convert all run (command line) arguments into internal character arrays to find longest text line.
	// Note: Skipping 1st run (command line) argument (because standard is full path of executable file).
	for(int i = 1; i < argc; i++) {
		// Convert current run (command line) argument into internal character array.
		len = getline(argv[i]);
		// Check if current text line is longer than current longest.
		if(len > max) {
			// Update current longest line.
			max = len;
			copy(); } }
	// Check if there was at least 1 non-empty line in input.
	if(max > 0) { printf("Longest text line is: %s\n", longest); }
	// Exit.
	return 0; // Normal exit.
}

// Stores input line it into external variable (line) returning its size.
int getline(char l[]) {
	int c = 0; // Current character being read.
	int i = 0; // Iteration variable scope has to include all function!
	extern char line[]; // External variable.
	// Reading input line, 1 character at time, storing it in external variable (line).
	c = l[i];
	while(c != '\0') {
		line[i] = c;
		i++;
		c = l[i]; }
	line[i] = '\0'; // Adding null character at end of text line.
	return i; // Returning size of line in input.
}

// Copies external variable (line) into external variable (longest).
void copy(void) {
	int i = 0; // Iteration variable.
	extern char line[]; // External variable.
	extern char longest[]; // External variable.
	// Copy characters from (line) to (longest) until reaching null character (included).
	while((longest[i] = line[i]) != '\0') { i++; }
}


