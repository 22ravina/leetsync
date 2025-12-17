/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);   // ascending
}
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    qsort(deck, deckSize, sizeof(int), cmp);

    int* ans = malloc(deckSize * sizeof(int));
    *returnSize = deckSize;

    int queue[10000];
    int front = 0, rear = 0;

    for (int i = 0; i < deckSize; i++){
        queue[rear++] = i;
    }
                       
    for (int i = 0; i < deckSize; i++) {
        int idx = queue[front++];     
        ans[idx] = deck[i];

        if (front < rear) {           
            queue[rear] = queue[front];
            rear++;
            front++;
        }
    }
    return ans;
    
}