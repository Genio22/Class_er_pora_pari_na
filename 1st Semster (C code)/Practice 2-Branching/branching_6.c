/*Number Sign Checker: Take an integer as input and print "Positive" if it’s
greater than zero, otherwise print "Non-positive."*/ 
#include <stdio.h>

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x>0) {
        printf("Positive\n");
    }
    else if (x!=0 && x<0) {
        printf("Negative\n");
    }
    else {
        printf("Zero\n");
    }
    return 0;
}
