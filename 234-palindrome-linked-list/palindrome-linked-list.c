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
bool isPalindrome(struct ListNode* head) {
    int n = len(head);
    int arr[n];
    struct ListNode* temp = head;
    for(int i=0;i<n;i++){
        arr[i]=temp->val;
        temp = temp->next;
    }

    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-i-1]){
            return false;

        }
    }
    return true;

    
    
}