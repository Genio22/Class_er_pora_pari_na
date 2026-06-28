#include <stdio.h>
#include <stdlib.h>

int num, n;
int arr[1000];

// Function to input the array and populate it with the digits of 'num'
void array_input()
{
    int temp_num = num;
    n = 0;  // Initialize n to count the digits
    while (temp_num > 0)
    {
        arr[n] = temp_num % 10;
        temp_num /= 10;
        n++;
    }
}

// Function to sort the array
void sort_array()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search Function
int Binary_sort(int target)
{
    int first = 0, last = n - 1;

    while (first <= last)
    {
        int mid_value = (first + last) / 2;
        if (target == arr[mid_value])
        {
            return mid_value;
        }
        else if (target > arr[mid_value])
        {
            first = mid_value + 1;
        }
        else
        {
            last = mid_value - 1;
        }
    }
    return -1;
}

int main()
{
    int target;
    
    // Input
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the target number: ");
    scanf("%d", &target);

    // Convert the number into an array of digits
    array_input();

    // Sort the array before performing binary search
    sort_array();

    // Perform binary search
    int check = Binary_sort(target);
    // printf("%d", check);
    if (check == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Target %d found at array location %d position.\n", target, check);
    }

    return 0;
}
