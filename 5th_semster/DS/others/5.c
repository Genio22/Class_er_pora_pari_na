#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *create()
{
    stack *stack1 = (stack *)malloc(sizeof(stack));
    if (stack1 == NULL)
    {
        printf("Fail to create stack.");
        return stack1;
    }
    else
    {
        stack1->count = 0;
        stack1->top = NULL;
    }
    return stack1;
}

void push(stack *stack1, int data)
{
    stacknode *newnode = (stacknode *)malloc(sizeof(stacknode));
    if (!newnode)
        return;
    newnode->data = data;
    newnode->next = stack1->top;
    stack1->top = newnode;
    stack1->count++;
}

void pop(stack *stack1, int *data)
{
    if (stack1->count == 0)
    {
        printf("Stack is empty.");
        return;
    }
    stacknode *temp = stack1->top;
    *data = temp->data;
    stack1->top = temp->next;
    free(temp);
    stack1->count--;
}



int main()
{
    stack *stack1 = create();
    char str[] = "Hello World!";

    for (int i = 0; i < sizeof(str); i++)
    {
        push(myStack, str[i]);
    }

    
    return 0;
}
