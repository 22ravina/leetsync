/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
//     struct ListNode *temp;
//     struct ListNode *prev=NULL;
//     for(int i=0;i<numsSize;i++){
//         temp = head;
//         prev = NULL;
//         while(temp!=NULL){
//             if(nums[i]==temp->val){
//                 if(temp==head){
//                     head = temp->next;
//                 }else{
//                     prev->next = temp->next;
//                 }
//                 temp = temp->next;
//                 continue;//skip iteration
//             }
//             prev = temp;
//             temp = temp->next;
            
//         }
//     }   
//     return head; 
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX 100001   // adjust according to constraints

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    int mark[MAX] = {0};  // hash-like array for O(1) lookup

    // Step 1: mark all numbers that need to be deleted
    for (int i = 0; i < numsSize; i++) {
        mark[nums[i]] = 1;
    }

    // Step 2: traverse linked list once and delete marked nodes
    struct ListNode *temp = head;
    struct ListNode *prev = NULL;

    while (temp != NULL) {
        if (mark[temp->val]==1) {  // if this value needs to be deleted
            if (temp == head) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            temp = temp->next;
            continue;  // skip updating prev when a node is removed
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
