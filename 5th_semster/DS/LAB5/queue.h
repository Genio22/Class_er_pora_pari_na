#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ===== Linked List Queue ===== */

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
} queue_ll;


queue_ll *create_queue_ll();
bool isempty_ll(queue_ll *q1);
void enqueue_ll(queue_ll *q1, int data);
void dequeue_ll(queue_ll *q1);
int peek_ll(queue_ll *q1);
void show_queue_ll(queue_ll *q1);

/* ===== Array Queue ===== */

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} queue_arr;



queue_arr *create_queue_arr(int cap);
void enqueue_arr(int item, queue_arr *q1);
int dequeue_arr(queue_arr *q1);
int peek_arr(queue_arr *q1);
bool isFull_arr(queue_arr *q1);
bool isempty_arr(queue_arr *q1);
void show_queue_arr(queue_arr *q1);

// Task work
void copy_arr(queue_arr *q_copy, queue_arr *q_to);
void neg_int_rem(queue_arr *q1);

#endif
