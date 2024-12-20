/**
 * Program to find largest difference between any two elements
 */
#include <stdio.h>

int findLargestDifference(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];
    
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    
    return max - min;
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
    
    int diff = findLargestDifference(arr, size);
    printf("Largest difference between elements: %d\n", diff);
    
    return 0;
}