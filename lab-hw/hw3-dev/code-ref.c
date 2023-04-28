
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



///
// =================== Support Code =================
// Queue
//
//
//
// - Implement each of the functions to create a working circular queue.
// - Do not change any of the function declarations
//   - (i.e. queue_t* create_queue(unsigned int _capacity) should not have additional arguments)
// - You should not have any 'printf' statements in your queue functions. 
//   - (You may consider using these printf statements to debug, 
//     but they should be removed from your final version)
// ==================================================
#ifndef MYQUEUE_H
#define MYQUEUE_H

// The main data structure for the queue
struct queue{
    unsigned int back;      // The next free position in the queue
                            // (i.e. the end or tail of the line)
    unsigned int front;     // Current 'head' of the queue
                            // (i.e. the front or head of the line)
    unsigned int size;      // How many total elements we currently have enqueued.
    unsigned int capacity;  // Maximum number of items the queue can hold
    int* data;              // The 'integer' data our queue holds   
};
// Creates a global definition of 'queue_t' so we 
// do not have to retype 'struct queue' everywhere.
typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
queue_t* create_queue(unsigned int _capacity){
    queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));
    if (myQueue == NULL) {
        return NULL;
    }
    myQueue->back = 0;
    myQueue->front = 0;
    myQueue->size = 0;
    myQueue->capacity = _capacity;
    myQueue->data = (int*)malloc(sizeof(int) * _capacity);

    return myQueue;
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
int queue_empty(queue_t* q){
    return q->size == 0;
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
int queue_full(queue_t* q){
    return q->size == q->capacity;
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the queue is full that is an error).
int queue_enqueue(queue_t* q, int item){
    if (q->size == q->capacity){
        return -1;
    }
    q->data[q->back] = item;
    q->back = (q->back + 1) % (q->capacity);
    q->size += 1;
    return 0; // Note: you should have two return statements in this function.
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty queue should crash the program, call exit(1)
int queue_dequeue(queue_t *q){
    if (q->size == 0){
        exit(1);
    }
    int first = q->data[q->front];
    q->front = (q->front + 1) % (q->capacity);
    q->size -= 1;

    return first; // Note: This line is a filler so the code compiles.
}


// Queue Size
// Queries the current size of a queue
// A queue that has not been previously created will crash the program.
// (i.e. A NULL queue cannot return the size, call exit(1))
unsigned int queue_size(queue_t* q){
    if (q == NULL) {
        exit(1);
    }
    return q->size;
}


// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q){
    // TODO: Implement me!
    if (q == NULL){
        return;
    }
    if (q->data != NULL){
        free(q->data);
    }
    free(q);
}


#endif


///


// =================== Support Code =================
// Stack
//
//
//
// - Implement each of the functions to create a working stack.
// - Do not change any of the function declarations
//   - (i.e. stack_t* create_stack() should not have additional arguments)
// - You should not have any 'printf' statements in your stack functions. 
//   - (You may consider using these printf statements to debug, 
//      but they should be removed from your final version)
// ==================================================
#ifndef MYSTACK_H
#define MYSTACK_H

// Stores the maximum 'depth' of our stack.
// Our implementation enforces a maximum depth of our stack.
// (i.e. capacity cannot exceed MAX_DEPTH for any stack)
# define MAX_DEPTH 32

// Create a node data structure to store data within
// our stack. In our case, we will stores 'integers'
typedef struct node{
    int data;
    struct node* next;
}node_t;

// Create a stack data structure
// Our stack holds a single pointer to a node, which
// is a linked list of nodes. No empty nodes should be used. 
typedef struct stack{
    int count;      // count keeps track of how many items
                // are in the stack.
    unsigned int capacity;  // Stores the maximum size of our stack
    node_t* head;       // head points to a node on the top of our stack.
}stack_t;

// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The stacks fields should also be initialized to default values.
stack_t* create_stack(unsigned int capacity){
    // Modify the body of this function as needed.
    stack_t* myStack = (stack_t*)malloc(sizeof(stack_t));   
    // TODO: Implement me!!
    if (myStack == NULL){
        return NULL;
    }
    myStack->count = 0;
    myStack->capacity = capacity;
    myStack->head = NULL;

    return myStack;
}

// Stack Empty
// Check if the stack is empty
// Returns 1 if true (The stack is completely empty)
// Returns 0 if false (the stack has at least one element enqueued)
int stack_empty(stack_t* s){
    // TODO: Implement me!!
    return s->count == 0;
}

// Stack Full
// Check if the stack is full
// Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
// Returns 0 if false (the Stack has more space available to enqueue items)
int stack_full(stack_t* s){
    return s->capacity == s->count;
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the Stack is full that is an error, but does not crash the program).
int stack_push(stack_t* s, int item){
    if (s->count == s->capacity){
        return -1;
    }
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL){
        return -1;
    }
    newNode->data = item;
    newNode->next = s->head;
    s->head = newNode;
    s->count += 1; 
    return 0; // Note: you should have two return statements in this function.
}

// Dequeue an item
// Returns the item at the front of the stack and
// removes an item from the stack.
// Removing from an empty stack should crash the program, call exit(1).
int stack_pop(stack_t* s){
    if (s->count == 0){
        exit(1);
    }
    node_t* front = s->head;
    int res = front->data;
    
    s->head = front->next;
    s->count -= 1;
    free(front);
    return res; // Note: This line is a 'filler' so the code compiles.
}

// Stack Size
// Queries the current size of a stack
// A stack that has not been previously created will crash the program.
// (i.e. A NULL stack cannot return the size)
unsigned int stack_size(stack_t* s){
    if (s == NULL){
        exit(1);
    }
    return s->count;
}

// Free stack
// Removes a stack and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_stack(stack_t* s){
    if (s == NULL){
        return;
    }
    while (s->count > 0){
        stack_pop(s);
    }
    free(s);
}

#endif