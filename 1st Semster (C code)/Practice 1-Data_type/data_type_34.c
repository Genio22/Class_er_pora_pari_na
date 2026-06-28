/*.Date Converter: Given a date in the format YYYYMMDD, print it as "Year:
YYYY, Month: MM, Day: DD".*/
#include <stdio.h>

int main() {
    int data;
    scanf("%d",&data);
    int year = data / 10000;
    int Month = (data%10000)/100;
    int day = data % 100;
    printf ("Years: %d, Month: %d, Date: %d",year,Month,day);
    return 0;
}