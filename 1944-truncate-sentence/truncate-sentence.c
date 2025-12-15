char* truncateSentence(char* s, int k) {
    int n = strlen(s);
    char *ans = malloc((n+1)*sizeof(char));

    char *token = strtok(s," ");
    int pos =0;
    int i=0;
    while(i<k){
        int n = strlen(token);
        memcpy(ans+pos,token,n);
        pos+=n;
        i++;
        if(i!=k){
            ans[pos++] = ' ';

        }
        token = strtok(NULL," ");
    }
    ans[pos] = '\0';
    return ans;


    
}