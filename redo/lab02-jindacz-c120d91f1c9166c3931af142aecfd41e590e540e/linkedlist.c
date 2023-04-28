// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// use the following struct for your linked list 

typedef struct node {
    int years;
    int numWins;
    struct node* next;
} node_t;

// TODO: Complete the functions below.
// You may create as many helper functions as you like.


node_t* create_list(int* wins, int* years, int length) {
    node_t* head = (node_t*)malloc(sizeof(node_t));
    if (head == NULL) {
        return NULL;
    }
    head->years = years[length-1];
    head->numWins = wins[length-1];
    head->next = NULL;

    node_t* cur = head;

    for (int i = length - 2; i >= 0; i -= 1) {
        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        if (newNode == NULL) {
            return NULL;
        }
        newNode->years = years[i];
        newNode->numWins = wins[i];
        cur->next = newNode;
        cur = cur->next;
    }
    return head;
}

// use the iterator pattern!
void print_list(node_t* list) {
    if (list == NULL) {
        return;
    }
    node_t* cur = list;
    while (cur != NULL) {
        printf("%d, %d wins\n", cur->years, cur->numWins);
        cur = cur->next;
    }
}

// use the iterator pattern here too!
void free_list(node_t* list) {
    if (list == NULL) {
        return;
    }
    node_t* cur = list;
    while (cur != NULL) {
        node_t* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    //TODO complete me!
}

int main(){ 
    int wins[] = {71, 78, 93, 93, 108};
    int years[] = {2014, 2015, 2016, 2017, 2018};
    node_t* redsox = create_list(wins, years, 5);
    print_list(redsox);
    free_list(redsox);

    return 0;
}
