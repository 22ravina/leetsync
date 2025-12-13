
#define MAX 30000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

/* Initialize stack */
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

/* Push element */
void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0)
        obj->minStack[obj->top] = val;
    else {
        int currentMin = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

/* Pop element */
void minStackPop(MinStack* obj) {
    obj->top--;
}

/* Get top element */
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

/* Get minimum element */
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

/* Free memory */
void minStackFree(MinStack* obj) {
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