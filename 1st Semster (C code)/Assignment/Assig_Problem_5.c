/*5. Print All Numbers Divisible by 7 but Not Divisible by 5 Within a Range [a, b]
Input two integers a and b and print all numbers in the range that are divisible by 7 but not divisible
by 5. Use a loop to iterate through the range and apply the conditions.*/
#include <stdio.h>

int main()
{
    int start, end, count = 0;
    printf("Enter the upper limit: ");
    scanf("%d", &start);
    printf("Enter the lower limit: ");
    scanf("%d", &end);
    for (int i = start; i <= end; i++)
    {
        if (i % 5 != 0 && i % 7 == 0)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

// By sAhAf🙂
