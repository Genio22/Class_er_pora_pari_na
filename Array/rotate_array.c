/**
 * Program to rotate array left by k positions
 */
#include <stdio.h>

void reverseArray(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateLeft(int arr[], int size, int k) {
    k = k % size; // Handle cases where k > size
    
    // Reverse first k elements
    reverseArray(arr, 0, k-1);
    // Reverse remaining elements
    reverseArray(arr, k, size-1);
    // Reverse entire array
    reverseArray(arr, 0, size-1);
}

int main() {
    int size, k;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter number of positions to rotate left: ");
    scanf("%d", &k);
    
    printf("Original array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    rotateLeft(arr, size, k);
    
    printf("\nRotated array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}