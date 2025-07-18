/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head==null|| head.next==null){
            return null;
        }else if(head.next==head){
            return head;
        }
        ListNode slow = head;
        ListNode fast = head;
        while(fast!=null&& fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(fast==slow){
                break;
            }
        }
        if (fast == null || fast.next == null) {
            return null;
        }

        ListNode temp = head;
        while(slow!=temp){
            temp = temp.next;
            slow = slow.next;
        }
        return slow;
        
    }
}