typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *rear;
    Node *front;
    int size;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter *newNode = malloc(sizeof(RecentCounter));
    newNode->rear = NULL;
    newNode->front = NULL;
    newNode->size = 0;
    return newNode;   
}
//are u there ??


int recentCounterPing(RecentCounter* obj, int t) {
    Node *temp = malloc(sizeof(Node));
    temp->data = t;
    temp->next = NULL;
    

    if(obj->front==NULL){
        obj->front=obj->rear=temp;
        obj->size++;
    }else{
        obj->rear->next = temp;
        obj->rear = temp;
        obj->size++;
    }

    int range = t-3000;
    
    if(range<0){
        return obj->size;
    }
    while(obj->front!=NULL && obj->front->data<range){
        Node *del = obj->front;
        obj->front=obj->front->next;
        free(del);
        obj->size--;
    }
    return obj->size;

    
}

void recentCounterFree(RecentCounter* obj) {
    Node* temp = obj->front;
    while(temp!=NULL){
        Node* f = temp;
        temp = temp->next;
        free(f);
    }
    free(obj);

    
}

