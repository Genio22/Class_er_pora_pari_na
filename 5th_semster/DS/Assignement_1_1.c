#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


void resize(arraylist *list)
{
    list->capacity = list->capacity * 2;

    int *newarr = (int *)malloc(list->capacity * sizeof(int));

    for (int i = 0; i < list->size; i++)
        newarr[i] = list->arr[i];

    free(list->arr);

    list->arr = newarr;
}


void add(int data, arraylist *list)
{
    if (list->size == list->capacity)
        resize(list);

    list->arr[list->size] = data;

    list->size++;
}


void addbegin(int data, arraylist *list)
{
    if (list->size == list->capacity)
        resize(list);

    for (int i = list->size; i > 0; i--)
        list->arr[i] = list->arr[i - 1];

    list->arr[0] = data;

    list->size++;
}


void addanypos(int pos, int data, arraylist *list)
{
    if (pos <= 0)
    {
        addbegin(data, list);
        return;
    }

    if (pos >= list->size)
    {
        add(data, list);
        return;
    }

    if (list->size == list->capacity)
        resize(list);

    for (int i = list->size; i > pos; i--)
        list->arr[i] = list->arr[i - 1];

    list->arr[pos] = data;

    list->size++;
}


bool contains(int item, arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        if (list->arr[i] == item)
            return true;

    return false;
}


int size(arraylist *list)
{
    return list->size;
}


bool isEmpty(arraylist *list)
{
    return list->size == 0;
}


int get(int pos, arraylist *list)
{
    if (pos < 0 || pos >= list->size)
    {
        printf("Invalid position\n");
        exit(1);
    }

    return list->arr[pos];
}


int indexOf(int item, arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        if (list->arr[i] == item)
            return i;

    return -1;
}


void removefirst(arraylist *list)
{
    if (list->size == 0)
        return;

    for (int i = 0; i < list->size - 1; i++)
        list->arr[i] = list->arr[i + 1];

    list->size--;
}


void removelast(arraylist *list)
{
    if (list->size == 0)
        return;

    list->size--;
}


void removeat(int pos, arraylist *list)
{
    if (pos < 0 || pos >= list->size)
        return;

    for (int i = pos; i < list->size - 1; i++)
        list->arr[i] = list->arr[i + 1];

    list->size--;
}


void reverse(arraylist *list)
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


void sort(arraylist *list)
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


void display(arraylist *list)
{
    for (int i = 0; i < list->size; i++)
        printf("[%d] ", list->arr[i]);

    printf("\n");
}
