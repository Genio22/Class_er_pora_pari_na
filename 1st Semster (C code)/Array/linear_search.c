/**
 * Program to perform linear search in an array
 */
#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size, key;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    int result = linearSearch(arr, size, key);
    if(result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in array\n");
    }
    
    return 0;
}