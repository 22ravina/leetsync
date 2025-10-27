bool isPalindrome(int start,int end, char *s){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
        
    }
    return true;

}
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
char* longestPalindrome(char* s) {
    if (s == NULL) return NULL;

    int n = strlen(s);
    // if (n == 0) {
    //     char *empty = malloc(1);
    //     if (empty) empty[0] = '\0';
    //     return empty;
    // }

    int maxLength = 0;
    int bestStart = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int length = 0;
            if (isPalindrome(i, j, s)) {
                length = j - i + 1;
            }
            if (max(length, maxLength) > maxLength) {
                maxLength = length;
                bestStart = i;
            }
        }
    }

    /* allocate and copy the result */
    char *ans = malloc(maxLength + 1);
    if (ans == NULL) return NULL; /* allocation failed */
    strncpy(ans, s + bestStart, maxLength);
    ans[maxLength] = '\0';
    return ans;
}

