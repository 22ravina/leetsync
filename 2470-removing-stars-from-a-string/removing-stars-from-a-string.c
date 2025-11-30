int len(char *s){
    int count =0;
    while(*s!='\0'){
        count++;
        s++;

    }
    return count;
}
char* removeStars(char* s) {
    int n = len(s);
    char *stack = (char*)malloc((n + 1) * sizeof(char));
    int top=-1;
    while(*s!='\0'){
        if(*s>='a'&& *s<='z'){
            top++;
            stack[top] = *s;
        }else if(*s=='*'){
            if (top >= 0){
                top--;
            }
        }
        s++;

    }
    stack[top + 1] = '\0'; 
    return stack;

    
}