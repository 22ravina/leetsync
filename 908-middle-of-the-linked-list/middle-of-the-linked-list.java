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
    int size(ListNode head){
            ListNode temp = head;
            int count =0;
            while(temp!=null){
                count++;
                temp = temp.next;
            }
            return count;
        }
    
    public ListNode middleNode(ListNode head) {
    
        int mid = (size(head)/2);
        ListNode temp = head;
        for(int i=0;i<mid;i++){
            temp = temp.next;
        }
        ListNode current = temp;
        while(current!=null){
            System.out.print(temp.val +" ");
            current = current.next;
        }
        return temp;

        
    }
}