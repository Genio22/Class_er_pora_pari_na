/* Write a program to check if a string contains only digits (numeric string).
▪ Sample Input:
"123456"
▪ Sample Output:
The string contains only digits */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char letter[100];
    scanf("%[^\n]s", letter);
    getchar();

    int len = 0, idex = -1;
    while (letter[len] != '\0')
        len++;
    // version with shortcut
    // for (int i = 0; i < len; i++)
    // {
    //     if (!isdigit(letter[i]))
    //     {
    //         idex = 1;
    //         break;
    //     }
    // }
    // if (idex == -1)
    //     printf("The string contains only digits\n");
    // else
    //     printf("The string contains non-digit characters\n");
    // version no shortcut
    for (int i = 0; i < len; i++)
    {
        if (!(45 <= letter[i] && letter[i] <= 57))
        {
            idex = 1;
            break;
        }
    }
    if (idex == -1)
        printf("The string contains only digits\n");
    else
        printf("The string contains non-digit characters\n");
    return 0;
}

// By sAhAf🙂