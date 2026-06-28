#include <stdio.h>

int a, b, c;

int main() {

    printf ("Enter a: ");
    scanf ("%d", &a); 
    
    printf ("Enter b: ");
    scanf ("%d", &b);
    
    printf ("Enter c: ");
    scanf ("%d", &c);

    if (((a+b) > c) || ((a+c) > b) ||  ((b+c)> a)) {
        if (a == b && b == c && a == c) {
            printf("It is Equilateral a triangle.");
        }
        else if (a == b || b == c || a == c) {
            printf("It is Isosceles a triangle.");
        }
        else{
            printf("It is Scalene a triangle.");
        }
    }
    else{
        printf("It is not a triangle.");
    }

    
    return 0;
}