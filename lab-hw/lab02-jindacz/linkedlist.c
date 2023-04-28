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
    node_t* head = NULL;
    node_t* cur = NULL;
    int i;

    if (wins == NULL || years == NULL) {
        return NULL;
    }

    for (i = 0; i < length; i += 1) {
        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        if (newNode == NULL) {
            return NULL;
        }
        newNode->years = years[length - i - 1];
        newNode->numWins = wins[length - i - 1];
        newNode->next = NULL;

        if (head == NULL) {
           head = newNode; 
           cur = newNode;
        } else {
           cur->next = newNode;
           cur = newNode;
        }    
    }
    return head;
}

// use the iterator pattern!
void print_list(node_t* list) {
    node_t* cur = list;
    while (cur != NULL) {
        printf("%d, %d wins\n", cur->years, cur->numWins);
        cur = cur->next;
    }
}

// use the iterator pattern here too!
void free_list(node_t* list) {
    node_t* cur = list;
    while (cur != NULL) {
        node_t* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}

int main(){
    int wins[] = {71, 78, 93, 93, 108};
    int years[] = {2014, 2015, 2016, 2017, 2018};
    node_t* redsox = create_list(wins, years, 5);
    print_list(redsox);
    free_list(redsox);

    return 0;
}
