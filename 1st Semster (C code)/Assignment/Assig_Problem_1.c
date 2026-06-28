#include <stdio.h>

int main() {
    char chr;
    printf("Enter a character: ");
    scanf("%c", &chr);
    int ch = (int) chr;

    if (ch>=65 && ch<=90) {
        printf("Lowercase form Of %c -> %c", ch, ch+32);
    }
    else if (ch>=97 && ch<=122) {
        printf("Uppercase form Of %c -> %c", ch, ch-32);
    }
    else {
        printf("Not \n");
    }

    return 0;
}