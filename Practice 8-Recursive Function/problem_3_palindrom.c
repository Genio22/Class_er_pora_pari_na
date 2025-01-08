/* comment */
#include <stdio.h>
#include <math.h>
#include <string.h>

int ispalindrom(char s[], int start, int end){
    if (start >= end){
        return 1;
    }
    else if (s[start] != s[end]){
        return 0;
    }
    return ispalindrom(s, start+1, end-1);
}

int main()
{
    int check, len;
    char s[100];
    scanf("%[^\n]s", s);
    getchar();
    len = strlen(s);
    check = ispalindrom(s, 0, len-1);
    if (check ==1){
        printf("Palindrom");
    }
    else{
        printf("Not Palindrom");
    }

   return 0;
}




// By sAhAf🙂