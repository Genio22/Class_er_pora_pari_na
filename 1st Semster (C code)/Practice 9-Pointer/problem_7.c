/* Write a program that checks if two strings are identical using pointers. */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char a[] = "hello";
    char b[] = "hellow";
    char *pa, *pb;
    pa = &a[0];
    pb = &b[0];
    int idx = -1;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        if (*(pa++) != *(pb++))
        {
            idx = 1;
            break;
        }
    }

    if (idx == 1)
    {
        printf("It is not identical.");
    }
    else
    {
        printf("It is identical");
    }
    return 0;
}

// By sAhAf🙂