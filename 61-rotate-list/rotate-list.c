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
struct ListNode* removeTail(struct ListNode* head, struct ListNode** dNode) {
    if (head == NULL) {
        *dNode = NULL;
        return NULL;
    }

    if (head->next == NULL) { // only 1 node
        *dNode = head;
        return NULL;  // list becomes empty
    }

    struct ListNode* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    *dNode = temp->next;     // last node
    temp->next = NULL;       // detach tail

    return head;             // updated list
}

struct ListNode* addFirst(struct ListNode* head,struct ListNode* node){
    node->next = head;
    return node;

}
struct ListNode* rotateRight(struct ListNode* head, int k) {
    int n = len(head);
    if (n == 0 || k == 0) return head;

    k %= n;
    if (k == 0) return head;

    struct ListNode* dNode = NULL;

    while (k--) {
        head = removeTail(head, &dNode);  // get last node in dNode
        dNode->next = head;               // insert at head
        head = dNode;                     // update head
    }

    return head;
}
