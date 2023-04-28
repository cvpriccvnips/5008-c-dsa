/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* insertionSortList(struct ListNode* head) {
    // Dummy node to serve as the head of the sorted list
    struct ListNode* dum = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    dum->next = NULL;
    struct ListNode* cur = head;
    
    while (cur) {
        // Start searching for the insertion position from the beginning of the sorted list
        struct ListNode* pre = dum; 
        // Find the correct insertion position in the sorted list
        while (pre->next && pre->next->val <= cur->val) {
            pre = pre->next;
        }
        
        struct ListNode* nxt = cur->next; // store the next node to insert
        cur->next = pre->next; // Insert the current node into the sorted list
        pre->next = cur;
        cur = nxt; // Move on to the next node in the unsorted list
    }
    return dum->next;
}

/*
这段代码实现了链表的插入排序算法。其中，我们用一个dummy节点来充当已排序链表的头节点。我们从未排序链表的第一个节点开始，一直遍历到最后一个节点。
在每次遍历中，我们在已排序链表中查找要插入的位置。具体而言，我们从dummy节点开始遍历已排序链表，如果当前节点的值小于等于要插入节点的值，就继续向后遍历；否则，我们找到了插入的位置。
然后，我们将要插入节点插入到已排序链表中，即将它插入到我们找到的插入位置的前面。在插入过程中，我们需要用一个指针来保存下一个节点的地址，以便遍历下一个节点。
最后，我们返回dummy节点的下一个节点作为排序后的链表的头节点。

Alternative Solution:

An alternative solution for the problem is to use the selection sort algorithm. This algorithm works by selecting the smallest element in the unsorted portion of the list and swapping it with the first element of the unsorted portion. This process is repeated until the entire list is sorted. However, this algorithm has a worst-case time complexity of O(n^2), which is much worse than the O(n^2) time complexity of the insertion sort algorithm used in the given solution.

Edge Cases and Constraints:

In this solution, the dummy node is necessary. This is because inserting a new node before each node requires pointing to the previous node. Without a dummy node, the head node cannot be changed. Additionally, using a dummy node makes it easier to return the sorted linked list.

The given solution works for all cases, including the edge cases where the list is empty or has only one element. No additional constraints need to be considered as the solution is already optimized for the given problem.


Time and Space Complexity:

The time complexity of the given solution is O(n^2) because, in the worst-case scenario, each node has to be inserted into the sorted list, and each insertion requires traversing the sorted list, which can take up to n iterations. The space complexity of the solution is O(1) because only constant extra space is used to store the dummy node and a few pointers.

Q:
我们可以把dum节点想象成一个虚拟的头结点，它不存储任何值，只是为了方便在排序时插入新的节点。如果没有dum节点，我们需要特别处理链表头的情况，这会增加代码的复杂性。因此，dum节点的存在使代码更加简洁。

当dum->next = NULL时，dum节点确实是一个孤立点，它不会连接到任何其他节点。但是，随着排序的进行，我们会不断地将新的节点插入到dum节点后面，从而形成一个新的有序链表。因此，最终返回的链表的头部就是dum节点的下一个节点，即dum->next。

如果您将dum->next = head，那么在排序时，排序算法会尝试将head节点插入到dum节点后面，而不是将第一个待排序的节点插入到dum节点后面，这会导致代码无法正确执行。

在算法开始执行之前，我们创建了一个dum节点，它的next指针为空。

dum -> NULL
现在我们将cur指针指向链表的头节点head，也就是节点4。

cur -> 4
然后，我们进入while循环，并将pre指针指向dum节点。

pre -> dum -> NULL
cur -> 4
我们开始遍历链表，直到找到一个节点，它的值大于cur节点的值，或者到达了链表的末尾。在这个例子中，第一个遍历到的节点是dum节点，它的值是NULL，所以我们继续遍历下一个节点。

pre -> dum -> NULL
cur -> 4
接下来，我们到达了节点2，它的值比cur节点的值小。因此，我们将pre指针移动到节点2的位置。

pre -> dum -> 2 -> NULL
cur -> 4
现在，我们将nxt指针指向cur节点的下一个节点，即节点3。

pre -> dum -> 2 -> NULL
cur -> 4
nxt -> 3
我们现在将cur节点插入到pre节点的后面。

pre -> dum -> 2 -> 4 -> NULL
cur -> 3
现在我们将cur指针移动到节点3的位置，并继续遍历链表。

pre -> dum -> 2 -> 4 -> NULL
cur -> 3
我们到达了节点1，它的值比cur节点的值小，因此我们将pre指针移动到节点1的位置。

pre -> dum -> 1 -> 2 -> 4 -> NULL
cur -> 3
然后，我们将cur节点插入到pre节点的后面。


pre -> dum -> 1 -> 2 -> 3 -> 4 -> NULL
cur -> NULL
现在，cur指针指向NULL，while循环结束，排序完成。我们可以通过dum节点的next指针获得排序后的链表的头节点。

dum -> 1 -> 2 -> 3 -> 4 -> NULL
res -> 1 -> 2 -> 3 -> 4
因此，我们返回dum节点的next指针，也就是res节点，作为最终的结果。
*/