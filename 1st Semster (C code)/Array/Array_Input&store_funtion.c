#include <stdio.h>

void array_input_store(int arr, int n)//array size insilation and size of array
{
    int n, num;
    printf("Enter the array: ");
    scanf("%d", &num);
    int arr[n];
    for (int i = n; i >= 0; i--)
    {
        arr[i] = num % 10; // Single digite input
        num /= 10;
        // printf("%d\n", arr[i]); // debuging
    }
    // return arr[lookup]; // give output for any value i want only i have tell the position
}

int main()
{
    int n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int arr[n];
    array_input_store();

    printf("%d\n", arr[2]);
    return 0;
}