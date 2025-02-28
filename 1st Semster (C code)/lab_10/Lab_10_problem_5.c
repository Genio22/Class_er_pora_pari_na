/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>


int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr = arr;

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", (ptr + i));
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    return 0;
}





// By sAhAf🙂