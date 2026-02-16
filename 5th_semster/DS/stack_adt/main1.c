#include <stdio.h>
#include "stack.h"



void reverse_string(Stack *stack)
{
    Stack *myStack = createStack();
    if (!myStack) return;
    printf("Enter someting: ");
    char in[30];
    fgets(in, sizeof(in), stdin);

    for (int i = 0; in[i] != '\0' ; i++)
    {
        push(myStack, in[i]);
    }

    // push(myStack, 10);
    // push(myStack, 20);
    // push(myStack, 30);

     int value;
    // if (stackTop(myStack, &value))
    //     printf("Top of stack: %c\n", value);

    printf("Reverse:\n");
    while (!isEmpty(myStack))
    {
        pop(myStack, &value);
        printf("%c", value);
    }

    destroyStack(myStack);
}

int main()
{
    Stack *myStack = createStack();

    char str[] = "Hello World!";

    for (int i = 0; i < sizeof(str); i++)
    {
        push(myStack, str[i]);
    }

    // push(myStack, 10);
    // push(myStack, 20);
    // push(myStack, 30);

    int value;
    if (stackTop(myStack, &value))
        printf("Top of stack: %d\n", value);

    printf("Popping stack:\n");
    while (!isEmpty(myStack))
    {
        pop(myStack, &value);
        printf("%d\n", value);
    }

    destroyStack(myStack);
    return 0;
}


