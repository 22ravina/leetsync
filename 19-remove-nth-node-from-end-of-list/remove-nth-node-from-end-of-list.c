/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int len(struct ListNode* head){
    int count =0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int l = len(head);
    int size = l-n;
    if(size==0){
        return head->next;
    }
    struct ListNode* temp = head;

    for(int i=0;i<size-1;i++){
        temp = temp->next;

    }

    temp->next = temp->next->next;
    return head;

    
}