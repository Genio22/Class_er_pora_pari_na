#include <stdio.h>
#include <stdlib.h>

void THO(int n, char beg, char aux, char des)
{
    if (n == 1)
    {
        printf("Move from %c to %c\n", beg, des);
        return;
    }
    THO(n - 1, beg, des, aux);
    THO(1, beg, aux, des);
    THO(n - 1, aux, beg, des);
}

void digit_sum(int num)
{
    static int sum = 0;
    if (num == 0)
    {
        printf("Sum: %d\n", sum);
        return;
    }

    sum = num % 10 + sum;
    digit_sum(num / 10);
}

void gcd(int a, int b)
{
    if (b == 0)
    {
        printf("GCD: %d\n", a);
        return;
    }
    if (a == 0)
    {
        printf("GCD: %d\n", b);
        return;
    }
    gcd(b, a % b);
}

void printf_down(int num)
{
    if (num == 1)
    {
        printf("%d\n", num);
        return;
    }
    printf("%d", num);
    printf_down(num - 1);
}

int fibo(int n)
{

    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

void sum_fibo(int n)
{
    static int sum = 0;
    if (n == 0)
    {
        printf("Sum: %d\n", sum);
        return;
    }
    sum += fibo(n);
    sum_fibo(n - 1);
}

// int sum_fibo(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     return fibo(n) + sum_fibo(n - 1);
// }

// Link list

typedef struct node{
    int data;
    struct node *next;
}node;

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

// recursion for deleletion
node *delete_by_value(node *head, int target){
    if (head == NULL){
        return NULL;
    }
    
    if (head -> data == target){
        node *temp = head -> next;
        free(head);
        return temp;
    }

    head -> next = delete_by_value(head->next, target);
    return head;
}


void display(node *head)
{
    struct node *current;
    current = head;

    while (current != NULL)
    {
        printf("[%d]", current->data);
        // printf("[%d|%p]", current->data, current -> next);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }

}

node* sorted_insert(node* sorted, node* newnode){
    if(sorted == NULL || newnode->data <= sorted->data){
        newnode->next = sorted;
        return newnode;
    }

    sorted->next = sorted_insert(sorted->next, newnode);
    return sorted;
}


node* insertion_sort(node* head){
    if(head == NULL || head->next == NULL)
        return head;

    node* rest = insertion_sort(head->next);

    head->next = NULL;  
    return sorted_insert(rest, head);
}


int main(){

        gcd(36, 12);
    digit_sum(42);
    THO(4, 'A', 'B', 'C');

    sum_fibo(3);

    printf_down(6);
    



    node *head = NULL;

    printf("Start\n");
    insert_at_beginner(10, &head);
    insert_at_beginner(30, &head);
    insert_at_beginner(20, &head);
    insert_at_beginner(50, &head);
    insert_at_beginner(60, &head);
    insert_at_beginner(40, &head);
    display(head);
    
    printf("\n");
    head = delete_by_value(head, 30);
    display(head);
    
    printf("\n");
    head = insertion_sort(head);
    display(head);
    

    return 0;
}






