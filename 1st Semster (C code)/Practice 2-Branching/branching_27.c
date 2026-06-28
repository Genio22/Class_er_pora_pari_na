/*Even or Odd (Ternary): Take an integer and use the ternary operator to
print "Even" if it’s even and "Odd" if it’s odd.*/
#include <stdio.h>
void main(){
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    (x>0) ? printf("It is Even") : printf("It is Odd");
}