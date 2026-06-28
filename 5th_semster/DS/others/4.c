#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} stacknode;

typedef struct
{
    int count;
    stacknode *top;
} stack;

// Create stack
stack *create()
{
    stack *stack1 = (stack *)malloc(sizeof(stack));
    if (stack1 == NULL)
    {
        printf("Fail to create stack.\n");
        return NULL;
    }
    stack1->count = 0;
    stack1->top = NULL;
    return stack1;
}

// Check if empty
int isEmpty(stack *s)
{
    return (s->count == 0);
}

// Push
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

// Pop
int pop(stack *stack1)
{
    if (isEmpty(stack1))
    {
        printf("Stack is empty.\n");
        return -1;
    }

    stacknode *temp = stack1->top;
    int data = temp->data;
    stack1->top = temp->next;
    free(temp);
    stack1->count--;

    return data;
}

// Display stack
void showStack(stack *stack1)
{
    stacknode *temp = stack1->top;

    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Destroy stack
void destroyStack(stack *stack1)
{
    while (!isEmpty(stack1))
    {
        pop(stack1);
    }
    free(stack1);
}

int main()
{
    char str[] = "Hello";

    stack *s = create();

    int i = 0;

    // Push characters
    while (str[i] != '\0')
    {
        push(s, str[i]);
        i++;
    }

    // Show stack
    showStack(s);

    // Reverse string using stack
    i = 0;
    while (!isEmpty(s))
    {
        str[i] = pop(s);
        i++;
    }

    printf("Reversed: %s\n", str);

    destroyStack(s);

    return 0;
}