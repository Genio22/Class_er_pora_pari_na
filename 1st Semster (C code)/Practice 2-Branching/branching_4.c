// Eligible for Voting: Take the user’s age as input and print "Eligible to vote" if
// they are 18 or older.

#include <stdio.h>


int main(){
    int age;
    printf ("Enter your age: ");
    scanf ("%d", &age);
    if (age >= 18) {
        printf("Eligible to vote");
    }
    else {
        printf("Not Eligible to vote");
    }
    return 0;
}