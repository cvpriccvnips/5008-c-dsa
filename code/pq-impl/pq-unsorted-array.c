#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct PriorityQueue {
    int queue[MAX_SIZE];
    int size;
} PriorityQueue;

void init(PriorityQueue *pq) {
    pq->size = 0;
}

bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void enqueue(PriorityQueue *pq, int item) {
    pq->queue[pq->size] = item;
    pq->size++;
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        return -1;
    }
    int max_index = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->queue[i] > pq->queue[max_index]) {
            max_index = i;
        }
    }
    int item = pq->queue[max_index];
    pq->queue[max_index] = pq->queue[pq->size-1];
    pq->size--;
    return item;
}

int peek(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        return -1;
    }
    int max_index = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->queue[i] > pq->queue[max_index]) {
            max_index = i;
        }
    }
    int item = pq->queue[max_index];
    return item;
}

int main() {
    PriorityQueue pq;
    init(&pq);

    // 添加元素到队列中
    enqueue(&pq, 10);
    enqueue(&pq, 20);
    enqueue(&pq, 30);

    // 获取队列中的最大元素
    printf("当前队列中最大的元素是: %d\n", peek(&pq));

    // 将队列中的最大元素弹出
    printf("将最大元素 %d 弹出队列\n", dequeue(&pq));

    // 再次获取队列中的最大元素
    printf("当前队列中最大的元素是: %d\n", peek(&pq));

    return 0;
}