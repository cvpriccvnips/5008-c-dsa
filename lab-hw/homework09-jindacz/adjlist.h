#ifndef ADJLIST_H
#define ADJLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse_cities.h"

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

#define CITIES 12

// if you choose to implement an adjacency list,
//     your code for implementing an adjancency list must be in this file

// remember to follow https://www.cs.swarthmore.edu/~newhall/unixhelp/c_codestyle.html
//    for code style

typedef struct node {
	int nei;
	int dist;
	struct node *next;
} node_t;

typedef struct adj {
	node_t *head;
} adj_t;

char *cityName[CITIES] = {
	"paris",
	"berlin",
	"milan",
	"rome",
	"cologne",
	"munich",
	"vienna",
	"warsaw",
	"amsterdam",
	"brussels",
	"frankfurt",
	"prague"};

/*
 * Function:  createNode
 * --------------------
 * Create node in adjacent list.
 *
 *  nei: the neighbour node of current node
 *  dist: the distance of current node to neighbor node
 *
 *  returns: new newNode created with give neibour node and distance
 *
 */
node_t *createNode(int nei, int dist) {
	node_t *newNode = (node_t *)malloc(sizeof(node_t));
	if (newNode == NULL) {
		return NULL;
	}
	newNode->nei = nei;
	newNode->dist = dist;
	newNode->next = NULL;
	return newNode;
}

/*
 * Function:  createAdjList
 * --------------------
 * Create adjacent list.
 *
 *  citySet: array of city_t struct entries.
 *
 *  returns: the created adjacent list generated from array of city_t struct.
 *
 */
adj_t *createAdjList(city_t *citySet) {
	int i;
	int j;
	int k;
	adj_t *adjList = (adj_t *)malloc(CITIES * sizeof(adj_t));
	if (adjList == NULL) {
		return NULL;
	}
	for (i = 0; i < CITIES; i += 1) {
		adjList[i].head = NULL;
	}

	for (i = 0; i < CITIES; i += 1) {
		for (j = 0; j < CITIES; j += 1) {
			if (i == j) {
				continue;
			};
			for (k = 0; k < citySet[i].numLines; k += 1) {
				if ((strcmp(citySet[k].start, cityName[i]) == 0 
				&& strcmp(citySet[k].end, cityName[j]) == 0)) {
					node_t *newNode = createNode(j, citySet[k].dist);
					if (newNode == NULL) {
						return NULL;
					} 
					newNode->next = adjList[i].head;
					adjList[i].head = newNode;
				}
			}
		}
	}
	return adjList;
}

/*
 * Function:  freeAdjList
 * --------------------
 * Free memory allocation of adjacent list.
 *
 *  adjList: input adjcant list to be freed.
 *
 *  returns: void
 *
 */
void freeAdjList(adj_t* adjList) {
	node_t* cur;
	node_t* tmp;
	int i;
	for (i = 0; i < CITIES; i ++) {
		cur = adjList[i].head;
		while (cur) {
			tmp = cur;
			cur = cur->next;
			free(tmp);
		}
		adjList[i].head = NULL;
	}
	free(adjList);
}

#endif