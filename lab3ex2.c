#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

void Input(double *E, double *a, double *b);
int Check(double a, double b, double E);
double LeftRectangleMethod(double N, double x, double h);
void RowSum(double E, double a, double b);
double RowElement(double i, double x, double h);
double rE(double E);
double Abs(double x1, double x2);

void main() {
    double E, a, b;
    while(1){
        Input(&E, &a, &b);
        if(Check(a, b, E)) {
            RowSum(E, a, b);
            getch();
        }
        else {
            continue;
        }
    }
}

void Input(double *E, double *a, double *b) {
    printf("enter precision E\n");
    scanf("%lf", E);
    printf("enter a and b\n");
    scanf("%lf %lf", a, b);
}

int Check(double a, double b, double E) {
    if(E <= 0 || a <= 0 || b <= 0) {
        printf("Numbers must be greater than zero\n");
        return 0;
    }
    return 1;
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

double rE(double E) {
    double i = 1;
    while(E > i) {
        i *= 10;
    }
    return E / i;
}

void RowSum(double E, double a, double b) {
    double flag = 0;
    if(a > b) {
        double a1 = a;
        flag = 1;
        a = b;
        b = a1;
        E = rE(E);
    }
    double sa = LeftRectangleMethod(1, b, (b-a));
    double sb = LeftRectangleMethod(2, a + (b-a)/2, (b-a)/2);
    double S;
    double N = 4;
    double h = 4;
    double x = a + h;
    while(Abs(sa, sb)>= E) {
        sa = sb;
        sb = LeftRectangleMethod(N, x, h);
        N *= 2;
        h = (b - a)/N;
        x = a + h;
    }
    if(flag == 1) {
        printf(" %.15lf\n", (sb*-1));
    }
    else {
        printf(" %.15lf\n", sb);
    }
}