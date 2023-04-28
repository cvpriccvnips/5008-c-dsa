#include <stdio.h>
#include <stdlib.h>

// 定义链表结构体
typedef struct node {
	int data;
	int priority;
	struct node* next;
} node_t;

typedef struct pq {
	struct node* front;
} pq_t;

node_t* createNode(int data, int priority) {
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = data;
	newNode->priority = priority;
	newNode->next = NULL;
	return newNode;
}

pq_t* createPriorityQueue() {
	pq_t* newQ = (pq_t*)malloc(sizeof(pq_t));
	newQ->front = NULL;
	return newQ;
}

int isEmpty(pq_t* q) {
	return q->front == NULL;
}

void enqueue(pq_t* q, int data, int priority) {
	node_t* newNode = createNode(data, priority);

	if (isEmpty(q) || priority > q->front->priority) {
		newNode->next = q->front;
		q->front = newNode;
	} else {
		node_t* cur = q->front;
		while (cur->next && cur->next->priority >= priority) {
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
	}
}

int dequeue(pq_t* q) {
	if (isEmpty(q)) {
		printf("empty.\n");
	} 
	node_t* tmp = q->front;
	int item = tmp->data;
	q->front = q->front->next;
	free(tmp);
	return item;

}

int peek(pq_t* q) {
	if (isEmpty(q)) {
		printf("empty.\n");
		return -1;
	} else {
		return q->front->data;
	}
}

int main() {
    pq_t* pq = createPriorityQueue();
    enqueue(pq, 5, 2);
    enqueue(pq, 7, 1);
    enqueue(pq, 9, 3);

    printf("%d\n", dequeue(pq));
    printf("%d\n", dequeue(pq));
    printf("%d\n", dequeue(pq));

    return 0;
}
