typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
    int len;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *que = malloc(sizeof(MyCircularQueue));
    que->size = k;
    que->front = NULL;
    que->rear = NULL;
    que->len =0;
    return que;    
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size==0){
        return false;
    }
    if(obj->size==obj->len){
        return false;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    
    if(obj->front==NULL){
        obj->front = obj->rear = newNode;
        newNode->next = obj->front;
    }else{
        obj->rear->next = newNode;
        obj->rear = newNode;
        obj->rear->next = obj->front;
    }
    obj->len++;
    return true; 
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->len==0||obj->len<0){
        return false;
    }

    if(obj->len==1){
        free(obj->front);
        obj->front = NULL;
        obj->rear = NULL;
        obj->len--;
        return true;


    }
    Node *temp = obj->front;
    obj->front = obj->front->next;
    obj->rear->next = obj->front;
    obj->len--;
    free(temp);
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->front==NULL){
        return -1;
    }
    return obj->front->data;
    
}
int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->front==NULL){
        return -1;
    }
    return obj->rear->data;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->front == NULL){
        return true;
    }
    return false;
    
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->size ==obj->len){
        return true;
    }
    return false;
    
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj == NULL || obj->front == NULL) {
        free(obj);
        return;
    }
    Node *curr = obj->front;
    Node *next;

    do {
        next = curr;
        curr = curr->next;
        free(next);
    } while (curr!=obj->front);

    free(obj);
    
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/