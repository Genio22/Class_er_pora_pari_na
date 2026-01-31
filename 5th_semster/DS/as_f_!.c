#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;

} node;

node *head = NULL;



void add(int item)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = item;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void addbegin(int item)
{
    node *newNode = (node *)malloc(sizeof(node));

    newNode->data = item;
    newNode->next = head;

    head = newNode;
}



void addanypos(int pos, int item)
{
    if (pos <= 1)
    {
        addbegin(item);
        return;
    }

    node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = item;

    newNode->next = temp->next;
    temp->next = newNode;
}



bool contains(int item)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == item)
            return true;

        temp = temp->next;
    }

    return false;
}

int size()
{
    int count = 0;
    node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}


bool isEmpty()
{
    return head == NULL;
}

int get(int pos)
{
    if (pos < 1 || pos > size())
    {
        printf("Invalid position\n");
        return -1;
    }

    node *temp = head;
    int count = 1;

    while (count < pos)
    {
        temp = temp->next;
        count++;
    }

    return temp->data;
}

/*
int indexOf(int item){

    node *temp = head;

    int count = 1;

    while(temp!=NULL)
    {
        if(temp->data == item)
        {
            printf("Position of %d is %d\n.",item,count);
            count++;
            temp = temp->next;
        }
    }



}
*/



int indexOf(int item)
{
    node *temp = head;
    int count = 1;

    while (temp != NULL)
    {
        if (temp->data == item)
            return count;

        temp = temp->next;
        count++;
    }

    return -1;
}

/*)
void remove(int pos){

    int count = 1;

    node *temp = head;

    if(head == NULL)
    {
        printf("There is no node to remove.\n");

    }

    if(pos == 1)
    {
        head = head->next;
        free(temp);

    }

    while(count != pos-1 && temp->next!= NULL)
    {
        temp = temp->next;
        count++;
    }

    temp-> next = temp->next->next;
    temp = temp->next;
    free(temp);



}
*/

void removefirst()
{
    if (head == NULL)
        return;

    node *temp = head;

    head = head->next;

    free(temp);
}

void removelast()
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    node *del = temp->next;
    temp->next = NULL;

    free(del);
}


void remove_pos(int pos)
{
    if (pos < 1 || head == NULL)
        return;

    if (pos == 1)
    {
        removefirst();
        return;
    }

    node *temp = head;
    int count = 1;

    while (count < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
        return;

    node *del = temp->next;

    temp->next = del->next;

    free(del);
}

void reverse()
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    head = prev;
}

void sort()
{
    if (head == NULL)
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



void showLL()
{
    node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

// array list

typedef struct
{
    int *data;
    int size;
    int capacity;

} arraylist;


void init(arraylist *list)
{
    list->capacity = 4;      
    list->size = 0;

    list->data = (int *)malloc(sizeof(int) * list->capacity);
}



void resize(arraylist *list)
{
    list->capacity = list->capacity * 2;

    int *newData = (int *)malloc(sizeof(int) * list->capacity);

    for (int i = 0; i < list->size; i++)
        newData[i] = list->data[i];

    free(list->data);

    list->data = newData;
}



void arr_add(int item, arraylist *list)
{
    if (list->size == list->capacity)
        resize(list);

    list->data[list->size] = item;

    list->size++;
}



void arr_addbegin(int item, arraylist *list)
{
    if (list->size == list->capacity)
        resize(list);

    for (int i = list->size; i > 0; i--)
        list->data[i] = list->data[i - 1];

    list->data[0] = item;

    list->size++;
}



void arr_addanypos(int pos, int item, arraylist *list)
{
    if (pos < 0 || pos > list->size)
    {
        printf("Invalid position\n");
        return;
    }

    if (list->size == list->capacity)
        resize(list);

    for (int i = list->size; i > pos; i--)
        list->data[i] = list->data[i - 1];

    list->data[pos] = item;

    list->size++;
}



bool arr_contains(int item, arraylist *list)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == item)
            return true;
    }

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
        return -1;
    }

    return list->data[pos];
}




int arr_indexOf(int item, arraylist *list)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->data[i] == item)
            return i;
    }

    return -1;
}



void arr_removefirst(arraylist *list)
{
    if (list->size == 0)
        return;

    for (int i = 0; i < list->size - 1; i++)
        list->data[i] = list->data[i + 1];

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
        list->data[i] = list->data[i + 1];

    list->size--;
}


void arr_reverse(arraylist *list)
{
    int left = 0;
    int right = list->size - 1;

    while (left < right)
    {
        int temp = list->data[left];
        list->data[left] = list->data[right];
        list->data[right] = temp;

        left++;
        right--;
    }
}



void arr_sort(arraylist *list)
{
    for (int i = 0; i < list->size; i++)
    {
        for (int j = 0; j < list->size - i - 1; j++)
        {
            if (list->data[j] > list->data[j + 1])
            {
                int temp = list->data[j];
                list->data[j] = list->data[j + 1];
                list->data[j + 1] = temp;
            }
        }
    }
}

void arr_display(arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        printf("%d ", list->data[i]);

    printf("\n");
}



void arr_free(arraylist *list)
{
    free(list->data);
}




void main()
{
    arraylist list;

    init(&list);


    printf("ADD BEGIN\n");

    addbegin(10);
    arr_addbegin(10, &list);

    addbegin(20);
    arr_addbegin(20, &list);

    addbegin(30);
    arr_addbegin(30, &list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n ADD END \n");

    add(5);
    arr_add(5, &list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n ADD POSITION \n");

    addanypos(2, 99);
    arr_addanypos(2, 99, &list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n REMOVE FIRST \n");

    removefirst();
    arr_removefirst(&list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n REMOVE LAST \n");

    removelast();
    arr_removelast(&list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n REMOVE POSITION 1 \n");

    remove_pos(1);
    arr_removeat(1, &list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n REVERSE \n");

    reverse();
    arr_reverse(&list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n SORT \n");

    sort();
    arr_sort(&list);

    showLL();
    printf("\n");
    arr_display(&list);



    printf("\n INFO \n");

    printf("Linked size   = %d\n", size());
    printf("Array size    = %d\n", arr_size(&list));

    printf("Linked contains 10 = %d\n", contains(10));
    printf("Array contains 10  = %d\n", arr_contains(10, &list));

    printf("Linked indexOf 10 = %d\n", indexOf(10));
    printf("Array indexOf 10  = %d\n", arr_indexOf(10, &list));


    arr_free(&list);

}
