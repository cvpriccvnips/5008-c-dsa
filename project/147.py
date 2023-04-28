class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Dummy node to serve as the head of the sorted list
        dum = ListNode(0)
        toInsert = head
        
        while toInsert: # 0 - 1 - 2 - 4 - 3 - 7, sorted, 0124, insert = 3
            pre = dum # Start searching for the insertion position from the beginning of the sorted list
            nxt = toInsert.next # store the next node to insert
            
            while pre.next and pre.next.val <= toInsert.val:
                pre = pre.next # get position to insert
            
            toInsert.next = pre.next # Insert the current node into the sorted list
            pre.next = toInsert 
            
            toInsert = nxt # # Move on to the next node in the unsorted list
        return dum.next
"""
init dummy node
set to_insert node as head

while to_insert node exist:
    set pre node as dum
    while pre's next exist and its value < to_insert value:
        pre ++
    store store nxt pos 
    link to_insert.next to pre.next
    link pre.next to to_insert
    update to_insert
return dum.next
"""