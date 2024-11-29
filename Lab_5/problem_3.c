/*Problem 3
Develop a function that takes two integers as parameters and returns the count of numbers that
are divisible by 5 and 7 in that range. Call the function from main and print the result.*/
#include <stdio.h>

int start, end, count = 0;

int divisible_count(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (i % 5 == 0 && i % 7 == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    printf("Enter the upper limit: ");
    scanf("%d\n", &start);
    printf("Enter the lower limit: ");
    scanf("%d\n", &end);
    int final_result = divisible_count(start, end);
    printf("%d", final_result);
    return 0;
}
