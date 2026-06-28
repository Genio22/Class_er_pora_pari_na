#ifndef STACK_H
#define STACK_H

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


#endif