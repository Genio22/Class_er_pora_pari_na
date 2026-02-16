#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

// single link list Implementaion

queue_ll *create_queue_ll()
{
    queue_ll *q1 = (queue_ll *)malloc(sizeof(queue_ll));
    q1->head = q1->tail = NULL;
    q1->count = 0;
    return q1;
}

bool isempty_ll(queue_ll *q1)
{
    return q1->head == NULL;
}

void enqueue_ll(queue_ll *q1, int data)
{
    queuenode *newnode = (queuenode *)malloc(sizeof(queuenode));
    newnode->data = data;
    if (isempty_ll(q1))
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

void dequeue_ll(queue_ll *q1)
{
    queuenode *temp = q1->head;
    if (isempty_ll(q1))
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

int peek_ll(queue_ll *q1)
{
    return q1->head->data;
}

void show_queue_ll(queue_ll *q1)
{
    queuenode *temp = q1->head;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Array Implementation

queue_arr *create_queue_arr(int cap)
{
    queue_arr *q1 = (queue_arr *)malloc(sizeof(queue_arr));
    q1->arr = (int *)malloc(cap * sizeof(int));
    q1->front = -1;
    q1->rear = -1;
    q1->size = 0;
    q1->capacity = cap;
    return q1;
}

void enqueue_arr(int item, queue_arr *q1)
{
    if (q1->size == q1->capacity)
    {
        return;
    }
    q1->rear = (q1->front + q1->size) % q1->capacity;
    q1->arr[q1->rear] = item;
    q1->size++;
}

int dequeue_arr(queue_arr *q1)
{
    if (q1->size == 0)
    {
        return -1;
    }
    int r_items = q1->arr[q1->front];
    q1->front = (q1->front + 1) % q1->capacity;
    q1->size--;
    return r_items;
}

int peek_arr(queue_arr *q1)
{
    if (q1->size == 0)
    {
        return -1;
    }
    return q1->arr[q1->front];
}

bool isFull_arr(queue_arr *q1)
{
    return q1->size == q1->capacity;
}

bool isempty_arr(queue_arr *q1)
{
    return q1->size == 0;
}

void show_queue_arr(queue_arr *q1)
{
    if (q1->size == 0)
    {
        return;
    }
    int i = q1->front;
    for (int count = 0; count < q1->size; count++)
    {
        printf("%d ", q1->arr[i]);
        i = (i + 1) % q1->capacity;
    }
}

// Task 3
void copy_arr(queue_arr *q_copy, queue_arr *q_to)
{
    if (q_copy->size == q_copy->capacity)
    {
        return;
    }
    int i = q_to->front = q_copy->front;
    q_to->capacity = q_copy->capacity;
    q_to->size = q_copy->size;
    for (int count = 0; count < q_copy->size; count++)
    {
        q_to->arr[i] = q_copy->arr[i];
        i = (i + 1) % q_copy->capacity;
    }
}

// Task 4
void neg_int_rem(queue_arr *q1)
{
    if (q1->size == 0)
    {
        return;
    }
    int *arr = (int *)malloc(q1->capacity * sizeof(int));
    int i = q1->front;
    int j = 0;
    for (int count = 0; count < q1->size; count++)
    {
        if (q1->arr[i] >= 0)
        {
            arr[j] = q1->arr[i];
            j++;
        }
        i = (i + 1) % q1->capacity;
    }

    i = q1->front = 0;
    q1->size = j;
    while (i < j)
    {
        q1->arr[i] = arr[i];
        i++;
    }
    q1->rear = j - 1;
    free(arr);
    arr = NULL;
}
