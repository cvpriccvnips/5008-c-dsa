#include <stdio.h>  // Input/Output
#include <stdlib.h> // malloc/free
#include <string.h> // String utility functions

int main() {
	const int numStudents = 10;

	char** namesOfStudents = NULL;

	namesOfStudents = (char**)malloc(sizeof(char*) * numStudents);

	for (int i = 0; i < numStudents) {
		namesOfStudents[i] = strdup("Mike\0");
	}

	

}