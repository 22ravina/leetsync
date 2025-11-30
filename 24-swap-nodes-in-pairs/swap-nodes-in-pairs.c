/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        return head;
    }
    struct ListNode* prev = (struct ListNode*)malloc(sizeof(struct ListNode));
    prev->val =-1;
    struct ListNode* mainHead = prev;

    struct ListNode* curr = head;
    struct ListNode* fut = NULL;
    while(curr!=NULL){
        fut = curr->next;
        if(fut==NULL){
            return mainHead->next;
        }
        curr->next = fut->next;
        prev->next = fut;
        fut->next = curr;
        prev = curr;
        curr = curr->next;
    }
    return mainHead->next;
   
}