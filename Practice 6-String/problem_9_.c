/*
Write a program to find the frequency of each word in a string and print the result. Ignore
case and punctuation marks.
▪ Sample Input:
"Hello world! hello everyone."
▪ Sample Output:
hello: 2, world: 1, everyone: 1
*/
// by gpt
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

int main() {
    char sentence[200], word[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int frequencies[MAX_WORDS] = {0};
    int wordCount = 0;

    // Input the sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character if present
    int len = strlen(sentence);
    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    // Convert to lowercase and replace punctuation with spaces
    for (int i = 0; i < len; i++) {
        if (!isalnum(sentence[i])) {
            sentence[i] = ' ';
        } else {
            sentence[i] = tolower(sentence[i]);
        }
    }

    // Extract words and count their frequencies
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        // Check if the word already exists in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                frequencies[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add the new word to the array
        if (!found) {
            strcpy(words[wordCount], token);
            frequencies[wordCount] = 1;
            wordCount++;
        }

        // Get the next word
        token = strtok(NULL, " ");
    }

    // Print the words and their frequencies
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    return 0;
}
