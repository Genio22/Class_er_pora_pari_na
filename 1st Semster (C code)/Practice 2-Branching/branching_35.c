/*Exam Result Summary: Take marks in three subjects as input:
o If all marks are 50 or above, print "Pass."
o If any mark is below 50, print "Fail.*/
#include <stdio.h>

void main(){
    int x,y,z;
    printf("Enter math score: ");
    scanf("%d", &x);
    printf("Enter physics score: ");
    scanf("%d", &y);
    printf("Enter Chemistry score: ");
    scanf("%d", &z);
    // this is ternaty operator
    // (x>=50 && y>=50 && z>=50) ? printf("pass"):printf("Fail");
    
    // we can also use (if and else) like the following example 
    // scanf("%d %d %d",&x,&y,&z);
    if (x>=50 && y>=50 && z>=50){
        printf("pass");
    }
    else{
        printf("Fail");
    }
}