#include <stdio.h>
#include <math.h>

float calculateperimeter(float a, float b, float c)
{
    return a + b + c;
}

float calcutaleArea(float a, float b, float c)
{
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
int isValidTriangle(float a, float b, float c)
{
    return ((a + b) > c) && ((a + c) > b) && ((b + c) > a) ? 1 : 0;
}
int main()
{
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    (isValidTriangle(a, b, c) == 1) ? printf("Perimeter: %f \nArea: %f", calculateperimeter(a, b, c), calcutaleArea(a, b, c)) : printf("It is not triangle");
    return 0;
}