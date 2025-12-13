typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct {
    Node *rear;
    Node *front;  
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* rc = malloc(sizeof(RecentCounter));
    rc->rear = NULL;
    rc->front = NULL;

    return rc;

}
int recentCounterPing(RecentCounter* obj, int t) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = t;
    newNode ->next = NULL;
    if(obj->front ==NULL){
        obj->front = newNode;
        obj->rear = newNode;

    }else{
    obj->rear->next= newNode;
    obj->rear = newNode;
    }
    
    int range = t-3000;
    while (obj->front != NULL && obj->front->data < range) {
        Node *del = obj->front;
        obj->front = obj->front->next;
        free(del);
    }

    int count = 0;
    Node *temp = obj->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count; 
}

void recentCounterFree(RecentCounter* obj) {
    Node *temp = obj->front;
    while(temp!=NULL){
        Node *f = temp;
        temp = temp->next;
        free(f);
    }
    free(obj);
    
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/