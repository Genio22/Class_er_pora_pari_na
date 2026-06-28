#include <stdio.h>

int main()
{
    int x, y;
    printf("Number a: ");
    scanf("%d", &x);
    printf("Number b: ");
    scanf("%d", &y);
    printf("Below a = %d <> b = %d", x, y);
    x = x + y;
    y = x - y;
    x = x - y;
    printf("After a = %d <> b = %d", x, y);
    return 0;
}