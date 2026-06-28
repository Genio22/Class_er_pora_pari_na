/*Investment Growth: Given an initial investment, annual interest rate, and
number of years, calculate the future investment value using the formul*/
// FV (Future Value -> future investment value)
// PV (Present Value -> initial investment):
// rate (Annual Interest Rate):
// years (number of years):
#include <stdio.h>
#include <math.h>

void main(){
    double fv, pv, rate, years;
    printf("Enter the Present Value (PV): ");
    scanf("%lf", &pv);
    printf("Enter the Annual Interest Rate (Rate): ");
    scanf("%lf", &rate);
    printf("Enter the Number of Years: ");
    scanf("%lf", &years);
    fv = pv *(pow((1+(rate/100)),years));
    printf("Future Value = %.2lf", fv);


}