/* Write a program to sort an array of integers in ascending order using pointer manipulation. */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int a[] = {5, 2, 8, 4, 1};
    int *pa = &a[0];
    int size = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(pa + j) > *(pa + j + 1))
            {
                int temp = *(pa + j);
                *(pa + j) = *(pa + j + 1);
                *(pa + j + 1) = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(pa + i));
    }

    return 0;
}

// By sAhAf🙂