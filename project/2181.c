/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    // Initialize sum = 0, write to the head and read to the next element in the list.
    struct ListNode* write = head;
    struct ListNode* read = head->next;
    int curSum = 0;
    // Loop through the list till read reaches the read of the list.
    while (read) {
        // In the loop, if read's value is 0
        if (read->val != 0) {
            curSum += read->val; // keep adding read's value to the current sum.
        } else {
            // make write move to the next list item and give it the value of the current sum
            write = write->next;
            write->val = curSum;
            curSum = 0; // Re-initialize the sum to 0.
        }
        read = read->next; // increment read
    }
    // When read pointer reaches the read of the list, make write tail None.
    write->next = NULL;
    return head->next;
}

/*
Alternative solution:
A brute force solution would be to traverse the linked list and keep track of the sum of nodes between two consecutive zeros. When two zeros are found, create a new node with the sum and connect it to the previous zero. This approach has a time complexity of O(n^2) as we need to traverse the list for each zero pair.
current = head
while current is not None:
    if current.val == 0:
        sum_between_zeros = 0
        next_node = current.next
        while next_node is not None and next_node.val != 0:
            sum_between_zeros += next_node.val
            next_node = next_node.next
        if next_node is not None:
            new_node = ListNode(sum_between_zeros)
            current.next = new_node
            new_node.next = next_node
        current = next_node
    else:
        current = current.next
上述代码会遍历整个链表，并且在每次找到连续两个 0 之后，需要再次遍历它们之间的节点来计算它们的和。这个计算和的过程是必要的，但是它的时间复杂度是 O(n)。因此，总时间复杂度是 O(n^2)。

Chosen solution:
The chosen solution uses two pointers to traverse the list only once and update the values of nodes between two consecutive zeros. It has a time complexity of O(n) and a space complexity of O(1) as it only uses constant extra space to store the pointers and the sum.

Edge cases and constraints:
The linked list can be empty, in which case the function returns None.
The linked list can contain only one zero node at the beginning and read, in which case the function returns a single node with value 0.
The linked list can contain only one zero node at the beginning, in which case the function returns a single node with the sum of all nodes after the zero node.
The linked list can contain only one zero node at the read, in which case the function returns a single node with the sum of all nodes before the zero node.
Questions:


Can you think of a scenario where the chosen solution would not work correctly?
- A scenario where the chosen solution would not work correctly is when the linked list contains only one zero.

Is there a more efficient solution that uses extra space but reduces the time complexity even further?
- A more efficient solution that uses extra space would be to create a new linked list to store the sum nodes as we traverse the original linked list. This approach has a time complexity of O(n) and a space complexity of O(n).

*/