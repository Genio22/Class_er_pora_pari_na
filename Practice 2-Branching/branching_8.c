/*Pass/Fail: Take a student's score as input. If the score is 50 or more, print
"Pass"; otherwise, print "Fail."*/
#include <stdio.h>

int main() {
    int x;
    
    printf("Enter your score: ");
    scanf("%d", &x);

    if (x>50) {
        printf("Pass\n");
    }
    else {
        printf("Fail\n");
    }
    return 0;
}