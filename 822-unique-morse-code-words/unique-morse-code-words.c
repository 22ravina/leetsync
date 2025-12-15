int uniqueMorseRepresentations(char** words, int wordsSize) {
    char *code[] = {
        ".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
        "...","-","..-","...-",".--","-..-","-.--","--.."
    };

    char result[100][1200];

    for (int i = 0; i < wordsSize; i++) {
        int pos = 0;
        for (int j = 0; words[i][j] != '\0'; j++) {
            int idx = words[i][j] - 'a';
            int len = strlen(code[idx]);

            memcpy(result[i] + pos, code[idx], len);
            pos += len;
        }
        result[i][pos] = '\0';   
    }

    int visited[100] = {0};
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        if (visited[i]!=0){
            continue;
        }
        count++;
        for (int j = i + 1; j < wordsSize; j++) {
            if (strcmp(result[i], result[j]) == 0) {
                visited[j] = 1;
            }
        }
    }

    return count;
}
