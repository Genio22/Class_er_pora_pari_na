#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

// Create a new empty stack
Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack)
    {
        stack->count = 0;
        stack->top = NULL;
    }
    return stack;
}

// Push an item onto the stack
int push(Stack *stack, int item)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode)
        return FALSE;

    newNode->data = item;
    newNode->next = stack->top;

    stack->top = newNode;
    stack->count++;

    return TRUE;
}

// Pop an item from the stack
int pop(Stack *stack, int *item)
{
    // int* item = NULL;
    if (stack->count == 0)
        return FALSE;

    StackNode *temp = stack->top;
    *item = temp->data;
    stack->top = temp->next;

    free(temp);
    stack->count--;

    return TRUE;
}

// Peek at the top of the stack
int stackTop(Stack *stack, int *item)
{
    if (stack->count == 0)
        return FALSE;

    *item = stack->top->data;
    return TRUE;
}

// Check if the stack is empty
int isEmpty(Stack *stack)
{
    return (stack->count == 0);
}

// Free all memory used by the stack
void destroyStack(Stack *stack)
{
    StackNode *temp;
    while (stack->top != NULL)
    {
        temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
    free(stack);
}
