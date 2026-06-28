#ifndef STACK_H
#define STACK_H

#define TRUE 1
#define FALSE 0

// Node for stack
typedef struct node {
    int data;
    struct node* next;
} StackNode;

// Stack structure
typedef struct {
    int count;
    StackNode* top;
} Stack;

// Function prototypes
Stack* createStack();
int push(Stack* stack, int item);
int pop(Stack* stack, int* item);
int stackTop(Stack* stack, int* item);
int isEmpty(Stack* stack);
void destroyStack(Stack* stack);

#endif

