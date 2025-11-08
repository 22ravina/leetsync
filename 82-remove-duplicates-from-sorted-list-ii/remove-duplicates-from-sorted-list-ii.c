/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    int stack[205] =  {0};
    struct ListNode *temp = head;
    
    struct ListNode *newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newHead->next = NULL;

    while(temp!=NULL){
        stack[temp->val+100]++;
        temp = temp->next;
    }
    temp = head;
    struct ListNode *prev = newHead;
    
    while(temp!=NULL){
        if(stack[temp->val+100]==1){
            prev->next = temp;
            prev = prev ->next;
            
        }
        temp= temp->next;
    }
    prev->next = NULL;
    return newHead->next;
    
}