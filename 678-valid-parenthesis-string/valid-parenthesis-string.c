bool checkValidString(char* s) {
    int n = strlen(s);
    char stack[n];
    char star[n];
    int topStar =-1;
    int top =-1;
    for(int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        }
        else if (s[i] == '*') {
            star[++topStar] = i;   
        }else {  // ')'
            if (top >= 0) { 
                top--;           // match '('
            }
            else if (topStar >= 0) {
                topStar--;       // use '*' as ')'
            }
            else {
                return false;    // no match available
            }
        }
    }
    while (top >= 0 && topStar >= 0) {
        if (stack[top] > star[topStar]) return false;
        top--;
        topStar--;
    }

    return top==-1;
}