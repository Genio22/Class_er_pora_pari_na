/*
Absolute Value: Take an integer as input and use the ternary operator to
print its absolute value.
*/ 
#include <stdio.h>
void main(){
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    (x>0) ? printf("It is absulote") : printf("It is not absulote");
}