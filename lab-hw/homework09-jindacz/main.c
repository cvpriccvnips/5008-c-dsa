#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// remove whichever you don't need
#include "adjlist.h"
#include "parse_cities.h"

// define other CONSTANTS you need here

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

#define INPUT_SIZE 20

// your main code for the homework, including any additional required functions,
//		should be in this file

// remember to follow https://www.cs.swarthmore.edu/~newhall/unixhelp/c_codestyle.html
//    for code style

int main(int argc, char *argv[]) {
    city_t *citySet = parseCity("city.dat");
    adj_t *adjList = createAdjList(citySet);

    int start;
    int end;
    char input[INPUT_SIZE];

    while (1) {
        printf("Please select an origin city\n\n");
        printf("Enter a number associated with one of the cities below:\n\n");
        int i;
        for (i = 0; i < CITIES; i++) {
            printf("%s   ---  %d\n", cityName[i], i);
        }
        printf("\n\nTO QUIT ENTER -- %d\n", CITIES);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &start);
        if (start >= CITIES) {
            break;
        }

        printf("Please select an destination city\n\n");
        printf("Enter a number associated with one of the cities below:\n\n");
        for (i = 0; i < CITIES; i++) {
            if (i != start) {
                printf("%s   ---  %d\n", cityName[i], i);
            }
        }
        printf("\n");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &end);
        if (end >= CITIES || end == start) {
            break;
        }

        node_t *cur = adjList[start].head;
        while (cur) {
            if (cur->nei == end) {
                printf("there is an edge connecting %s to %s, and the distance is %d\n\n", cityName[start], cityName[end], cur->dist);
                break;
            }
            cur = cur->next;
            if (!cur) {
                printf("There is no edge connecting %s to %s\n\n", cityName[start], cityName[end]);
            }
        }
    }
    free(citySet);
    freeAdjList(adjList);
    return 0;
}
