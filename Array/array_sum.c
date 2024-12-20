/**
 * Program to find sum of all elements in an array
 */
#include <stdio.h>

int arraySum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
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
    
    int sum = arraySum(arr, size);
    printf("Sum of all elements: %d\n", sum);
    
    return 0;
}