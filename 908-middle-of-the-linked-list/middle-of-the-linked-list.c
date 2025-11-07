/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int sizeofLL(struct ListNode *head){
    struct ListNode *temp = head;
    int size =0;
    while(temp!=NULL){
        size++;
        temp = temp->next;
    }
    return size;
}
struct ListNode* middleNode(struct ListNode* head) {
    int size = sizeofLL(head);
    struct ListNode *temp = head;

    for(int i=0;i<size/2;i++){
        temp = temp->next;
    }

    return temp;


    
}