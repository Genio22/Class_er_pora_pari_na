/* Create a structure named Book to store book details like title, author, and price. Write a C
program to input details for five books, find the most expensive and the lowest priced books, and
display their information. */
#include <stdio.h>
#include <math.h>
#include <string.h>

struct mys {
    char title[100];
    char author[100];
    float price;
} book;

int main()
{
    int n;
    printf("Enter the number of book: ");
    scanf("%d", &n);
    for(int i = 0; i<n ;i++){
        fget(book.title[i], 100, stdin);
    }
    
    for ()
    scanf ("%c", &book.title[0]);
    printf ("%c\n", book.title[0]);
    printf ("%c\n", book.title[1]);
   return 0;
}




// By sAhAf🙂