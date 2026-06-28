#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node
{
    int data;
    struct dll_node *prev;
    struct dll_node *next;
} dll_node;

dll_node createnode(int data)
{
    dll_node *newnode = (dll_node *)malloc(sizeof(dll_node));
    newnode->prev = NULL;
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}

void in_at_beg(dll_node **head, int data)
{
    dll_node *newnode = createnode(data);
    if (head != NULL)
    {
        newnode->next = *head;
        (*head)->prev = newnode;
    }
    head = newnode;
}

typedef struct q_node
{
    int data;
    struct q_node *next;
} q_node;

typedef struct queue
{
    struct q_node *front;
    struct q_node *rear;
    int count;
} queue;

queue *create_queue()
{
    queue *new_queue = (queue *)malloc(sizeof(queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->count = 0;
}

q_node *create_qnode(int data)
{
    q_node *newnode = (q_node *)malloc(sizeof(q_node));
    newnode->data = data;
    newnode->next = NULL;
}

void enqueue_ll(queue *q, int data)
{
    q_node *newnode = create_qnode(data);
    if (q->count > 0)
    {
        q->rear->next = newnode;
    }
    q->front = newnode;
    q->rear = newnode;
}

void dequeue_ll(queue *q, int data)
{
    
}

int main()
{

    return 0;
}
