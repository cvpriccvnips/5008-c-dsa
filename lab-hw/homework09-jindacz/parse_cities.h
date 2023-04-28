#ifndef PARSE_CITIES_H
#define PARSE_CITIES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PARIS 0
#define BERLIN 1
#define MILAN 2
#define ROME 3
#define COLOGNE 4
#define MUNICH 5
#define VIENNA 6
#define WARSAW 7
#define AMSTERDAM 8
#define BRUSSELS 9
#define FRANKFURT 10
#define PRAGUE 11

#define BUFF_SIZE 100
#define CHAR_SIZE 20

// your code for parsing the data from city.dat must be in this file

// remember to follow https://www.cs.swarthmore.edu/~newhall/unixhelp/c_codestyle.html
//    for code style

typedef struct city {
	char start[CHAR_SIZE];
	char end[CHAR_SIZE];
	int dist;
	int numLines;
} city_t;

/*
 * Function:  parseCity
 * --------------------
 * Parses the city data from a file and returns an array of city_t structs.
 *
 *  fileName: the name of the file containing the city data.
 *
 *  returns: a pointer to an array of city_t structs
 *           exit program if the file fails to open or memory *			  allocation fails.
 */
city_t* parseCity(char *fileName) {
	char buff[BUFF_SIZE];
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("file open failed\n");
		exit(1);
	}

	int numLines = 0;
	while (fgets(buff, BUFF_SIZE, fp) != NULL) {
		numLines += 1;
	}
	rewind(fp);
	city_t* dataset = (city_t*)malloc(sizeof(city_t) * numLines);
	if (dataset == NULL) {
		printf("memory allocation failed\n");
		exit(1);
	}

	int i = 0;
	while (fgets(buff, BUFF_SIZE, fp) != NULL) {
		sscanf(buff, "%s %s %d", dataset[i].start, dataset[i].end, &dataset[i].dist);
		dataset[i].numLines = numLines;
		i += 1;
	}
	fclose(fp);
	return dataset;
}

#endif