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
    public boolean hasCycle(ListNode head) {

        if(head==null || head.next==null){
            return false;
        }else if(head.next ==head){
            return true;
        }
        ListNode small = head;
        ListNode fast = head.next;

        while(small!=fast){
            if(small == null || fast==null|| small.next == null || fast.next==null){
                return false;
            }
        small = small.next;
        fast = fast.next.next;
        }
        return true;
        
    }
}