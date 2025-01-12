/* Write a program to find the first occurrence of a character in a string and print its
position.
▪ Sample Input:
String: "Hello World", Character: "o"
▪ Sample Output:
First occurrence of 'o' is at position 4 */
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
    int len = 0, found = 0;
    while (letter[len] != '\0')
        len++;
    
    for (int i = len-1; i >= 0 ; i--)
    {
        if(letter[i] == target){
            found = i;
        }
    }
    printf("First occurrence of '%c' is at position %d", target, found);

    return 0;
}

// By sAhAf🙂