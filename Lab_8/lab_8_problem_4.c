/*
Problem 4: Substring Search
Write a program that searches for a substring in a string and prints its starting index.
Example:
Input:
• String: "the quick brown fox jumps over the lazy dog"
• Target: "brown"
Output: "brown starts at index 10"
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char string[10000], target[100];
    int count = 1;
    int x = 0;
    printf("Enter the string: ");
    fgets(string, 10000, stdin);
    printf("Enter the target: ");
    fgets(target, 10000, stdin);
    for (int i = 0; i < strlen(target); i++)
    {
        for (int j = 0; j < strlen(string); j++)
        {
            if (target[i] == string[j])
            {
                while (x == 0)
                {
                    i++;
                    j++;
                    if (target[i] == string[j])
                    {
                        count++;
                        if (count == strlen(target))
                        {
                            printf("found");
                            x = 1;
                        }
                    }
                    else
                    {
                        printf("Not found %s, \n %s", target[i], string[j]);
                        x = 1;
                    }
                }
            }
        }
    }
    return 0;
}

// By sAhAf🙂