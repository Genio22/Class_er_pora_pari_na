/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>


int main() {
    int n, key, i;
    int *ptr;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    ptr = arr;

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", (ptr + i));
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (*(ptr + i) == key) {
            printf("Element found at index %d\n", i);
            return 0;
        }
    }

    printf("Element not found\n");

    return 0;
}



// By sAhAf🙂