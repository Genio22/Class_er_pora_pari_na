#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    int *arr;
    int size;
    int capacity;
} Heap;

void heap_sort_descending(int arr[], int n);

// ================= BASIC =================

Heap *create_heap(int cap)
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

int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ================= MIN HEAP =================

void min_heapify(Heap *h, int i)
{
    int smallest = i;
    int l = left(i);
    int r = right(i);

    if (l < h->size && h->arr[l] < h->arr[smallest])
        smallest = l;

    if (r < h->size && h->arr[r] < h->arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        min_heapify(h, smallest);
    }
}

// O(n) build (fix from your inefficient version)
void build_minheap(Heap *h)
{
    for (int i = (h->size / 2) - 1; i >= 0; i--)
        min_heapify(h, i);
}

// FAST array → heap
void array_to_minheap(Heap *h, int arr[], int n)
{
    for (int i = 0; i < n; i++)
        h->arr[i] = arr[i];

    h->size = n;
    build_minheap(h);
}

void  insert_into_minheap(Heap *h, int val)
{
    if (h->size == h->capacity)
    {
        printf("Overflow\n");
        return;
    }

    int i = h->size++;
    h->arr[i] = val;

    while (i != 0 && h->arr[parent(i)] > h->arr[i])
    {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

int extractmin(Heap *h)
{
    if (h->size <= 0)
        return -1;

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    min_heapify(h, 0);
    return root;
}

// DELETE NODE (fixed properly)
void delete_key(Heap *h, int index)
{
    if (index >= h->size)
        return;

    h->arr[index] = h->arr[h->size - 1];
    h->size--;

    int i = index;

    // move up / up fix
    while (i != 0 && h->arr[parent(i)] > h->arr[i])
    {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }

    // move down / down fix
    min_heapify(h, i);
}

// ================= MAX HEAP =================

void max_heapify(Heap *h, int i)
{
    int largest = i;
    int l = left(i);
    int r = right(i);

    if (l < h->size && h->arr[l] > h->arr[largest])
        largest = l;

    if (r < h->size && h->arr[r] > h->arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&h->arr[i], &h->arr[largest]);
        max_heapify(h, largest);
    }
}

void insert_into_maxheap(Heap *h, int val)
{
    if (h->size == h->capacity)
        return;

    int i = h->size++;
    h->arr[i] = val;

    while (i != 0 && h->arr[parent(i)] < h->arr[i])
    {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
}

int extractmax(Heap *h)
{
    if (h->size <= 0)
        return -1;

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    max_heapify(h, 0);
    return root;
}

// ================= TASK 3 =================
// K-th largest

int kth_largest(int arr[], int n, int k){
    heap_sort_descending(arr,n);
    return arr[k-1];
}

// ================= TASK 4 =================
// Heap Sort

void heap_sort_ascending(int arr[], int n)
{
    Heap *h = create_heap(n);
    array_to_minheap(h, arr, n);

    for (int i = 0; i < n; i++)
        arr[i] = extractmin(h);
}

void heap_sort_descending(int arr[], int n)
{
    Heap *h = create_heap(n);

    for (int i = 0; i < n; i++)
        insert_into_maxheap(h, arr[i]);

    for (int i = 0; i < n; i++)
        arr[i] = extractmax(h);
}

// ================= TASK 5 =================
// Sliding Window Max Sum

int max_subarray_sum(int arr[], int n, int k)
{
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    int max_sum = sum;

    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        if (sum > max_sum)
            max_sum = sum;
    }

    return max_sum;
}

// ================= PRINT =================

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// ================= MAIN =================

int main()
{
    int arr[] = {45, 5, 15, 2, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // -------- Min Heap --------
    Heap *h = create_heap(20);
    array_to_minheap(h, arr, n);

    printf("Min Heap:\n");
    print_array(h->arr, h->size);

    // -------- Delete --------
    delete_key(h, 2);
    printf("After delete index 2:\n");
    print_array(h->arr, h->size);

    // -------- Kth Largest --------
    int k = 3;
    printf("Kth largest: %d\n", kth_largest(arr, n, k));

    // -------- Heap Sort --------
    int arr1[] = {45, 5, 15, 2, 4, 3};
    heap_sort_ascending(arr1, n);
    printf("Ascending:\n");
    print_array(arr1, n);

    int arr2[] = {45, 5, 15, 2, 4, 3};
    heap_sort_descending(arr2, n);
    printf("Descending:\n");
    print_array(arr2, n);

    // -------- Sliding Window --------
    int k2 = 3;
    printf("Max subarray sum (k=3): %d\n", max_subarray_sum(arr, n, k2));

    return 0;
}