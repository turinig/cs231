


// 016A-CopyInputToOutput.c
// Giuseppe Turini
// CS-231
// 2023-12-01

#include <stdio.h>

// Copy input to output.
int main() {
	int c; // So variable can store any value getchar could return (char type is not enough).
	c = getchar(); // getchar reads the next input character from a text stream (usually from keyboard) and returns it.
	//while(c != EOF) { // Checking for special character EOF (end of file).
	while(c != '\n') { // Checking for special character newline ('\n').
		putchar(c); // putchar writes the input value c in output (usually on the screen/console).
		c = getchar();
	}
	return 0; // Normal exit.
}


