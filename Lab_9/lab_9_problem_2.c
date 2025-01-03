/* Create a structure named Book to store book details like title, author, and price. Write a C
program to input details for five books, find the most expensive and the lowest priced books, and
display their information. */
#include <stdio.h>
#include <math.h>
#include <string.h>

struct mys
{
    char title[100];
    char author[100];
    float price;
} book;

int main()
{
    int n;
    printf("Enter the number of book: ");
    scanf("%d", &n);
    getchar();
    struct mys book[n];


    // Input
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for book %d\n", i + 1);
        printf("Title: ");
        fgets(book[i].title, 100, stdin);
        // scanf("%s",&book[i].title);
        printf("Author: ");
        fgets(book[i].author, 100, stdin);
        // scanf("%s",&book[i].author);
        printf("Price: ");
        scanf("%f", &book[i].price);
        getchar();
    }

    float most_expensive = book[0].price, lowest_priced = book[0].price;
    int expensive = 0, lowest = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (book[i].price > most_expensive){
            most_expensive = book[i].price;
            expensive = i;
        }
        else if (book[i].price < lowest_priced){
            lowest_priced = book[i].price;
            lowest = i;
        }
    }
    
    printf("Most expensive Book\n");
        printf("Title: %s", book[expensive].title);
        printf("Author: %s", book[expensive].author);
        printf("Price: %.2f\n", most_expensive);

    
    printf("Lowest priced Book\n");
        printf("Title: %s", book[lowest].title);
        printf("Author: %s", book[lowest].author);
        printf("Price: %.2f\n", lowest_priced);

    // Output
    /*
    for (int i = 0; i < n; i++)
    {
        printf("Book %d\n", i+1);
        printf("Title: %s", book[i].title);
        printf("Author: %s", book[i].author);
        printf("Price: %.2f\n", book[i].price);
    }*/
    return 0;
}


// By sAhAf🙂