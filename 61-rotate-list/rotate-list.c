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
struct ListNode* deleteTail(struct ListNode* head){
    struct ListNode* temp = head;
    if(temp==NULL){
        return head;
    }
    if(temp->next ==NULL){
        return head;
    }
    while(temp->next!=NULL && temp->next->next!=NULL){
        temp = temp->next;
    }
    struct ListNode* dNode = temp->next;
    temp->next = temp->next->next;
    return dNode;
}
struct ListNode* addFirst(struct ListNode* head,struct ListNode* node){
    node->next = head;
    return node;

}
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int n = len(head);
    if(n == 0 || k == 0) return head;
    k = k%n;
    if(k == 0) return head;
    struct ListNode* dNode = NULL;
    struct ListNode* Main_Head =head;
    for(int i=0;i<k;i++){
        dNode = deleteTail(head);
        Main_Head = addFirst(Main_Head,dNode);
        
    }
    return Main_Head;
 
}