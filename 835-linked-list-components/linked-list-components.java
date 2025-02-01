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
    public int numComponents(ListNode head, int[] nums) {
                Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        
        int count = 0;
        while (head != null) {
            if (numSet.contains(head.val) && (head.next == null || !numSet.contains(head.next.val))) {
                count++;
            }
            head = head.next;
        }
        
        return count;
        
    }
}