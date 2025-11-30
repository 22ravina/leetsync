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
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp = head;
    for(int i=0;i<len(head)/2;i++){
        temp = temp->next;
    }
    return temp;


    
}