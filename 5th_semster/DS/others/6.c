#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} queuenode;

typedef struct
{
    int count;
    queuenode *head;
    queuenode *tail;
} queue;

queue *create_queue()
{
    queue *q1 = (queue *)malloc(sizeof(queue));
    q1->head = q1->tail = NULL;
    q1->count = 0;
    return q1;
}

bool isempty(queue *q1)
{
    return (q1->head == NULL) ? true : false;
}

void push(queue *q1, int data)
{
    queuenode *newnode = (queuenode *)malloc(sizeof(queuenode));
    newnode->data = data;
    if (isempty(q1))
    {
        q1->head = q1->tail = newnode;
    }
    else
    {
        q1->tail->next = newnode;
        q1->tail = newnode;
    }
    newnode->next = NULL;
    q1->count++;
}

void pop(queue *q1)
{
    queuenode *temp = q1->head;
    if (isempty(q1))
    {
        return;
    }

    q1->head = temp->next;
    if (q1->head == NULL)
    {
        q1->tail = NULL;
    }
    free(temp);
    q1->count--;
}

void show_queue(queue *q1)
{
    queuenode *temp = q1->head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    queue *q1 = create_queue();
    push(q1, 10);
    push(q1, 20);
    push(q1, 30);
    push(q1, 40);
    push(q1, 50);
    push(q1, 60);
    push(q1, 70);

    show_queue(q1);

    pop(q1);
    pop(q1);

    show_queue(q1);

    return 0;
}

// By sAhAf🙂




