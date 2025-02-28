/*Problem 4
Write a function that takes the radius of a circle and returns the area of that circle. Write another
function that takes area as parameter and determines whether the area is greater than 25 or not. If
the area is greater than 25 then print ”Greater than 25” or else “Less than 25”. Call both functions
from the main.*/
#include <stdio.h>

int radius, area;

int area_calculate(int radius)
{
    area = 3.1214 * radius * radius;
    return area;
}

void gre_les(int area)
{
    if (area >= 25)
    {
        printf("Greater than 25");
    }
    else
    {
        printf("Less than 25");
    }
}

int main()
{
    printf("Enter the radius of a circle: ");
    scanf("%d", &radius);
    int f_area = area_calculate(radius);
    gre_les(f_area);
    return 0;
}


// By sAhAf🙂