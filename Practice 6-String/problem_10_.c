/*Write a program to check if a given string contains any spaces, and if so, replace all
spaces with underscores (_).
▪ Sample Input:
"Hello World"
▪ Sample Output:
"Hello_World" */
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Replace spaces with underscores
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }

    // Output the modified string
    printf("Modified string: %s\n", str);

    return 0;
}
