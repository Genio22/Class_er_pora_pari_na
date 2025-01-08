// Check Vowel: Take a single character as input and use an if statement to
// check if it’s a vowel (a/A, e/E, i/I, o/O, u/U).
#include <stdio.h>
#include <stdbool.h>

int main(){
    char x;
    scanf("%c", &x);
    bool y = (x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O'|| x == 'u' || x == 'U');
    // printf ("%d", y);
    if (y == 1) {
        printf ("It is vowel");
    } 
    else {
        printf ("It is consonent");
    }
    return 0;
}