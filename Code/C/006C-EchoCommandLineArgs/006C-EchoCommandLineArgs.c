


// 006C-EchoCommandLineArgs.c
// Giuseppe Turini
// CS-231
// 2024-04-03

#include <stdio.h> // Importing external code for "printf" etc.

// Echoes command-line arguments.
int main(int argc, char *argv[]) { // Or: int main(int argc, char **argv)
	printf("Echoing command-line arguments...\n");
	for(int i = 0; i < argc; i++) {
		printf("argv[%d]: %s\n", i, argv[i]);
	}
	return 0;
}


