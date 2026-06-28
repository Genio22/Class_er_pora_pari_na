/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 10, 3, 4, 5, 6, 2, 3, 8};
    int size = sizeof(arr);
    int *seen = (int *)calloc(size, sizeof(int));
    int result = -1;
    for (int i = 0; i < size; i++)
    {
        if (seen[arr[i]] == 1)
        {
            result = arr[i];
            break;
        }
        seen[arr[i]] = 1;
    }

    free(seen);

    if (result != -1)
    {
        printf("First duplicate is: %d\n", result);
    }
    else
    {
        printf("No duplicates found.\n");
    }

    return 0;
}

// By sAhAf🙂