/*Write a C program to count frequency of each element in an array.*/
#include <stdio.h>

void array_input(int num, int num_arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        num_arr[i] = num % 10;  // Extract the last digit
        num /= 10;              // Remove the last digit
    }
}

int main()
{
    int n, num;

    // Input the size of the array (number of digits)
    printf("Enter the number of digits: ");
    scanf("%d", &n);

    // Declare an array to store the digits
    int num_arr[n]; // Array to hold the digits of the number

    // Input the number
    printf("Enter the number: ");
    scanf("%d", &num);

    // Input the digits into the array
    array_input(num, num_arr, n);

    // Frequency array for digits 0-9
    int freq[10] = {0};

    // Count the frequency of each digit in the array
    for (int i = 0; i < n; i++)
    {
        if (num_arr[i] >= 0 && num_arr[i] <= 9)  // Check if the number is a valid digit
        {
            freq[num_arr[i]]++; // Increment the frequency of the corresponding digit
        }
    }

    // Display the frequency of each digit
    printf("Digit | Frequency\n");
    printf("-----------------\n");
    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0) // Print only digits that appear in the input
        {
            printf("  %d   |    %d\n", i, freq[i]);
        }
    }

    return 0;
}
