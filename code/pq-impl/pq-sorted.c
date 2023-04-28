#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct PriorityQueue {
	int q[MAX_SIZE];
	int size;
} PriorityQueue_t;

PriorityQueue_t* createPQ() {
	PriorityQueue_t* pq = (PriorityQueue_t*)malloc(sizeof(PriorityQueue_t*));
	pq->size = 0;
	return pq;
}

int isEmpty(PriorityQueue_t* pq) {
	return pq->size == 0;
}

int isFull(PriorityQueue_t* pq) {
	return pq->size == MAX_SIZE;
}

void enqueue(PriorityQueue_t* pq, int item) {
	if (isFull(pq)) {
		printf("full.\n");
		return;
	}
	int i = pq->size-1;
	while (i >= 0 && pq->q[i] > item) {
		pq->q[i+1] = pq->q[i];
		i --;
	}
	pq->q[i+1] = item;
	pq->size ++;
}

int dequeue(PriorityQueue_t* pq) {
	if (isEmpty(pq)) {
		printf("empty.\n");
		return -1;
	}
	int item = pq->q[pq->size-1];
	pq->size --;
	return item;
}

int peek(PriorityQueue_t* pq) {
	if (isEmpty(pq)) {
		printf("pq is empty.\n");
		return -1;
	}
	return pq->q[pq->size-1];
}

int main() {
    struct PriorityQueue *pq = createPQ();

    // Enqueue some items
    enqueue(pq, 4);
    enqueue(pq, 2);
    enqueue(pq, 5);
    enqueue(pq, 1);
    enqueue(pq, 3);

    // Dequeue and print items
    while (!isEmpty(pq)) {
        int item = dequeue(pq);
        printf("%d ", item);
    }
    printf("\n");

    return 0;
}
// 在这个实现中，我们使用了一个固定大小的数组来存储优先队列元素。enqueue操作的时间复杂度为O(n)，因为我们需要遍历数组来找到正确的插入位置。dequeue和peek操作的时间复杂度都为O(1)，因为我们只需要访问数组的最后一个元素即可。
// 该实现具有一定的局限性，即数组的大小是固定的，如果优先队列的元素数量超过了数组的大小，则无法继续添加元素。如果要支持可变大小的优先队列，需要使用动态数组或链表等数据结构。