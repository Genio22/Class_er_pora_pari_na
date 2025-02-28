/*5. Write a program to swap two integers using pointers. */
#include <stdio.h>
#include <math.h>
#include <string.h>

void swap(int *p, int *q){
    int *temp = p;
    p = q;
    q = temp;
}


int main()
{
    int *a, *b;
    int c, d;
    printf("a = ");
    scanf("%d", &c);
    printf("b = ");
    scanf("%d", &d);
    a = &d;
    b = &c;
    swap(a,b);
    printf("\n\na = %d\n", *a);
    printf("b = %d", *b);
    return 0;
}

// By sAhAf🙂