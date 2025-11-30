typedef struct Node{
    int data;
    int minSoFar;
    struct Node *next;
}Node;


typedef struct {
    Node *head;    
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = ( MinStack*)malloc(sizeof(MinStack));
    obj->head = NULL;
    return obj;
    
}
void minStackPush(MinStack* obj, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    if(obj->head==NULL){
        newNode->minSoFar = val;
    }else{
        if(obj->head->minSoFar < val){
            newNode->minSoFar = obj->head->minSoFar;

        }else{
            newNode->minSoFar = val;

        }
    }
    newNode->next = obj->head;
    obj->head = newNode;
  
}

void minStackPop(MinStack* obj) {
    if(obj->head==NULL){
        return;
    }
    Node *temp = obj->head;
    obj->head = obj->head->next;
    free(temp);
}

int minStackTop(MinStack* obj) {
    return obj->head->data;
    
}

int minStackGetMin(MinStack* obj) {
    return obj->head->minSoFar;

    
}

void minStackFree(MinStack* obj) {
    Node *temp = obj->head;
    while(temp!=NULL){
        Node *freeP = temp;
        temp = temp->next;
        free(freeP);
    }
    free(temp);
    free(obj);
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/