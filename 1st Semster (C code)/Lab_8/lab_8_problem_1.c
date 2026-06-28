/* Problem 1: Palindrome Checker
Write a program that takes a string as input and checks if it is a palindrome. A palindrome reads the
same backward as forward. Ignore case and spaces. */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void remove_space(char *string);
int palindrom_check(char *string);

int main()
{
    int check;
    char string[1000];
    printf("Enter a sentence: ");
    fgets(string,1000,stdin);
    check = palindrom_check(string);
    if (check == 1){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
    // remove_space(string);
    // printf("%s", string);
    return 0;
}


void remove_space(char *string)// it can handle space, tab, newline. why pointer because it whole memory acces is gained by it
{
    int j = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        // if (string[i] != ' ') // without ctype.h libaray
        if (!isspace(string[i]))  // with ctype.h libaray
        {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0';// termination of array
}

int palindrom_check(char *string){
    char original[1000]; //declere original
    remove_space(string);//remove space from string
    strlwr(string);//lower it for comparison
    strcpy(original, string);// then copied the string to sapated array for comparison
    strrev(string);
    if (strcmp(original, string) == 0){
        return 1;
    }
    else{
        return 0;
    }

}


// By sAhAf🙂