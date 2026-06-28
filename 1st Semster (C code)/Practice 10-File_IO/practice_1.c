/*  */
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char name[20];
    int class;
    int roll;
} student;

student s;

int main()
{
    FILE *f1;
    f1 = fopen("text.txt", "a");
    int n;
    printf("Name: ");
    scanf("%[^\n]s", s.name);
    printf("Class: ");
    scanf("%d", &s.class);
    printf("Roll: ");
    scanf("%d", &s.roll);

    fwrite(&s, sizeof(s), 1, f1);

    // fprintf(f1, "Name: %s\t", s.name);
    // fprintf(f1, "Class: %d\t", s.class);
    // fprintf(f1, "Roll: %d\n", s.roll);

    // fputs(s.name, f1);
    // fputs(s.class, f1);
    // fputs(s.roll, f1);
    // fwrite(f1, "%d", &n);
    // printf("%d\n", n);

    // fscanf(f1, "%d", &n);
    // printf("%d\n", n);

    // fscanf(f1, "%d", &n);
    // printf("%d\n", n);

    // fscanf(f1, "%d", &n);
    // printf("%d", n);
    fclose(f1);
    return 0;
}

// By sAhAf🙂