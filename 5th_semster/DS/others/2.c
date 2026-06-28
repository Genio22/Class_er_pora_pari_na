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
        printf("[%d]", current->data);
        // printf("[%d|%p]", current->data, current -> next);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }

}

//===========================Array list======================//

typedef struct arraylist
{
    int *list;
    int size;
    int capacity;
} arraylist;

void create_dy_array(arraylist **arr1, int size, int choice)
{
    if (choice == 1)
    {
        *arr1 = (arraylist *)malloc(sizeof(arraylist));
        (*arr1)->list = (int *)malloc(size * sizeof(int));
        (*arr1)->size = 0;
        (*arr1)->capacity = size;
    }
    else
    {
        if ((*arr1)->size < (*arr1)->capacity)
        {
            return;
        }
        size = (*arr1)->capacity + size;
        (*arr1)->list = (int *)realloc((*arr1)->list, size * sizeof(int));
        (*arr1)->capacity = size;
    }
}

void contain(arraylist **arr1)
{
    int count = 0;
    for (int i = (*arr1)->capacity - 1; i >= 0; i--)
    {
        if (-10000 < (*arr1)->list[i] && (*arr1)->list[i] < 100000)
        {
            count++;
        }
    }
    (*arr1)->size = count;
}

void arr_insert_at_beg(int data, arraylist **arr1)
{
    if ((*arr1)->size == (*arr1)->capacity)
    {
        create_dy_array(arr1, 1, 0);
    }
    for (int i = (*arr1)->capacity - 1; i >= 0; i--)
    {
        (*arr1)->list[i] = (*arr1)->list[i - 1];
    }
    (*arr1)->list[0] = data;
    contain(arr1);
}

void arr_insert_at_pos(int data, arraylist **arr1, int pos)
{

    if ((*arr1)->size == (*arr1)->capacity)
    {
        create_dy_array(arr1, 1, 0);
    }
    for (int i = (*arr1)->capacity - 1; i >= pos - 1; i--)
    {
        (*arr1)->list[i] = (*arr1)->list[i - 1];
    }
    (*arr1)->list[pos - 1] = data;
    (*arr1)->size++;
}

void arr_display(arraylist *arr1)
{

    for (int i = 0; i < arr1->size; i++)
    {
        printf(" %d |", arr1->list[i]);
    }
    printf("\n%d", arr1->size);
}

// int main(int argc, char const *argv[])
// {
//     arraylist *arr1 = NULL;

//     create_dy_array(&arr1, 5, 1);

//     arr_insert_at_beg(10, &arr1);
//     arr_insert_at_beg(20, &arr1);
//     arr_insert_at_beg(30, &arr1);
//     arr_insert_at_beg(40, &arr1);
//     arr_insert_at_beg(50, &arr1);

//     arr_display(arr1);

//     printf("\n");
//     arr_insert_at_pos(56, &arr1, 2);
//     arr_display(arr1);

//     return 0;
// }

int main()
{
    node *head = NULL;
    arraylist *arr1 = NULL;

    printf("Start\n");
    insert_at_beginner(10, &head);
    insert_at_beginner(30, &head);
    insert_at_beginner(20, &head);
    insert_at_beginner(50, &head);
    insert_at_beginner(60, &head);
    insert_at_beginner(40, &head);
    display(head);

    printf("\n");
    insert_at_pos(2, 70, &head);
    display(head);

    printf("\n");
    sort(&head);
    display(head);

    printf("\n");
    reverse(&head);
    display(head);

    printf("\n");
    removefirst(&head);
    display(head);

    printf("\n");
    remove_at_any(2, &head);
    display(head);

    printf("\n");
    removelast(&head);
    display(head);

    return 0;
}

// void removelast(node **head){
//     node *current = *head;
//     while (current -> next -> next != NULL)
//     {
//         current = current -> next;
//     }
//     free(current -> next);
//     current -> next = NULL;

// }
