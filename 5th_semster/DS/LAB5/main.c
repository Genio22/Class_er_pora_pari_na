#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main()
{
    // Task 2
    /* Singly Linked List Queue */
    printf("-------LINKED LIST QUEUE-------\n");

    queue_ll *q1 = create_queue_ll();

    enqueue_ll(q1, 10);
    enqueue_ll(q1, 20);
    enqueue_ll(q1, 30);
    enqueue_ll(q1, 40);
    enqueue_ll(q1, 50);
    enqueue_ll(q1, 60);
    enqueue_ll(q1, 70);

    printf("Initial queue: ");
    printf("\n");
    show_queue_ll(q1);
    printf("\n");

    dequeue_ll(q1);
    dequeue_ll(q1);

    printf("After two dequeues: ");
    printf("\n");
    show_queue_ll(q1);
    printf("\n");

    printf("Front data: %d\n", peek_ll(q1));

    // Task 1
    /* Array Queue */
    printf("\n------- ARRAY QUEUE -------\n");

    int n;
    printf("Enter capacity: ");
    scanf("%d", &n);

    queue_arr *q = create_queue_arr(n);

    enqueue_arr(10, q);
    enqueue_arr(20, q);
    enqueue_arr(30, q);
    enqueue_arr(40, q);
    enqueue_arr(50, q);

    printf("Queue elements: ");
    show_queue_arr(q);
    printf("\n");

    printf("Dequeued: %d\n", dequeue_arr(q));
    printf("Dequeued: %d\n", dequeue_arr(q));

    printf("After dequeue: ");
    show_queue_arr(q);
    printf("\n");

    printf("Front data: %d\n", peek_arr(q));

    // Task 4
    /* Insert negatives and remove them */
    printf("\n------- REMOVE NEGATIVES -------\n");

    enqueue_arr(-60, q);
    enqueue_arr(70, q);
    enqueue_arr(-80, q);
    enqueue_arr(90, q);
    enqueue_arr(-100, q);
    enqueue_arr(-110, q);
    enqueue_arr(120, q);

    printf("Before removing negatives: ");
    show_queue_arr(q);
    printf("\n");

    neg_int_rem(q);

    printf("After removing negatives: ");
    show_queue_arr(q);
    printf("\n");

    // Task 3
    /* Copy queue */
    printf("\n------- COPY QUEUE -------\n");

    queue_arr *q2 = create_queue_arr(n);
    copy_arr(q, q2);

    printf("Copied queue: ");
    show_queue_arr(q2);
    printf("\n");

    // Test array
    // for (int i = 0; i < n; i++)
    // {
    //     q->arr[i] = i + 1;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d", q->arr[i]);
    // }

    return 0;
}
