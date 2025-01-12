/* Write a program that takes a string and a character as input, and removes all occurrences
of that character from the string.
▪ Sample Input:
String: "Hello, World!", Character: "l"
▪ Sample Output:
"Heo, Word!" */
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char letter[100];
    scanf("%[^\n]s", letter);
    getchar();
    char target;
    scanf("%c", &target);
    int len = 0, foundcount = 0;
    while (letter[len] != '\0')
        len++;
    char temp[len];
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if(letter[i] != target){
            temp[j] = letter [i];
            j++;
        }
        
    }
    temp[j] = '\0';
    printf("%s", temp);

    return 0;
}

// By sAhAf🙂