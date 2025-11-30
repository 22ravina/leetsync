/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct ListNode *smallHead = NULL, *smallTail = NULL;
    struct ListNode *bigHead = NULL, *bigTail = NULL;
    struct ListNode *curr = head;
    while (curr != NULL) {
        if (curr->val < x) {
            if (smallHead == NULL) {
                smallHead = curr;
                smallTail = curr;
            } else {
                smallTail->next = curr;
                smallTail = curr;
            }
        } else {
            if (bigHead == NULL) {
                bigHead = curr;
                bigTail = curr;
            } else {
                bigTail->next = curr;
                bigTail = curr;
            }
        }
        curr = curr->next;
    }
    
    if (smallHead == NULL) {
        if (bigTail!=NULL) bigTail->next = NULL;
        return bigHead;
    }
    smallTail->next = bigHead;

    if (bigTail!=NULL) bigTail->next = NULL;

    return smallHead;
 
}