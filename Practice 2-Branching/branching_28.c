/*Larger of Two Numbers: Take two integers and use the ternary operator to
print the larger one.*/
#include <stdio.h>
void main(){
    int x, y;
    printf("Enter number x: ");
    scanf("%d", &x);
    printf("Enter number y: ");
    scanf("%d", &y);
    (x>y) ? printf("%d <- It is largest.", x) : printf("%d <- It is Largest", y);
}