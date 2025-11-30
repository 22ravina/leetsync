/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int len(struct ListNode* head){
    int count =0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}
bool isPalindrome(struct ListNode* head) {
    struct ListNode* temp = head;
    int n = len(head);
    for(int i=0;i<n/2;i++){
        temp = temp->next;
    }
    struct ListNode *rev = reverse(temp);
    struct ListNode* check = head;

    for(int i=0;i<n/2;i++){
        if(check->val!=rev->val){
            return false;
        }
        check = check->next;
        rev = rev->next;
    }
    return true;

    
}