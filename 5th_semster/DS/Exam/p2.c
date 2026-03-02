#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}

void in_at_beg(node **head, int data)
{
    node *newnode = createnode (data);
    if (head != NULL){
        newnode -> next = *head;
        (*head)->prev = newnode; 
    }
    head = newnode;
}



int main()
{

    return 0;
}
