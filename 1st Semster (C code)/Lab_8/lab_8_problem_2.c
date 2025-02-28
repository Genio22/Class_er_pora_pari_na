/*
Problem 2: Anagram Detector
Write a program to check if two strings are anagrams of each other. Ignore case and spaces.
Example:
Input: "Listen" and "Silent"
Output: "Anagrams"
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void remove_space(char *string);
void bubble_sort(char *string);
void anagram_detector(char *string1, char *string2);

int main()
{
    int check;
    char string1[1000], string2[1000];
    printf("Enter the word: ");
    fgets(string1, 1000, stdin);
    printf("Enter other word: ");
    fgets(string2, 1000, stdin);
    remove_space(string1);
    // printf("%s\n", string1);
    remove_space(string2);
    bubble_sort(string1);
    printf("%s\n", string1);
    bubble_sort(string2);
    printf("%s\n", string2);
    anagram_detector(string1, string2);
    return 0;
}

void anagram_detector(char *string1, char *string2)
{
    strlwr(string1);
    strlwr(string2);
    if (!strcmp(string1, string2))// tepically strcmp return 0 as true but if only expect 0 as false so if not is use the problem get solved
    {
        printf("Anagram.\n");
    }
    else
    {
        printf("Not Anagram.\n");
    }
}

void bubble_sort(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        for (int j = 0; j < (strlen(string) - 1 - i); j++)
        {
            if (string[j] > string[j + 1])
            {
                int temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
}

void remove_space(char *string) // it can handle space, tab, newline. why pointer because it whole memory acces is gained by it
{
    int j = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        // if (string[i] != ' ') // without ctype.h libaray
        if (!isspace(string[i])) // with ctype.h libaray
        {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0'; // termination of array
}

/*
// version 1 without sorting string
void anagram_detector(char *string1, char *string2)
{
    int count = 0;
    strlwr(string1);
    strlwr(string2);
    for (int i = 0; i < strlen(string1); i++)
    {
        for (int j = 0; j < strlen(string2); j++)
        {
            if (string1[i] == string2[j])
            {
                count++;
            }
        }
    }
    if (count == strlen(string1) && count == strlen(string2))
    {
        printf("Anagram.\n");
    }
    else
    {
        printf("Not Anagram.\n");
    }
}
*/

// By sAhAf🙂
