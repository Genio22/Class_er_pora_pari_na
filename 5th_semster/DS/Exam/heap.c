#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int *arr;
    int size;
    int capacity;
} Heap;

Heap *create_minheap(int cap)
{
    if (cap > 0)
    {
        Heap *h = (Heap *)malloc(sizeof(Heap));
        h->size = 0;
        h->capacity = cap;
        h->arr = (int *)malloc(cap * sizeof(int));
        return h;
    }
    return NULL;
}

int parent(int i)
{
    return (i - 1) / 2;
}

int left(int i)
{
    return (2 * i) + 1;
}

int right(int i)
{
    return (2 * i) + 2;
}

void swap(int *start, int *end)
{
    int temp = *start;
    *start = *end;
    *end = temp;
}

void min_heapify(Heap *h, int i)
{
    int smallest, leftc, rightc;
    smallest = i;
    leftc = left(i);
    rightc = right(i);

    if (leftc < h->size && h->arr[leftc] < h->arr[smallest])
    {
        smallest = leftc;
    }
    if (rightc < h->size && h->arr[rightc] < h->arr[smallest])
    {
        smallest = rightc;
    }
    if (smallest != i)
    {
        swap(&h->arr[smallest], &h->arr[i]);
        min_heapify(h, smallest);
    }
}

void build_minheap(Heap *h)
{
    for (int i = (h->size / 2) - 1; i >= 0; i--)
    {
        min_heapify(h, i);
    }
}

int extractmin(Heap *h)
{
    if (h->size <= 0)
    {
        printf("Heap underflow\n");
        return -1;
    }
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    min_heapify(h, 0);
    return root;
}

void insert_into_minheap(Heap *h, int value)
{
    if (h->size == h->capacity)
    {
        printf("Overflow");
        return;
    }
    h->size++;
    int i = h->size - 1;
    h->arr[i] = value;
    while (i != 0 && h->arr[(i - 1) / 2] > h->arr[i])
    {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void array_to_minheap(Heap *h, int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        insert_into_minheap(h, arr[i]);
        i++;
    }
}

// Max heap

void max_heapify(Heap *h, int i)
{
    int largest, leftc, rightc;
    largest = i;
    leftc = left(i);
    rightc = right(i);

    if (leftc < h->size && h->arr[leftc] > h->arr[largest])
    {
        largest = leftc;
    }

    if (rightc < h->size && h->arr[rightc] > h->arr[largest])
    {
        largest = rightc;
    }

    if (largest != i)
    {
        swap(&h->arr[i], &h->arr[largest]);
        max_heapify(h, largest);
    }
}

void insert_into_maxheap(Heap *h, int value)
{

    if (h->size == h->capacity)
    {
        printf("Overflow");
        return;
    }

    h->size++;
    int i = h->size - 1;
    h->arr[i] = value;

    while (i != 0 && h->arr[(i - 1) / 2] < h->arr[i])
    {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractmax(Heap *h)
{
    if (h->size <= 0)
    {
        printf("Heap underflow\n");
        return -1;
    }
    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    max_heapify(h, 0);
    return root;
}

void print_heap(Heap *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ->", h->arr[i]);
    }
}

void array_to_maxheap(Heap *h, int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        insert_into_maxheap(h, arr[i]);
        i++;
    }
}

void rearreng_asn(Heap *h, int arr[])
{
    int n = h->size;
    for (int i = 0; i < n; i++)
    {
        arr[i] = extractmin(h);
    }
}

int main()
{

    Heap *h = create_minheap(10);

    int arr[] = {45, 5, 15, 2, 4, 3};

    array_to_minheap(h, arr, sizeof(arr) / sizeof(arr[0]));

    print_heap(h);

    int rearr[h->size];
    rearreng_asn(h, rearr);

    printf("\n");
    print_heap(h);

    return 0;
}