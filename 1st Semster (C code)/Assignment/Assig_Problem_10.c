/*
Print the Number of Distinct Elements in an Array Already Sorted in Ascending Order
Problem:
Given a sorted array of integers, count and print the number of distinct elements in the array.
• Input: A sorted array of integers, e.g., [1, 1, 2, 2, 3, 4, 4, 5].
• Output: The number of distinct elements, e.g., 5 (elements: 1, 2, 3, 4, 5).
*/
#include <stdio.h>

// Function to count distinct elements in a sorted array
int countDistinct(int arr[], int n) {
    int count = 1; // First element is always distinct
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int distinctCount = countDistinct(arr, n);
    printf("Number of distinct elements: %d\n", distinctCount);

    return 0;
}
