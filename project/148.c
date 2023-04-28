/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

// Function to get the middle node of a linked list
struct ListNode* getMid(struct ListNode* head) {
    struct ListNode* slow = head; // Initialize slow pointer to head
    struct ListNode* fast = head->next; // Initialize fast pointer to head's next
    // move slow and fast pointers until fast reaches the end of the list
    while (fast && fast->next) {
        slow = slow->next; // Move slow pointer one step forward
        fast = fast->next->next; // Move fast pointer two steps forward
    }
    return slow; // Return the middle node
}

// Function to merge two sorted linked lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    // create a dummy node to hold the merged list
    struct ListNode* dum = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = dum; // Initialize current pointer to dummy node
    
    while (l1 && l2) { // While both lists have nodes
        // If value of node in first list is less than value of node in second list
        if (l1->val < l2->val) {
            cur->next = l1; // Point current node to node in first list
            l1 = l1->next; // Move pointer of first list one step forward
        } else {
            cur->next = l2; // Point current node to node in second list
            l2 = l2->next; // Move pointer of second list one step forward
        }
        cur = cur->next; // Move current pointer one step forward
    }
    cur->next = l1 ? l1 : l2; // Append the remaining nodes of either list to the merged list
    return dum->next; // Return the merged list
}

// Sort a linked list using merge sort algorithm
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) {  // If list is empty or has only one node
        return head;
    }
    struct ListNode* mid = getMid(head); // Get middle pointer
    struct ListNode* right = mid->next; // Store next node of middle node
    mid->next = NULL; // Set next node of middle node to null
    
    // recursively sort the two halves and merge them back together
    struct ListNode* left_sorted = sortList(head); // Recursively sort the left half of the list
    struct ListNode* right_sorted = sortList(right); // Recursively sort the right half of the list
    return merge(left_sorted, right_sorted);  // Merge the sorted left and right halves of the list and return th
}

/*
Alternative solution:
A simple brute force solution could be to iterate through the list and compare each pair of adjacent nodes, swapping them if they are in the wrong order. This process can be repeated until the list is sorted. However, this solution would have a time complexity of O(n^2) in the worst case, which is not very efficient for large lists.

Chosen solution:
The chosen solution is to use merge sort to sort the linked list. This solution has a time complexity of O(n log n) 
space complexity of O(log n) due to the recursive call stack.

Edge cases and constraints:

One edge case to consider is when the input linked list is empty or has only one element. In these cases, the function simply returns the input list since it is already sorted.

Another edge case to consider is when the linked list has a very large number of elements. In this case, the recursive calls to sort the sublists may lead to a stack overflow error. To handle this, we can convert the recursive algorithm to an iterative algorithm that uses a stack data structure to store the sublists to be sorted.

Big O time and space complexity:

The time complexity of the chosen solution is O(n log n) because we divide the linked list into halves recursively until we get single nodes, and then we merge them back in a sorted manner. The space complexity of the solution is O(log n) due to the recursive call stack.


Q:
1.struct ListNode* fast = head->next; 为什么把fast设置为head.next而不是head?而且后者报错前者不报错？ 
1.The reason for setting fast to head->next instead of head is to make sure that the fast pointer starts ahead of the slow pointer (which is initialized as head). This is because in the while loop fast is incremented by two nodes while slow is incremented by one node, so starting fast at head->next ensures that the pointers are not initialized at the same node. If fast was initialized as head, the first iteration of the loop would increment both pointers at the same node, which would skip the first element in the list. The reason why setting fast to head results in an error is probably because when head is the only node in the list, head->next is NULL, which would cause a segmentation fault if you try to access it.

2. struct ListNode* rNext = r->next; 为什么设置r = rNext; // Set r pointer to the next node? 为什么这里是设置为next node？
2.The reason why r is set to rNext (which is r->next) is because rNext points to the start of the r half of the list, while r still points to the middle node. By setting r to rNext, we update the pointer to the start of the r half, which is necessary for merging the l and r halves. If we didn't do this, r would still point to the middle node, which would result in a segmentation fault when we try to access r->next in the merge function.

*/