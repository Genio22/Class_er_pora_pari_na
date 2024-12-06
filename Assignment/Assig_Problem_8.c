/*
Find the Sum of All Elements in an Array
Write a program to compute the total sum of elements in an array.
• Input: An array of integers.
• Output: The sum of all elements.
• Logic: Use a loop to traverse the array, adding each element to a running total.
*/
#include <stdio.h>

int main()
{
    int n, sum = 0, total_count;
    printf("Enter the memory for array: ");
    scanf("%d", &n);
    int num_order[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number %d: ", i);
        scanf("%d", &num_order[i]);
        sum += num_order[i];
    }
    printf("Sum = %d\n", sum);
    return 0;
}





















// By sAhAf🙂
