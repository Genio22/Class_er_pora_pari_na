/*Write a C program to count frequency of each element in an array.*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n;

    printf("Enter the memory for array (number of digits): ");
    scanf("%d", &n);

    char num_str[n + 1]; 

    printf("Enter the number for the array: ");
    scanf("%s", num_str);

    int freq[10] = {0}; 

    for (int i = 0; i < strlen(num_str); i++)
    {
        if (num_str[i] >= '0' && num_str[i] <= '9') 
        {
            int digit = num_str[i] - '0'; 
            freq[digit]++;
        }
    }
    // design korar jono lakchilam 🙂
    printf("Digit | Frequency\n");
    printf("-----------------\n");
    for (int i = 0; i < 10; i++)
    {
        if (freq[i] > 0)
        {
            printf("  %d   |    %d\n", i, freq[i]);
        }
    }

    return 0;
}






// By sAhAf🙂