int evalRPN(char **tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *t = tokens[i];

        // If the token is an operator
        if (strcmp(t, "+") == 0 || strcmp(t, "-") == 0 ||
            strcmp(t, "*") == 0 || strcmp(t, "/") == 0) {
            
            int b = stack[top--];   // second operand
            int a = stack[top--];   // first operand
            int result;

            if (strcmp(t, "+") == 0) result = a + b;
            else if (strcmp(t, "-") == 0) result = a - b;
            else if (strcmp(t, "*") == 0) result = a * b;
            else result = a / b;  // integer division

            stack[++top] = result;
        } 
        else {
            // Convert string to int and push
            stack[++top] = atoi(t);
        }
    }

    return stack[top];   // final answer
}
