char* reverse(char *token){
    int n = strlen(token);
    for(int i=0;i<n/2;i++){
        char temp = token[i];
        token[i] = token[n-i-1];
        token[n-i-1] = temp;
    }
    return token;
    
}
char* reverseWords(char* s) {
    int n = strlen(s);
    char *ans = malloc((n+1)*sizeof(char));

    char *token = strtok(s," ");
    int pos =0;
    while (token != NULL){
        int tokenSize = strlen(token);
        char *r = reverse(token);
        memcpy(ans+pos,r,tokenSize);
        pos+=tokenSize;
        if(pos!=n){
            ans[pos] = ' '; 
            pos++;

        }
        token = strtok(NULL," ");  
    }
    ans[pos] = '\0';
    return ans;
    
}