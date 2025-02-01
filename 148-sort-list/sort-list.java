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
    public ListNode sortList(ListNode head) {
                if (head == null || head.next == null) {
            return head;
        }
        
        // Step 1: Split the list into two halves
        ListNode mid = getMid(head);
        ListNode left = sortList(head);
        ListNode right = sortList(mid);
        
        // Step 2: Merge the two sorted halves
        return merge(left, right);
    }
    
    // Helper function to find the middle of the linked list
    private ListNode getMid(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode mid = slow.next;
        slow.next = null; // Split the list into two halves
        return mid;
    }
    
    // Helper function to merge two sorted linked lists
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode();
        ListNode tail = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        
        // Attach the remaining nodes
        if (l1 != null) {
            tail.next = l1;
        } else {
            tail.next = l2;
        }
        
        return dummy.next;

        
    }
}