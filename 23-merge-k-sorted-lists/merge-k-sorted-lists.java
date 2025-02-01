/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
                if (lists == null || lists.length == 0) {
            return null;
        }

        // Create a min-heap (priority queue) to store the nodes
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>(new Comparator<ListNode>() {
            @Override
            public int compare(ListNode l1, ListNode l2) {
                return l1.val - l2.val; // Compare node values for sorting
            }
        });

        // Add the head of each non-empty list to the min-heap
        for (ListNode list : lists) {
            if (list != null) {
                minHeap.offer(list);
            }
        }

        // Dummy node to simplify the merging process
        ListNode dummy = new ListNode();
        ListNode tail = dummy;

        // Merge the lists
        while (!minHeap.isEmpty()) {
            // Get the smallest node from the heap
            ListNode smallest = minHeap.poll();
            tail.next = smallest; // Add it to the result list
            tail = tail.next; // Move the tail pointer

            // If the smallest node has a next node, add it to the heap
            if (smallest.next != null) {
                minHeap.offer(smallest.next);
            }
        }

        return dummy.next; // Return the merged sorted list

        
    }
}