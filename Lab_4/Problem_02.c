/*In this problem, you will develop a program that can find how many times an integer number
can be divided by Two (2).*/
#include <stdio.h>
int main()
{
    int a, num = 0, count = 0;

    printf("Enter a integer: ");
    scanf("%d", &a);
    if (a == 0)
    {
        printf("The number 0 cannot be divided by 2.\n");
    }

    int original = a;
    while ((a % 2) == 0 && a != 0)
    {
        a /= 2;
        count++;
    }
    printf("The number %d can be divided by 2 exactly %d times.", original, count);
    while (getchar() != '\n')
        ;
    return 0;
}

// By sAhAf