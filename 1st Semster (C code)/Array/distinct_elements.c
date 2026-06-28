/**
 * Program to count distinct elements in a sorted array
 */
#include <stdio.h>

int countDistinct(int arr[], int size) {
    if(size == 0) return 0;
    
    int count = 1; // First element is always distinct
    
    for(int i = 1; i < size; i++) {
        if(arr[i] != arr[i-1]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter %d elements in sorted order:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int distinct = countDistinct(arr, size);
    printf("Number of distinct elements: %d\n", distinct);
    
    return 0;
}