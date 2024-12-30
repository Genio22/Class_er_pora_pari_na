// 2.
#include <stdio.h>
#include <string.h>

void removeSpaces(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void sortString(char *str) {
    int i, j;
    char temp;
    int n = strlen(str);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    strlwr(str1);
    strlwr(str2);

    removeSpaces(str1);
    removeSpaces(str2);

    sortString(str1);
    sortString(str2);

    if (strcmp(str1, str2) == 0) {
        printf("Anagrams\n");
    } else {
        printf("Not Anagrams\n");
    }

    return 0;
}

// 3.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removePunctuation(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i]) || str[i] == ' ') {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main() {
    char str[200];
    int letters = 0, vowels = 0, consonants = 0, words = 0;
    printf("Enter a string: ");
    gets(str);

    strlwr(str);
    removePunctuation(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            letters++;
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    char *token = strtok(str, " ");
    while (token != NULL) {
        words++;
        token = strtok(NULL, " ");
    }

    printf("Words: %d\n", words);
    printf("Letters: %d\n", letters);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}


// 4.
#include <stdio.h>
#include <string.h>

int main() {
    char str[200], target[100];
    printf("Enter the main string: ");
    gets(str);
    printf("Enter the substring to search for: ");
    gets(target);

    char *position = strstr(str, target);
    if (position != NULL) {
        int index = position - str;
        printf("\"%s\" starts at index %d\n", target, index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
