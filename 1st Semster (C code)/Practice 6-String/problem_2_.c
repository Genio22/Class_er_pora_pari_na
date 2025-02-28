/* Write a program to count the number of vowels and consonants in a string. Ignore any
non-alphabet characters (e.g., spaces, punctuation).
▪ Sample Input:
"Hello World!"
▪ Sample Output:
Vowels: 3, Consonants: 7 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char letter[100];
    scanf("%[^\n]s", letter);
    getchar();
    int len = 0, vowelcount = 0, consonentcount = 0;
    while (letter[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len; i++)
    {
        if (isalpha(letter[i]))
        {
            if (letter[i] == 'a' || letter[i] == 'e' || letter[i] == 'i' || letter[i] == 'o' || letter[i] == 'u')
            {
                vowelcount++;
            }
            else
            {
                consonentcount++;
            }
        }
    }
    printf("Vowel: %d Consonent: %d", vowelcount, consonentcount);

    return 0;
}

// By sAhAf🙂