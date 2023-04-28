/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* dum = (struct ListNode*)malloc(sizeof(struct ListNode)); // create a dummy node
    dum->next = head; // point the next of the dummy node to the head of the list
    // set the write node to the dummy node
    struct ListNode* write = dum; 
    // set the readrent node to the head of the list
    struct ListNode* read = head; 
    
    // traverse the list
    while (read) { 
        // if the next node is not null and has the same value as the readrent node
        if (read->next && read->val == read->next->val) {
            // traverse the list until a node with a different value is found
            while (read->next && read->val == read->next->val) {
                read = read->next;
            }
            // link the writevious node to the next node of the readrent node
            write->next = read->next;
        } else {
            write = read; // move the writevious node to the readrent node
        }
        read = read->next; // move the readrent node to its next node
    }
    
    return dum->next; // return the head of the modified list
}

/*
As for the alternative solution, a brute force approach would be to compare each node with all the nodes that come after it and remove any duplicates found. However, this approach would have a time complexity of O(n^2) which is not efficient for larger inputs. 

The edge cases for this solution are when the input list is empty or has only one node. These cases are handled correctly because the dummy node is created and linked to the head of the list, and the while loop will not execute if the head is null.

The chosen solution has a time complexity of O(n) because it only traverses the list once.
The space complexity of the solution is O(1) because it only uses a constant amount of extra memory regardless of the size of the input.
*/