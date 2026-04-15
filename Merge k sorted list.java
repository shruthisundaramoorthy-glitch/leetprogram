class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        

        PriorityQueue<ListNode> minHeap = new PriorityQueue<>(Comparator.comparingInt(node -> node.val));
        
      
        for (ListNode list : lists) {
            if (list != null) {
                minHeap.offer(list);
            }
        }

      
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

      
        while (!minHeap.isEmpty()) {
         
            ListNode node = minHeap.poll();
            current.next = node; 

        
            if (node.next != null) {
                minHeap.offer(node.next); 
            }
            current = current.next; 
        }

        return dummy.next; 
    }

    
}
