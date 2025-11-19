typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

typedef struct HashNode {
    int key;
    Node *node;
    struct HashNode *next;
} HashNode;

typedef struct {
    int capacity;
    int size;
    Node *head, *tail;
    HashNode **hash;
} LRUCache;

#define HASH_SIZE 10007

int hashKey(int key) {
    return key % HASH_SIZE;
}

/* ---------- DLL FUNCTIONS with Dummy Nodes ---------- */

Node* createNode(int key, int value) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->prev = n->next = NULL;
    return n;
}

// Insert node right after dummy head (MRU)
void addToFront(LRUCache *obj, Node *n) {
    Node *first = obj->head->next;

    n->next = first;
    n->prev = obj->head;

    obj->head->next = n;
    first->prev = n;
}

// Remove node from list
void removeNode(Node *n) {
    Node *p = n->prev;
    Node *nx = n->next;

    p->next = nx;
    nx->prev = p;
}

HashNode* hashFind(HashNode* list, int key) {
    while (list) {
        if (list->key == key)
            return list;
        list = list->next;
    }
    return NULL;
}

void hashInsert(LRUCache *obj, int key, Node *node) {
    int h = hashKey(key);
    HashNode *hn = (HashNode*)malloc(sizeof(HashNode));
    hn->key = key;
    hn->node = node;
    hn->next = obj->hash[h];
    obj->hash[h] = hn;
}

void hashRemove(LRUCache *obj, int key) {
    int h = hashKey(key);
    HashNode *curr = obj->hash[h], *prev = NULL;

    while (curr) {
        if (curr->key == key) {
            if (prev) prev->next = curr->next;
            else obj->hash[h] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/* ---------- LRU CACHE FUNCTIONS ---------- */

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;

    obj->hash = (HashNode**)calloc(HASH_SIZE, sizeof(HashNode*));

    // Create dummy head & tail
    obj->head = createNode(-1, -1);
    obj->tail = createNode(-1, -1);

    // Connect dummy nodes
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    return obj;
}


int lRUCacheGet(LRUCache* obj, int key) {
    HashNode *hn = hashFind(obj->hash[hashKey(key)], key);
    if (!hn) return -1;

    Node *n = hn->node;
    removeNode(n);
    addToFront(obj, n);

    return n->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    HashNode *hn = hashFind(obj->hash[hashKey(key)], key);

    if (hn) {
        Node *n = hn->node;
        n->value = value;
        removeNode(n);
        addToFront(obj, n);
        return;
    }

    Node *newNode = createNode(key, value);
    addToFront(obj, newNode);
    hashInsert(obj, key, newNode);
    obj->size++;

    if (obj->size > obj->capacity) {
        Node *lru = obj->tail->prev;

        hashRemove(obj, lru->key);
        removeNode(lru);
        free(lru);

        obj->size--;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node *curr = obj->head;
    while (curr) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode *hn = obj->hash[i];
        while (hn) {
            HashNode *next = hn->next;
            free(hn);
            hn = next;
        }
    }

    free(obj->hash);
    free(obj);
}
