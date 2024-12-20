/**
 * Program to check if array is sorted in ascending order
 */
#include <stdio.h>

int isSorted(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
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
    
    if(isSorted(arr, size)) {
        printf("Array is sorted in ascending order\n");
    } else {
        printf("Array is not sorted in ascending order\n");
    }
    
    return 0;
}