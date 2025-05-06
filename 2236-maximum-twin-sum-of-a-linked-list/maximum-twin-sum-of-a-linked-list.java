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
    public static ListNode reverse(ListNode head){
        ListNode agla = null;
        ListNode prev = null;
        ListNode curr = head;
        while(curr!=null){
            agla = curr.next;
            curr.next = prev;
            prev = curr;
            curr = agla;
        }
        return prev;
    }
    public int pairSum(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode temp = reverse(slow.next);
        slow.next = temp;
        ListNode t1 = head;
        ListNode t2 = slow.next;
        int Maximum =0;
        while(t2!=null){
            int tempMax = t1.val +t2.val;
            if(tempMax>Maximum){
                Maximum = tempMax;
            }
            t1 = t1.next;
            t2 = t2.next;
        }
        return Maximum;
        
    }
}