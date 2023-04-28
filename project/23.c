struct ListNode *merge2Lists(struct ListNode *l1, struct ListNode *l2)
{
    // Create a dummy node to act as the head of the merged list
    struct ListNode *dum = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = dum;

    // While both lists have nodes remaining
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        // Move to the next node in the merged list
        cur = cur->next;
    }
    // Append any remaining nodes from l1 or l2 to the end of the merged list
    cur->next = l1 ? l1 : l2;
    // Return the head of the merged list
    struct ListNode *res = dum->next;
    free(dum);
    return res;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0)
        return NULL;

    // Iterate through the linked lists from the second one to the last one
    for (int i = 1; i < listsSize; i++)
    {
        // Merge the current linked list (lists[0]) with the i-th linked list
        // using the merge2Lists() function, and update the merged result in lists[0]
        lists[0] = merge2Lists(lists[0], lists[i]);
    }
    // Return the merged result in lists[0], which is the final merged linked list
    return lists[0];
}

/*
Alternative Solution:
A naive solution for merging k sorted lists would be to repeatedly merge pairs of lists until there is only one list left. This would have a time complexity of O(k^2 * n) because we would need to merge k/2 pairs in the first iteration, then k/4 pairs in the second iteration, and so on until we merge the final pair of lists. The space complexity would also be O(k^2 * n) because we would need to create k/2 new merged lists in the first iteration, then k/4 new merged lists in the second iteration, and so on until we have one final merged list.
 
Edge Cases and Constraints:
If the input list of lists is empty, the function should return NULL.
The values in the linked lists are assumed to be integers, but there are no constraints on the size of the integers.
If the integers are very large, there may be issues with memory usage or performance.
If the input lists contain duplicates, the merged list will also contain duplicates.

Q:
If len(lists) == 1, the while loop will not execute and the function will directly return the single list in the lists input. This is because there are no two lists to merge together.
Therefore, the function does not need to merge anything in this case and can simply return the single list in lists.
 
该算法的时间复杂度为O(kn)，空间复杂度为O(1)。
*/