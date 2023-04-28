#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} Heap;

// 创建一个新堆
Heap* createHeap() {
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->size = 0;
    return heap;
}

/*
这是实现堆（heap）数据结构中用来计算节点之间关系的三个函数。
其中，parent(i) 返回节点 i 的父节点在数组中的索引，leftChild(i) 返回节点 i 的左子节点在数组中的索引，rightChild(i) 返回节点 i 的右子节点在数组中的索引。
这些函数的输入参数 i 是一个节点在数组中的索引，输出结果是对应节点在数组中的父节点、左子节点或右子节点的索引。
*/
int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

// 检查堆是否为空
bool isEmpty(Heap* heap) {
    return heap->size == 0;
}

// 向堆中插入一个元素，并保持堆的性质
void enqueue(Heap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Error: Heap is full\n");
        return;
    }

    int i = heap->size;
    heap->data[i] = value;
    heap->size++;
	/*
	上滤是指将新的元素插入到堆中并将其上移直到满足堆的性质。

	在enqueue函数中，当一个新元素被插入到堆的末尾时，我们需要将其上移以满足堆的性质。具体来说，我们需要将其与父节点比较，如果比父节点小，则交换这两个元素。然后将新元素的索引更新为父节点的索引，继续执行这个过程，直到到达堆的根节点或者父节点比新元素小。

	这个循环的条件是：堆不为空（即i > 0）并且新元素比其父节点小（即heap->data[i] < heap->data[parent(i)]）。在循环中，我们执行交换操作来将新元素向上移动，然后将其索引更新为其父节点的索引。如果循环结束时，新元素已经到达了堆的根节点，或者它的父节点比它小，那么这个循环就结束了。
	*/
    while (i > 0 && heap->data[i] < heap->data[parent(i)]) {
        int tmp = heap->data[parent(i)];
        heap->data[parent(i)] = heap->data[i];
        heap->data[i] = tmp;
		/*这一行代码的作用是将 i 的值更新为其父节点的索引。在 while 循环中，我们将 i 与其父节点比较，如果 heap->data[i] 小于其父节点的值，就交换这两个元素，然后将 i 更新为其父节点的索引，继续循环直到 i 已经是根节点或者不再小于其父节点为止。*/
        i = parent(i);
    }
}

/*
这个函数是从堆中删除最小元素，并保持堆的性质。具体的实现步骤是：

将堆中第一个元素（即最小元素）取出来，保存到变量 min 中。
将堆的大小减一。
将堆的最后一个元素放到堆的根节点上，保持堆的完全二叉树形态。
比较当前节点和其左右子节点的大小，找到最小的那个节点。
如果当前节点比左右子节点中最小的还要小，说明已经满足了堆的性质，可以退出循环。
否则，交换当前节点和最小子节点的位置，继续循环到找到当前节点和其子节点满足堆的性质。
返回 min 变量，即为删除的最小元素。
*/
int dequeue(Heap* heap) 
{
    if (isEmpty(heap)) 
	{
        printf("Error: Heap is empty\n");
        return -1;
    }

    int min = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];

    int i = 0;
	// 这个循环会一直执行直到当前节点没有子节点，也就是当前节点是叶子节点，因为如果当前节点是叶子节点，那么就没有必要再向下比较和交换了，因为叶子节点不再有子节点可以比较。
    while (leftChild(i) < heap->size) 
	{
        int child = leftChild(i);
		// 这里先假设当前节点的左子节点是最小的，然后检查右子节点是否存在，并且比左子节点小，如果是，则将child指向右子节点。
        if (rightChild(i) < heap->size && heap->data[rightChild(i)] < heap->data[child]) 
		{
            child = rightChild(i);
        }
		// 如果当前节点已经比它的子节点中的最小值还小，那么不需要交换，退出循环。
        if (heap->data[i] <= heap->data[child]) 
		{
            break;
        }
		// 如果当前节点不是最小的，就将当前节点和子节点中最小的交换位置，然后将当前节点的指针指向交换后的子节点，以便下一轮循环继续比较和交换。
        int tmp = heap->data[i];
        heap->data[i] = heap->data[child];
        heap->data[child] = tmp;
        i = child;
    }
    return min;
}

// 获取堆中最小元素
int peek(Heap* heap) {
    if (isEmpty(heap)) {
        printf("Error: Heap is empty\n");
        return -1;
    }

    return heap->data[0];
}

int main() {
    Heap* heap = createHeap();

    // 测试isEmpty和peek
    printf("Is heap empty? %s\n", isEmpty(heap) ? "yes" : "no");
    printf("Peek at heap: %d\n\n", peek(heap));

    // 测试enqueue
    printf("Enqueue 5, 10, 3, 8, 2, 7\n");
    enqueue(heap, 5);
    enqueue(heap, 10);
    enqueue(heap, 3);
    enqueue(heap, 8);
    enqueue(heap, 2);
    enqueue(heap, 7);

    printf("Is heap empty? %s\n", isEmpty(heap) ? "yes" : "no");
	    // 测试peek
    printf("Peek at heap: %d\n\n", peek(heap));

    // 测试dequeue
    printf("Dequeue elements from heap: ");
    while (!isEmpty(heap)) {
        printf("%d ", dequeue(heap));
    }
    printf("\n");

    // 测试isEmpty和peek
    printf("Is heap empty? %s\n", isEmpty(heap) ? "yes" : "no");
    printf("Peek at heap: %d\n\n", peek(heap));

    // 释放内存
    free(heap);
    return 0;
}