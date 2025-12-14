typedef struct Node{
    char *data;
    struct Node *next;
}Node;

Node *push_st(Node *head,char *val){
    if(val==NULL){
        return head;
    }
    Node *newNode = malloc(sizeof(Node));
    int n = strlen(val);
    newNode->data = malloc((n+1)*sizeof(char));
    strcpy(newNode->data,val);

    newNode->next = head;
    return newNode;
}

Node *pop_st(Node *head){
    if (head == NULL) {
        return NULL;
    }
    Node *temp = head;
    Node* newHead = head->next;
    free(temp->data);
    free(temp);
    return newHead;
}
char* simplifyPath(char* path) {
    Node *head = NULL;
    int n = strlen(path);

    char *token = strtok(path,"/");
    while(token!=NULL){
        if (strcmp(token, ".") == 0) {
            // do nothing
        }
        else if (strcmp(token, "..") == 0) {
            head = pop_st(head);
        }
        else {
            head = push_st(head, token);
        }

        token = strtok(NULL,"/");
    }

    Node* rev = NULL;
    while (head != NULL) {
        rev = push_st(rev, head->data);
        head = pop_st(head);
    }
    char *ans = malloc(n+ 2);
    int i = 0;
    ans[i] = '/';
    i++;

    while (rev != NULL) {
        int len = strlen(rev->data);
        memcpy(ans + i, rev->data, len);
        i += len;

        if (rev->next != NULL)
            ans[i++] = '/';

        rev = rev->next;
    }
    ans[i] = '\0';
    return ans;
}