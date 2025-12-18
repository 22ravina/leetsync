/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct {
    int count[26];      // frequency key
    char **words;       // list of anagrams
    int size;
} Group;
int sameKey(int *a, int *b) {
    for (int i = 0; i < 26; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {

    Group groups[10000];
    int gCount = 0;

    for (int i = 0; i < strsSize; i++) {

        int freq[26] = {0};
        for (int j = 0; strs[i][j]; j++)
            freq[strs[i][j] - 'a']++;

        int found = -1;
        for (int g = 0; g < gCount; g++) {
            if (sameKey(groups[g].count, freq)) {
                found = g;
                break;
            }
        }

        if (found == -1) {
            groups[gCount].words = malloc(strsSize * sizeof(char*));
            memcpy(groups[gCount].count, freq, sizeof(freq));
            groups[gCount].words[0] = strs[i];
            groups[gCount].size = 1;
            gCount++;
        } else {
            groups[found].words[groups[found].size++] = strs[i];
        }
    }

    char ***result = malloc(gCount * sizeof(char**));
    *returnColumnSizes = malloc(gCount * sizeof(int));

    for (int i = 0; i < gCount; i++) {
        result[i] = groups[i].words;
        (*returnColumnSizes)[i] = groups[i].size;
    }

    *returnSize = gCount;
    return result;
}
