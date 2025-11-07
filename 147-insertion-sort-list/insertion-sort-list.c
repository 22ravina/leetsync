/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* insertionSortList(struct ListNode* head) {

//     if (!head || !head->next) return head; // base case
//     struct ListNode *temp = head;
//     struct ListNode *prev = NULL;
//     struct ListNode *curr = head->next;
//     struct ListNode *future= NULL;

//     while(curr!=NULL){
//         temp = head;
//         while(temp->next!=curr){
//             if(curr->val<=temp->val){
//                 future->next = curr->next;
//                 prev->next = curr;
//                 curr->next = temp;
//                 curr = future->next;
//                 break;
//             }
//             prev = temp;
//             temp = temp->next;
//         }
//         future = curr;
//         curr = curr->next;

//     }
//     return head;
   
// }
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head; // base case

    struct ListNode *temp, *prev, *curr, *future;
    curr = head->next;  // start from 2nd node
    head->next = NULL;  // mark first node as sorted part

    while (curr != NULL) {
        future = curr->next;  // store next node before changing pointers
        temp = head;
        prev = NULL;

        // find correct position to insert curr
        while (temp != NULL && temp->val < curr->val) {
            prev = temp;
            temp = temp->next;
        }

        // insert curr in correct place
        if (prev == NULL) {
            // insert at beginning
            curr->next = head;
            head = curr;
        } else {
            // insert after prev
            prev->next = curr;
            curr->next = temp;
        }

        // move to next node
        curr = future;
    }

    return head;
}
