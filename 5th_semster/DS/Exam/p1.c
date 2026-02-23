
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insertatbeg(node **head, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void display(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
}

// dll
typedef struct dnode
{
    int data;
    struct dnode *prev;
    struct dnode *next;
} dnode;

dnode *create_node_dll(int data)
{
    dnode *newnode = (dnode *)malloc(sizeof(dnode));
    newnode->data = data;
    newnode->prev = newnode->next = NULL;
    return newnode;
}

void delect(

void insertatbeg_dll(dnode **head, int data)
{
    dnode *newnode = create_node_dll(data);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void display_dll(dnode *head)
{
    dnode *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
}

int main()
{
    node *head = NULL;

    printf("Start\n");
    insertatbeg(&head, 10);
    insertatbeg(&head, 20);
    insertatbeg(&head, 30);
    insertatbeg(&head, 40);
    insertatbeg(&head, 50);
    insertatbeg(&head, 60);
    // printf("%d\n", head->data);
    display(head);
    printf("\n");

    // ddl
    dnode *head1 = NULL;
    printf("-----DLL-----\n");
    insertatbeg_dll(&head1, 10);
    insertatbeg_dll(&head1, 20);
    insertatbeg_dll(&head1, 30);
    insertatbeg_dll(&head1, 40);
    insertatbeg_dll(&head1, 50);
    insertatbeg_dll(&head1, 60);
    // printf("%d\n", head->data);
    display_dll(head1);
    printf("\n");
    printf("Try programiz.pro");

    return 0;
}