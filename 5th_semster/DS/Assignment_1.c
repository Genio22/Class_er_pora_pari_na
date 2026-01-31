#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_node(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

typedef struct
{
    int *arr;
    int size;
    int capacity;
} arraylist;


void init(arraylist *list)
{
    list->capacity = 4;
    list->size = 0;
    list->arr = (int *)malloc(list->capacity * sizeof(int));
}

void addbegin(int data, node **head)
{
    node *newnode = create_node(data);
    newnode->next = *head;
    *head = newnode;
}

void add(int data, node **head)
{
    node *newnode = create_node(data);

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    node *current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = newnode;
}

void addanypos(int pos, int data, node **head)
{
    if (pos <= 0 || *head == NULL)
    {
        addbegin(data, head);
        return;
    }

    node *current = *head;

    for (int i = 0; i < pos - 1 && current->next != NULL; i++)
        current = current->next;

    node *newnode = create_node(data);

    newnode->next = current->next;
    current->next = newnode;
}

int size(node *head)
{
    int count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

bool isEmpty(node *head)
{
    return head == NULL;
}

bool contains(int item, node *head)
{
    while (head)
    {
        if (head->data == item)
            return true;

        head = head->next;
    }

    return false;
}

int get(int pos, node *head)
{
    int i = 0;

    while (head)
    {
        if (i == pos)
            return head->data;

        head = head->next;
        i++;
    }

    return -1;
}

int indexOf(int item, node *head)
{
    int i = 0;

    while (head)
    {
        if (head->data == item)
            return i;

        head = head->next;
        i++;
    }

    return -1;
}

void removefirst(node **head)
{
    if (*head == NULL)
        return;

    node *temp = *head;

    *head = temp->next;

    free(temp);
}

void removelast(node **head)
{
    if (*head == NULL)
        return;

    node *current = *head;

    while (current->next->next != NULL)
        current = current->next;

    free(current->next);
    current->next = NULL;
}

void removeat(int pos, node **head)
{
    if (*head == NULL)
        return;

    if (pos == 0)
    {
        removefirst(head);
        return;
    }

    node *current = *head;

    for (int i = 0; i < pos - 1 && current->next != NULL; i++)
        current = current->next;

    if (current->next == NULL)
        return;

    node *temp = current->next;

    current->next = temp->next;

    free(temp);
}

void reverse(node **head)
{
    node *prev = NULL;
    node *curr = *head;
    node *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

void sort(node *head)
{
    if (!head)
        return;

    node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
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
    node *current = head;

    while (current)
    {
        printf("[%d]", current->data);

        if (current->next)
            printf(" -> ");

        current = current->next;
    }

    printf("\n");
}



void arr_resize(arraylist *list)
{
    list->capacity = list->capacity * 2;

    int *newarr = (int *)malloc(list->capacity * sizeof(int));

    for (int i = 0; i < list->size; i++)
        newarr[i] = list->arr[i];

    free(list->arr);

    list->arr = newarr;
}


void arr_add(int data, arraylist *list)
{
    if (list->size == list->capacity)
        arr_resize(list);

    list->arr[list->size] = data;

    list->size++;
}


void arr_addbegin(int data, arraylist *list)
{
    if (list->size == list->capacity)
        arr_resize(list);

    for (int i = list->size; i > 0; i--)
        list->arr[i] = list->arr[i - 1];

    list->arr[0] = data;

    list->size++;
}


void arr_addanypos(int pos, int data, arraylist *list)
{
    if (pos <= 0)
    {
        arr_addbegin(data, list);
        return;
    }

    if (pos >= list->size)
    {
        arr_add(data, list);
        return;
    }

    if (list->size == list->capacity)
        arr_resize(list);

    for (int i = list->size; i > pos; i--)
        list->arr[i] = list->arr[i - 1];

    list->arr[pos] = data;

    list->size++;
}


bool arr_contains(int item, arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        if (list->arr[i] == item)
            return true;

    return false;
}


int arr_size(arraylist *list)
{
    return list->size;
}


bool arr_isEmpty(arraylist *list)
{
    return list->size == 0;
}


int arr_get(int pos, arraylist *list)
{
    if (pos < 0 || pos >= list->size)
    {
        printf("Invalid position\n");
        exit(1);
    }

    return list->arr[pos];
}


int arr_indexOf(int item, arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        if (list->arr[i] == item)
            return i;

    return -1;
}


void arr_removefirst(arraylist *list)
{
    if (list->size == 0)
        return;

    for (int i = 0; i < list->size - 1; i++)
        list->arr[i] = list->arr[i + 1];

    list->size--;
}


void arr_removelast(arraylist *list)
{
    if (list->size == 0)
        return;

    list->size--;
}


void arr_removeat(int pos, arraylist *list)
{
    if (pos < 0 || pos >= list->size)
        return;

    for (int i = pos; i < list->size - 1; i++)
        list->arr[i] = list->arr[i + 1];

    list->size--;
}


void arr_reverse(arraylist *list)
{
    int left = 0;
    int right = list->size - 1;

    while (left < right)
    {
        int temp = list->arr[left];
        list->arr[left] = list->arr[right];
        list->arr[right] = temp;

        left++;
        right--;
    }
}


void arr_sort(arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        for (int j = i + 1; j < list->size; j++)
            if (list->arr[i] > list->arr[j])
            {
                int temp = list->arr[i];
                list->arr[i] = list->arr[j];
                list->arr[j] = temp;
            }
}


void arr_display(arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        printf("[%d] ", list->arr[i]);

    printf("\n");
}



// int main()
// {
//     node *head = NULL;

//     addbegin(10, &head);
//     addbegin(20, &head);
//     addbegin(30, &head);
//     display(head);

//     add(5, &head);
//     display(head);

//     addanypos(2, 99, &head);
//     display(head);

//     removefirst(&head);
//     display(head);

//     removelast(&head);
//     display(head);

//     removeat(1, &head);
//     display(head);

//     reverse(&head);
//     display(head);

//     sort(head);
//     display(head);

//     printf("Size = %d\n", size(head));
//     printf("Contains 10? %d\n", contains(10, head));
//     printf("Index of 10 = %d\n", indexOf(10, head));

//     return 0;
// }




int main()
{
    node *head = NULL;
    arraylist list;

    init(&list);

    printf("=== ADD BEGIN ===\n");
    addbegin(10, &head);
    arr_addbegin(10, &list);

    addbegin(20, &head);
    arr_addbegin(20, &list);

    addbegin(30, &head);
    arr_addbegin(30, &list);

    display(head);
    arr_display(&list);


    printf("\n=== ADD END ===\n");
    add(5, &head);
    arr_add(5, &list);

    display(head);
    arr_display(&list);


    printf("\n=== ADD ANY POSITION ===\n");
    addanypos(2, 99, &head);
    arr_addanypos(2, 99, &list);

    display(head);
    arr_display(&list);


    printf("\n=== REMOVE FIRST ===\n");
    removefirst(&head);
    arr_removefirst(&list);

    display(head);
    arr_display(&list);


    printf("\n=== REMOVE LAST ===\n");
    removelast(&head);
    arr_removelast(&list);

    display(head);
    arr_display(&list);


    printf("\n=== REMOVE POSITION 1 ===\n");
    removeat(1, &head);
    arr_removeat(1, &list);

    display(head);
    arr_display(&list);


    printf("\n=== REVERSE ===\n");
    reverse(&head);
    arr_reverse(&list);

    display(head);
    arr_display(&list);


    printf("\n=== SORT ===\n");
    sort(head);
    arr_sort(&list);

    display(head);
    arr_display(&list);


    printf("\n=== INFO ===\n");
    printf("Linked size = %d\n", size(head));
    printf("Array size  = %d\n", arr_size(&list));

    printf("Linked contains 10 = %d\n", contains(10, head));
    printf("Array contains 10  = %d\n", arr_contains(10, &list));

    printf("Linked indexOf 10 = %d\n", indexOf(10, head));
    printf("Array indexOf 10  = %d\n", arr_indexOf(10, &list));

    return 0;
}
