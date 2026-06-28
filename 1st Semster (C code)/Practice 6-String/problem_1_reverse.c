/* Write a program to input a string and print it in reverse order without using any built-in
functions.
▪ Sample Input:
"Hello"
▪ Sample Output:
"olleH" */
#include <stdio.h>
#include <math.h>
#include <string.h>



int main()
{
    int n, le;
    // scanf("%d", &n);
    // getchar();
    char st[100];
    scanf("%[^\n]s", st);
    getchar();
    le = strlen(st);
    st[le] = '\0';
    char tmp[le];
    tmp[le] = '\0';
    for (int i = 0; i < strlen(st); i++)
    {
        tmp[i] = st[le-1];
        le--;
    }
    
    printf("%s", tmp);
    

   return 0;
}




// By sAhAf🙂