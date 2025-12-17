typedef struct Node{
    int data;
    struct Node* prev;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
    int k;
    int size;
    
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *new = malloc(sizeof(MyCircularDeque));
    new->front = NULL;
    new->rear = NULL;
    new->k = k;
    new->size =0;

    return new;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->k==obj->size){
        return false;
    }
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    if(obj->front==NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        obj->front = obj->rear = newNode;
    }else{
        newNode->next = obj->front;
        newNode->prev = obj->rear;

        obj->front->prev = newNode;
        obj->rear->next = newNode;

        obj->front = newNode;
    }
    obj->size++;
    return true;
    
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->k) return false;

    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;

    if (obj->rear == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        obj->front = obj->rear = newNode;
    } else {
        newNode->prev = obj->rear;
        newNode->next = obj->front;

        obj->rear->next = newNode;
        obj->front->prev = newNode;

        obj->rear = newNode;
    }
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;

    Node *temp = obj->front;

    if (obj->size == 1) {
        obj->front = obj->rear = NULL;
    } else {
        obj->front = temp->next;
        obj->front->prev = obj->rear;
        obj->rear->next = obj->front;
    }

    free(temp);
    obj->size--;
    return true;
}


bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;

    Node *temp = obj->rear;

    if (obj->size == 1) {
        obj->front = obj->rear = NULL;
    } else {
        obj->rear = temp->prev;
        obj->rear->next = obj->front;
        obj->front->prev = obj->rear;
    }

    free(temp);
    obj->size--;
    return true;
}


int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->front->data;
}


int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;
    return obj->rear->data;
}


bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}


bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->k;
}


void myCircularDequeFree(MyCircularDeque* obj) {
    while (obj->size > 0) {
        myCircularDequeDeleteFront(obj);
    }
    free(obj);
}


/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/