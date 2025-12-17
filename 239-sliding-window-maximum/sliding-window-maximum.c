int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *ans = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int *dq = (int*)malloc(numsSize * sizeof(int)); // deque of indices
    int front = 0, rear = -1;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        // remove out-of-window index
        if (front <= rear && dq[front] <= i - k)
            front++;

        // maintain decreasing order
        while (front <= rear && nums[dq[rear]] <= nums[i])
            rear--;

        dq[++rear] = i;

        // window formed
        if (i >= k - 1)
            ans[idx++] = nums[dq[front]];
    }

    *returnSize = idx;
    free(dq);
    return ans;
}
