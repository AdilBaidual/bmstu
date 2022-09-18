#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

void Input(double *E, double *a, double *b);
double LeftRectangleMethod(double N, double x, double h);
void RowSum(double E, double a, double b);
double RowElement(double i, double x, double h);
double Abs(double x1, double x2);

void main() {
    double E, a, b;
    while(true){
        Input(&E, &a, &b);
        RowSum(E, a, b);
        getch();
    }
}

void Input(double *E, double *a, double *b) {
    printf("enter precision E\n");
    scanf("%lf", E);
    printf("enter a and b\n");
    scanf("%lf %lf", a, b);
}

double LeftRectangleMethod(double N, double x, double h) {
    double S = 0;
    for(int i = 1; i <= N; i++) {
        S += RowElement(i, x, h);
        x += h;
    }
    return S;
}

double RowElement(double i, double x, double h) {
    double sn = h * log(x-h);
    return sn;
}

double Abs(double x1, double x2) {
    if(x1 - x2 < 0) {
        return (x1 - x2) * -1;
    }
    else {
        return (x1 - x2);
    }
}

void RowSum(double E, double a, double b) {
    double sa = LeftRectangleMethod(1, b, (b-a));
    double sb = LeftRectangleMethod(2, a + (b-a)/2, (b-a)/2);
    printf("%lf %lf\n", sa, sb);
    double S;
    double N = 3;
    double h = (b - a)/N;
    double x = a + h;
    while(Abs(sa, sb)>= E) {
        printf("in");
        sa = sb;
        sb = LeftRectangleMethod(N, x, h);
        N *= 2;
        h = (b - a)/N;
        x = a + h;
    }
    printf("%.15lf\n", sb);
}