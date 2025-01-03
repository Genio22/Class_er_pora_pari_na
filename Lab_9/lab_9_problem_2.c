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
        printf("Book %s title: ", book.title);
        fget(book.title, 100, stdin);
        printf("Book %s author: ", book.author);
        fget(book.author, 100, stdin);
        printf("Book %d price: ", price);
        scanf("%f", &book.price);
    }
    
    printf ("%s\n", book.title);
    printf ("%s\n", book.author);
   return 0;
}

/*#include <stdio.h>
#include <string.h>

struct mys {
    char title[100];
    char author[100];
    float price;
};

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    getchar();  // To consume the newline character after entering the number

    // Array of books to store n books
    struct mys books[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details for book %d\n", i + 1);
        
        // Read the title of the book
        printf("Book %d title: ", i + 1);
        fgets(books[i].title, sizeof(books[i].title), stdin);
        // Remove the newline character added by fgets
        books[i].title[strcspn(books[i].title, "\n")] = 0;

        // Read the author of the book
        printf("Book %d author: ", i + 1);
        fgets(books[i].author, sizeof(books[i].author), stdin);
        // Remove the newline character added by fgets
        books[i].author[strcspn(books[i].author, "\n")] = 0;

        // Read the price of the book
        printf("Book %d price: ", i + 1);
        scanf("%f", &books[i].price);
        getchar();  // To consume the newline character after entering the price
    }

    // Print all books' details
    for (int i = 0; i < n; i++) {
        printf("\nBook %d details:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Price: %.2f\n", books[i].price);
    }

    return 0;
}
*/




// By sAhAf🙂