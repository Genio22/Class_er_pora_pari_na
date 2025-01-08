/*Grade Status: Take a student's score as input and use the ternary operator
to print "Pass" if it’s 50 or above, and "Fail" otherwise.*/

#include <stdio.h>
void main(){
    int x;
    printf("Enter your score: ");
    scanf("%d", &x);
    (x>=50) ? printf("Pass") : printf("Fail");
}