/* 
Problem 3: Word, letter, vowel, consonant Counter
Write a program to count the total words, letters, vowels and consonants in a given string. Ignore case
and punctuation marks.
Example:
Input: "Hello world! Hello everyone."
Output:
Word: 4
Vowel: 9
Consonant: 14
Letter: 23 */

/* Version - 2 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void count_all(char *string, int *vowel, int *consonent, int *letter);
void count_word(char *string, int *word);

int main()
{
    int check;
    char string[1000000];
    printf("Enter a sentence: ");
    fgets(string, 1000000, stdin);
    int vowel = 0, consonent = 0, letter = 0, word = 0;
    count_all(string, &vowel, &consonent, &letter);
    count_word(string, &word);
    printf("word: %d\n", word);
    printf("Vowel: %d\n", vowel);
    printf("Consonent: %d\n", consonent);
    printf("Letter: %d\n", letter);
    return 0;
}

void count_all(char *string, int *vowel, int *consonent, int *letter) // using pointer help to update info in memory across functions
{
    *vowel = 0, *consonent = 0, *letter = 0;
    strlwr(string);
    for (int i = 0; i < strlen(string); i++)
    {
        if (isalpha(string[i]) != 0)
        {
            (*letter)++;
            if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            {
                (*vowel)++;
            }
            else
            {
                (*consonent)++;
            }
        }
    }
}

void count_word(char *string, int *word)
{
    *word = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (isspace(string[i]))
        {
            (*word)++;
        }
    }
}

// By sAhAf🙂
/*
version - 1

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_vowel(char *string);
int count_consonent(char *string);
int count_all(char *string);

int main()
{
    int check;
    char string[1000];
    printf("Enter a sentence: ");
    fgets(string, 1000, stdin);
    int vowel, consonent, letter;
    vowel = count_vowel(string);
    consonent = count_consonent(string);
    letter = count_all(string);
    printf("Vowel: %d\n", vowel);
    printf("Consonent: %d\n", consonent);
    printf("Letter: %d\n", letter);
    return 0;
}

int count_vowel(char *string)
{
    int vowel = 0, consonent = 0, letter = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (isalpha(string[i]) != 0)
        {
            if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
            {
                vowel++;
            }
        }
    }
    return vowel;
}

int count_consonent(char *string)
{
    int consonent = 0, letter = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (isalpha(string[i]) != 0)
        {
            if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u')
            {
                consonent++;
            }
        }
    }
    return consonent;
}

int count_letter(char *string)
{
    int letter = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (isalpha(string[i]) != 0)
        {
            letter++;
        }
    }
    return letter;
}

//  By sAhAf🙂
*/