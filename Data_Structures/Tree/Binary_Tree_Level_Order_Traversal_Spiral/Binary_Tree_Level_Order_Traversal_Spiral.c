#include <stdio.h>
#include <stdlib.h>

// Tree Node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} NODE;

// Stack node
typedef struct Stack {
    NODE* dataPtr;
    struct Stack* nextStack;
} STACK;

// Create tree node
NODE* createNode(int data) {
    NODE* head = (NODE*) malloc(sizeof(NODE));
    head->data = data;
    head->left = NULL;
    head->right = NULL;
    
    return head;
}

// Create Stack node
STACK* createStack(NODE* dataPtr) {
    STACK* list = (STACK*) malloc(sizeof(STACK));
    list->dataPtr = dataPtr;
    list->nextStack = NULL;
    
    return list;
}

// Insert Stack node
STACK* push(NODE* dataPtr, STACK* list) {
    if (list == NULL) {
        list = createStack(dataPtr);
        // printf("Inside push %d ", (list->dataPtr)->data);
        return list;
    }
    STACK* newNode = createStack(dataPtr);
    newNode->nextStack = list;
    list = newNode;
    // printf("Inside push %d ", (list->dataPtr)->data);
    
    return list;
}

// Remove Stack node
STACK* pop(STACK* list) {
    if (list == NULL || list ->nextStack == NULL) {
        free(list);
        return NULL;
    }
    
    STACK* temp;
    temp = list;
    list = list->nextStack;
    free(temp);
    
    return list;
}

// Get top Stack node
NODE* peek(STACK* list) {
    return list->dataPtr;
}

// Verify if stack is empty or not
int isEmpty(STACK* list) {
    if (list == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Prints stack (just for testing)
void printStack(STACK* s) {
    while(s != NULL) {
        printf("%d -> ", (s->dataPtr)->data);
        s = s->nextStack;
    }
    printf("\n");
}

// Prints spiral level order traversal of the Binary tree 
void printSpiral(NODE* head) {
    if (head == NULL) {
        return;
    }
    STACK* s1 = NULL;
    STACK* s2 = NULL;
    // printf("Here");
    s1 = push(head, s1);
    // printStack(s1);
    
    while (!isEmpty(s1) || !isEmpty(s2)) { 
        // Print nodes of current level from s1 and push nodes of 
        // next level to s2 
        while (!isEmpty(s1)) {
        NODE* temp = peek(s1); 
        s1 = pop(s1); 
        printf("%d ", temp->data); 
  
        // Note that is right is pushed before left 
        if (temp->right) 
            s2 = push(temp->right, s2); 
        if (temp->left) 
            s2 = push(temp->left, s2); 
        }
  
        // Print nodes of current level from s2 and push nodes of 
        // next level to s1 
        while (!isEmpty(s2)) { 
            NODE* temp = peek(s2); 
            s2 = pop(s2); 
            printf("%d ", temp->data); 
  
            // Note that is left is pushed before right 
            if (temp->left) 
                s1 = push(temp->left, s1);  
            if (temp->right) 
                s1 = push(temp->right, s1); 
        } 
    } 
}

// main
int main()
{
    // demo binary tree 
    NODE* root = createNode(1); 
    root->left = createNode(2); 
    root->right = createNode(3); 
    root->left->left = createNode(7); 
    root->left->right = createNode(6); 
    root->right->left = createNode(5); 
    root->right->right = createNode(4); 
    printf("Spiral Order traversal of binary tree is \n"); 
    printSpiral(root); 
  
    return 0;
}
