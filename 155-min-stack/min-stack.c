typedef struct Node {
    int value;
    int minSoFar;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} MinStack;


MinStack* minStackCreate() {
    MinStack *st = (MinStack*)malloc(sizeof(MinStack));
    st->head = NULL;
    return st;
}

void minStackPush(MinStack* obj, int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = val;

    if (obj->head == NULL) {
        node->minSoFar = val;
    } else {
        if (val < obj->head->minSoFar)
            node->minSoFar = val;
        else
            node->minSoFar = obj->head->minSoFar;
    }

    node->next = obj->head;
    obj->head = node;
}

void minStackPop(MinStack* obj) {
    if (obj->head == NULL) return;

    Node *temp = obj->head;
    obj->head = obj->head->next;
    free(temp);
}

int minStackTop(MinStack* obj) {
    return obj->head->value;
}

int minStackGetMin(MinStack* obj) {
    return obj->head->minSoFar;
}

void minStackFree(MinStack* obj) {
    Node *curr = obj->head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
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