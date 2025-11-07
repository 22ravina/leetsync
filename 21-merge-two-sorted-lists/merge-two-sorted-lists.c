/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *temp1 = list1;
    struct ListNode *temp2 = list2;
    struct ListNode *prev;
    struct ListNode *newHead;
    if(temp1==NULL && temp2==NULL){
        return temp1;
    }else if(temp1==NULL && temp2!=NULL){
        return temp2;
    }else if(temp2==NULL && temp1!=NULL){
        return temp1;

    }
        
    if(temp1->val<=temp2->val){
        newHead = temp1;
        prev = temp1;
        temp1 = temp1->next;
    }else{
        newHead = temp2;
        prev = temp2;
        temp2= temp2->next;
    }

    while(temp1!=NULL && temp2!=NULL){
        if(temp2->val<=temp1->val){
            prev->next = temp2;
            prev = prev->next;
            temp2= temp2->next;

        }else{
            prev->next = temp1;
            prev = prev->next;
            temp1 = temp1->next;

        }
    }
    if(temp1==NULL){
        prev->next = temp2;
    }else{
        prev->next = temp1;
    }
    return newHead;
    
}