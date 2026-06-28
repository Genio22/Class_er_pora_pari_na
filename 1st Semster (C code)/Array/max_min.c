/**
 * Program to find maximum and minimum elements in an array
 */
#include <stdio.h>

void findMaxMin(int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    
    for(int i = 1; i < size; i++) {
        if(arr[i] > *max) {
            *max = arr[i];
        }
        if(arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int max, min;
    findMaxMin(arr, size, &max, &min);
    
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    
    return 0;
}