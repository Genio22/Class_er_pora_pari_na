#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

//==================Linked list==========================
node *create_node(int data);
void insert_at_beginner(int data, node **head);
void insert_at_pos(int pos, int data, node **head);
void insert_at_end(int data, node **head);
void removefirst(node **head);
void remove_at_any(int pos, node **head);
void removelast(node **head);
void remove_duplicate(node **head);
void reverse(node **head);
void display(node *head);

node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_at_beginner(int data, node **head)
{
    node *newnode = create_node(data);
    newnode->next = *head;
    *head = newnode;
}

void insert_at_pos(int pos, int data, node **head)
{
    node *newnode = create_node(data);
    node *temp_prev, *temp_curr;
    int count = 1;
    temp_prev = temp_curr = *head;

    if (*head == NULL)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }
    while (count != pos)
    {
        temp_prev = temp_curr;
        temp_curr = temp_curr->next;
        count++;
    }
    newnode->next = temp_prev->next;
    temp_prev->next = newnode;
}

void insert_at_end(int data, node **head)
{
    node *newnode = create_node(data);
    newnode->next = NULL;
    node *current = *head;
    while (current != NULL)
    {
        current = current->next;
    }
    current->next = newnode;
}

// bool contains(int items){

// }

void removefirst(node **head)
{
    node *current = *head;
    *head = current->next;
    free(current);
}

void remove_at_any(int pos, node **head)
{
    node *current = *head;
    int count = 1;
    while (current->next->next != NULL && count < pos - 1)
    {
        current = current->next;
        count++;
    }
    node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void removelast(node **head)
{
    node *current = *head;
    while (current->next->next)
    {
        current = current->next;
    }
    current->next = NULL;
    free(current->next);
}

// void remove_duplicate(node **head)
// {
//     node *current = *head;
//     node *temp = NULL;
//     node *prev = NULL;
//     while (current)
//     {
//         prev = current;
//         temp = current->next;
//         while (temp){
//             if (temp -> data == current -> data){

//             }
//             temp = temp -> next;
//         }
//         current = current->next;
//     }
// }

void reverse(node **head)
{
    node *prev, *current, *next;
    current = *head;
    prev = NULL;
    next = NULL;
    while (current)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

void sort(node **head)
{
    if (!head)
        return;

    node *i, *j;
    int temp;

    for (i = *head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void display(node *head)
{
    struct node *current;
    current = head;

    while (current != NULL)
    {
        printf("[%d]", current->data, current->next);
        // printf("[%d|%p]", current->data, current -> next);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    free(current);
}

int main()
{

    return 0;
}
