#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

void Input(double *E);
double Factorial(double num, double lastfact);
void RowSum(double E);
double RowElement(double n, double lastfact);

void main() {
    double E;
    while(true){
        Input(&E);
        RowSum(E);
        getch();
    }
}

void Input(double *E) {
    printf("enter precision E\n");
    scanf("%lf", E);
}

double Factorial(double n, double lastfact) {
    double fact = lastfact * n;
    return fact;
}

double RowElement(double n, double lastfact) {
    double sn = 1.0 / Factorial(n, lastfact);
    return sn;
}

void RowSum(double E) {
    double S = 1;
    double sa = 1;
    double sb;
    double n = 2;
    while(sa >= E) {
        sa = RowElement(n, 1/sa);
        n += 1;
        S += sa;
        printf("%.15lf %.15lf\n", sa, S);
    }
    printf("%.15lf\n", S);
}