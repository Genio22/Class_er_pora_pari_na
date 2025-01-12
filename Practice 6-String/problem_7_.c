/* Write a program to find the longest word in a sentence.
▪ Sample Input:
"I am learning C programming"
▪ Sample Output:
"programming" */
// by gpt
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];  // Array to hold the input sentence
    char longestWord[200];  // Array to store the longest word
    int maxLength = 0;  // Length of the longest word
    int currentLength = 0;  // Length of the current word
    int start = 0;  // Start index of the current word

    // Take input from the user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline character if present
    int len = strlen(sentence);
    if (sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
        len--;
    }

    // Iterate through each character of the sentence
    for (int i = 0; i <= len; i++) {
        // Check for space or null character which indicates the end of a word
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            // If the current word's length is greater than the longest word length
            if (currentLength > maxLength) {
                maxLength = currentLength;
                // Copy the current word to the longestWord array
                int j = 0;
                for (int k = start; k < i; k++) {
                    longestWord[j++] = sentence[k];
                }
                longestWord[j] = '\0';  // Null terminate the longest word
            }
            // Reset current word length and update start to the next word
            currentLength = 0;
            start = i + 1;
        } else {
            // If it's a character of a word, increase current length
            currentLength++;
        }
    }

    // Output the longest word
    printf("Longest word: %s\n", longestWord);

    return 0;
}


// By sAhAf🙂