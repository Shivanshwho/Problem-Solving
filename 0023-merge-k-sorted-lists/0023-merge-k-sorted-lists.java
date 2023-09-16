import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        // Create a priority queue (min-heap) with a custom comparator
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);

        // Step 1: Add the first node from each list to the min-heap
        for (ListNode list : lists) {
            if (list != null) {
                minHeap.offer(list);
            }
        }

        // Step 2: Create a dummy node to simplify the code
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;

        // Step 3: Merge nodes from the min-heap until it's empty
        while (!minHeap.isEmpty()) {
            // Get the node with the smallest value from the min-heap
            ListNode node = minHeap.poll();

            // Add this node to the merged list
            current.next = node;
            current = current.next;

            // Step 4: If there's a next node in the same list, add it to the min-heap
            if (node.next != null) {
                minHeap.offer(node.next);
            }
        }

        // Step 5: Return the merged list starting from the next node of the dummy node
        return dummy.next;
    }
}
