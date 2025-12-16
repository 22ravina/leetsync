char* reverseWords(char* s) {
    int n = strlen(s);
    char *ans = malloc((n+1)*sizeof(char));

    char *doublestr[1000];
    int count =0;

    char *token = strtok(s," ");
    while(token!=NULL){
        doublestr[count++] = token;
        token = strtok(NULL, " ");
    }

    

    for(int j=0;j<count/2;j++){
        char *temp = doublestr[j];
        doublestr[j] = doublestr[count - 1 - j];
        doublestr[count - 1 - j] = temp;
    }

    int pos =0;
   
    for (int i = 0; i < count; i++) {
        int len = strlen(doublestr[i]);
        memcpy(ans + pos, doublestr[i], len);
        pos += len;
        if (i < count - 1) {
            ans[pos++] = ' ';
        }
    }

    ans[pos] = '\0';
    return ans;
}