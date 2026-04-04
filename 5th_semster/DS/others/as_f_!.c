#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *arr = NULL;
int arrsize = 0;

void additem(int item)
{

    if (arr == NULL)
    {
        arr = (int *)calloc(1, sizeof(int));
        arr[0] = item;
        arrsize++;
        return;
    }

    arrsize++;
    arr = (int *)realloc(arr, arrsize * sizeof(int));
    arr[arrsize - 1] = item;
}

void addbegin(int item)
{

    if (arr == NULL)
    {
        arr = (int *)calloc(1, sizeof(int));
        arr[0] = item;
        arrsize++;
        return;
    }

    arrsize++;
    arr = (int *)realloc(arr, arrsize * sizeof(int));

    int temp = arrsize - 1;

    while (temp > 0)
    {

        arr[temp] = arr[temp - 1];
        temp--;
    }

    arr[0] = item;
}

void addanypos(int pos, int item)
{

    if (arr == NULL)
    {
        arr = (int *)calloc(1, sizeof(int));
        arr[0] = item;
        arrsize++;
        return;
    }

    arrsize++;
    arr = (int *)realloc(arr, arrsize * sizeof(int));

    int temp = arrsize - 1;

    while (temp > pos - 1)
    {

        arr[temp] = arr[temp - 1];
        temp--;
    }

    arr[pos - 1] = item;
}

bool contains(int item)
{

    if (arr == NULL)
    {
        printf("There is no element in the array.");
        return false;
    }

    for (int i = 0; i < arrsize; i++)
    {
        if (item == arr[i])
        {
            return true;
        }
    }

    return false;
}

int size()
{

    if (arr == NULL)
    {
        printf("There is no element in the array.");
        return 0;
    }

    return arrsize;
}

bool isEmpty()
{
    if (arr)
    {
        return false;
    }

    return true;
}

int get(int pos)
{

    if (arr == NULL)
    {
        printf("There is element in the array");
        return 0;
    }

    else if ((pos - 1) > size)
    {
        printf("Position does not exist.");
        return 0;
    }

    return arr[pos - 1];
}

/*
int indexOf(int item){

}
*/

void removefirst()
{

    if (arr == NULL)
    {
        printf("No elements to remove.\n");
        return;
    }

    int temp = 0;

    while (temp < arrsize - 1)
    {

        arr[temp] = arr[temp + 1];
        temp++;
    }

    arr[arrsize - 1] = NULL;

    arrsize--;
    arr = (int *)realloc(arr, arrsize * sizeof(int));
}

void removelast()
{

    if (arr == NULL)
    {
        printf("No elements to remove.\n");
        return;
    }

    arr[arrsize - 1] = NULL;

    arrsize--;
    arr = (int *)realloc(arr, arrsize * sizeof(int));
}

void removepos(int pos)
{

    if (arr == NULL)
    {
        printf("No elements to remove.\n");
        return;
    }

    int temp = pos - 1;

    while (temp < arrsize - 1)
    {

        arr[temp] = arr[temp + 1];
        temp++;
    }

    arr[arrsize - 1] = NULL;

    arrsize--;
    arr = (int *)realloc(arr, arrsize * sizeof(int));
}

void reverse()
{

    if (arr == NULL)
    {
        printf("No elements to reverse.\n");
        return;
    }

    else if (arrsize % 2 == 0)
    {
        for (int i = 0; i <= arrsize / 2 - 1; i++)
        {
            arr[i] = arr[i] + arr[arrsize - 1 - i];
            arr[arrsize - 1 - i] = arr[i] - arr[arrsize - 1 - i];
            arr[i] = arr[i] - arr[arrsize - 1 - i];
        }
    }

    else
    {
        for (int i = 0; i < arrsize / 2; i++)
        {
            arr[i] = arr[i] + arr[arrsize - 1 - i];
            arr[arrsize - 1 - i] = arr[i] - arr[arrsize - 1 - i];
            arr[i] = arr[i] - arr[arrsize - 1 - i];
        }
    }
}

void sort()
{

    for (int i = 0; i < arrsize; i++)
    {
        for (int j = i + 1; j < arrsize; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
}

void display()
{

    int i;

    for (i = 0; i < arrsize; i++)
    {
        printf("%d    ", arr[i]);
    }
}

void main()
{

    /*
    if(isEmpty())
    {
        printf("The array is empty.\n");
    }
    */

    additem(1);
    additem(2);
    additem(3);

    addbegin(4);
    addbegin(5);
    addbegin(6);
    addbegin(7);
    addbegin(8);

    addanypos(4, 9);

    /*
    if(contains(100))
    {
        printf("Found!!!\n");
    }
    */

    // printf("Array size is %d\n",size());

    /*
    if(isEmpty())
    {
        printf("The array is empty.\n");
    }
    */

    // printf("%d\n",get(4));

    display();

    // removefirst();

    // removelast();

    // removepos(4);

    reverse();

    printf("\n");

    display();

    sort();

    printf("\n");

    display();
}