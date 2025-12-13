int len(char *s){
    char *temp = s;
    int count =0;
    while(*temp!='\0'){
        count++;
        temp++;
    }
    return count;
}
char* removeDuplicates(char* s) {
    int n = len(s);
    char stack[n+1];
    int top = -1;
    for(int i=0;i<n;i++){
        if(top==-1){
            top++;
            stack[top] = s[i];
        }else if(stack[top]==s[i]){
            top--;
        }else{
            top++;
            stack[top] = s[i];
        }
    }
    char *ans = (char *)malloc((top + 2) * sizeof(char));

    for (int i = 0; i <= top; i++) {
         ans[i] = stack[i];
    }

    ans[top+1] = '\0';
return ans;
    
}