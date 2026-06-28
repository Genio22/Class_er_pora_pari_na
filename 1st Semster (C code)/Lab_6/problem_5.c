/*Write a C program to search an element in an array using binary search algorithm.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // sorted in increasing order
    int i;
    int n;
    printf("Enter the memory for array: ");
    scanf("%d", &n);
    int num_order[n];
    int target;
    printf("Target number: ");
    scanf("%d", &target);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the number %d: ", i);
        scanf("%d", &num_order[i]);
    }
    int idx = -1;
    int first = 0;
    int last = n - 1;
    int mid = (first + last) / 2;
    while (last >= first)
    {
        if (num_order[mid] == target)
        {
            idx = mid;
            break;
        }
        else if (num_order[mid] > target)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }
    if (idx == -1)
        printf("Target not found.\n\n");
    else
        printf("Target found at index: %d \n\n", idx);
}





// By sAhAf🙂