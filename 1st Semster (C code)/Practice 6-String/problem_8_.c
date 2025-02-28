/*
Write a program to reverse each word in a sentence while maintaining the word order.
▪ Sample Input:
"Hello World"
▪ Sample Output:
"olleH dlroW"
*/
// by gpt
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];  // Array to hold the input sentence
    char reversedSentence[200];  // Array to store the reversed sentence
    int start = 0, end = 0, k = 0;  // Indices for processing

    // Take input from the user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character if present
    int len = strlen(sentence);
    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
        len--;
    }

    // Loop through the sentence
    for (int i = 0; i <= len; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            // Reverse the current word
            for (int j = i - 1; j >= start; j--) {
                reversedSentence[k++] = sentence[j];
            }
            // Add the space after the word (if not the last word)
            if (sentence[i] == ' ') {
                reversedSentence[k++] = ' ';
            }
            // Update the start of the next word
            start = i + 1;
        }
    }

    // Null-terminate the reversed sentence
    reversedSentence[k] = '\0';

    // Print the reversed sentence
    printf("Reversed sentence: %s\n", reversedSentence);

    return 0;
}


// By sAhAf🙂