/*You will take several integer numbers as inputs until the user enters -1. Then calculate the
difference between the Highest and Lowest number.*/
#include <stdio.h>

int main()
{
    int num = 0, max = -999999, min = 999999;
    printf("Enter an integer: ");
    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        else if (num > max)
        {
            max = num;
        }
        else if (num < min)
        {
            min = num;
        }
    }
    int dif = max - min;
    printf("%d", dif);
    return 0;
}

// By sAhAf