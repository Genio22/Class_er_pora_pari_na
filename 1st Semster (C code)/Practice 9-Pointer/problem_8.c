/* Write a program that checks if a given string is URL which starts with "http" or "https" using
pointers. */
#include <stdio.h>
#include <math.h>
#include <string.h>

int idx = -1;

void url_check(char *pa, char *pb)
{
    for (int i = 0; i < 3; i++)
    {
        if (*(pa + i) != *(pb + i))
        {
            idx = 1;
            return;
        }
    }
}

int main()
{
    char a[100];
    scanf("%[^\n]s", a);
    getchar();
    char b[4] = "http";
    url_check(a,b);// array te '&' use kora lage na as perameter
    if (idx == 1)
    {
        printf("It is not url.");
    }
    else
    {
        printf("It is url");
    }
    return 0;
}

// By sAhAf🙂