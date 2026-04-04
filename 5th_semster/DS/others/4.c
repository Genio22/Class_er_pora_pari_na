#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void showStack(Stack *stack)
{

    StackNode *temp = stack ->top;

    while(temp != NULL)
    {
        printf("%c",()temp->data);
        temp = temp->next;
    }

}

int main()
{
    char str[] = "Hello";

    int *data = NUll;

    Stack *stack = createStack();

    int i = 0;

    while( str[i] != NULL )
    {
        push(stack,str[i]);
        i++;
    }


    showStack(stack);

    printf("%d",stack->top->data);


    i=0;

    while( (str[i] != NULL) && (!isEmpty(stack)) )
    {
        str[i] = stack ->top->data;
        pop(stack,data);
        i++;


        if(isEmpty(stack))
        {
            destroyStack(stack);
        }

    }



    printf("%s",str);



    return 0;
}
