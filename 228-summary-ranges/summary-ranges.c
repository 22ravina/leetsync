char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * numsSize);
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int start = nums[i];

        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1) {
            i++;
        }

        int end = nums[i];
        char buffer[50];

        if (start == end) {
            sprintf(buffer, "%d", start);
        } else {
            sprintf(buffer, "%d->%d", start, end);
        }

        result[*returnSize] = (char*)malloc(strlen(buffer) + 1);
        strcpy(result[*returnSize], buffer);
        (*returnSize)++;
    }

    return result;
}
