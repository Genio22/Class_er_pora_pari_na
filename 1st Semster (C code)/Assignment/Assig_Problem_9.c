/*
Find the Largest Difference Between Any Two Elements in an Array
Write a program to calculate the maximum absolute difference between any two elements in an
array.
• Input: An array of integers.
• Output: The largest difference (absolute value).
• Logic: Find the minimum and maximum values in the array. The largest difference will be
max − min.
*/
// #include <stdio.h>

// int main()
// {
//     int n;
//     printf("Enter the memory for array: ");
//     scanf("%d", &n);
//     int num_order[n+1];
//     for (int i = 0; i < n+1; i++)
//     {
//         printf("Enter the number %d: ", i);
//         scanf("%d", &num_order[i]);
//     }
//     int max = num_order[0], min = num_order[0];
//     for (int i = 0; i < (n+1); i++)
//     {

//         if (num_order[i] > max)
//         {
//             max = num_order[i];
//         }
//         else if (num_order[i] < min)
//         {
//             min = num_order[i];
//         }
//     }
//     int dif = max - min;
//     printf("Difference between highest and lowest: %d\n", dif);
//     return 0;
// }
#include <stdio.h>

int main()
{
    int n, max, min;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (i == 0)
            max = min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }
    printf("Difference: %d\n", max - min);
    return 0;
}
