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

// Explanation:

// We create a priority queue (min-heap) to keep track of the smallest node from each list at any given time. The custom comparator ensures that the nodes are ordered by their values in ascending order.

// We iterate through all the lists and add the first node from each list to the min-heap if it's not null. This initializes the min-heap with the initial elements.

// We create a dummy node to simplify the code. The current pointer is used to keep track of the last node in the merged list.

// We repeatedly extract the node with the smallest value from the min-heap and add it to the merged list. If this node has a next node in its original list, we add that next node to the min-heap for further processing.

// Finally, we return the merged list starting from the next node of the dummy node, effectively excluding the dummy node from the result.