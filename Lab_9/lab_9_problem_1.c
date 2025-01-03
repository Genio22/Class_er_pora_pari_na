/* Create a structure called ”Student” with members name, age, and total marks. Write a C program
to input data fortwo students, display theirinformation, and find the average oftotal marks. */
#include <stdio.h>
#include <math.h>
#include <string.h>

struct student
{
    char name[100];
    int age;
    float t_marks;
} s;

// void average(int t_marks){

// }

int main()
{

    int n;
    float sum = 0, average = 0;
    printf("Enter the number of student: ");
    scanf("%d", &n);
    getchar();

    struct student s[n];

    if (n <= 0)
    {
        printf("Invalid number of students. Please enter a positive integer.\n");
        return 1; // Exit the program with an error code
    }

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("Enter details for student: %d\n", i + 1);
        printf("Name: ");
        fgets(s[i].name, 100, stdin);
        printf("Age: ");
        scanf("%d", &s[i].age);
        getchar();
        printf("Total marks: ");
        scanf("%f", &s[i].t_marks);
        getchar();
    }

    for (int i = 0; i < n; i++)
    {
        sum += s[i].t_marks;
    }

    average = sum / n;

    for (int i = 0; i < n; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Name: %s", s[i].name);
        printf("Age: %d\n", s[i].age);
        printf("Total mark: %.2f\n", s[i].t_marks);
    }

    printf("Average performace of the class: %.3f", average);
    // average (s->t_marks);

    return 0;
}

// By sAhAf🙂