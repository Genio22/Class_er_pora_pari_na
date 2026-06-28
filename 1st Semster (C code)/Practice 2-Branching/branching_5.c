/*Check Uppercase Letter: Take a character as input and print "Uppercase" if
the character is an uppercase letter.
*/
#include <stdio.h>
#include <ctype.h>  // For isupper()

int main() {
    char ch;

    // Prompt user to enter a character
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Check if the character is an uppercase letter
    // if (isupper(ch)) {
    //     printf("Uppercase\n");
    // } else {
    //     printf("Not an Uppercase letter\n");
    // }
    if (ch>=65 && ch<=90) {
        printf("uppercase\n");
    }
    else if (ch>=97 && ch<=122) {
        printf("lowercase\n");
    }
    else {
        printf("Not \n");
    }

    return 0;
}
