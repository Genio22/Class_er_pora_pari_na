/* Write a program to find the frequency of a specific character in a given string.
▪ Sample Input:
String: "Hello, how are you?", Character: "o"
▪ Sample Output:
Character 'o' appears 3 times */
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
    
    for (int i = 0; i < len; i++)
    {
        if(letter[i] == target){
            foundcount++;
        }
    }
    printf("Character '%c' appears %d times", target, foundcount);

    return 0;
}




// By sAhAf🙂