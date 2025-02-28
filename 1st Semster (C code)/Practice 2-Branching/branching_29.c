/*Minimum of Three Numbers: Take three integers and use nested ternary
operators to print the smallest of the three.*/
#include <stdio.h>
void main(){
    int x, y, z;
    printf("Enter number x: ");
    scanf("%d", &x);
    printf("Enter number y: ");
    scanf("%d", &y);
    printf("Enter number z: ");
    scanf("%d", &z);
    // (x>y) ? ((y>z)? printf("%d <- It is smallest", z) : printf("%d <- It is smallest", y)) : ((x>z) ? printf("%d <- It is smallest", z): printf("%d <- It is smallest", x));
    (x<y) ?  
        ((x<z) ? printf("%d <- It is smallest", x) : printf("%d <- It is smallest", z)):
        ((y<z) ? printf("%d <- It is smallest", y) : printf("%d <- It is smallest", z)); 
}