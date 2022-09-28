#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdint.h>

void Input(double *E);
int Check(double E);
double Abs(double x1, double x2);
double Factorial(double num, double lastfact);
void RowSum(double E);
double RowElement(double n, double lastfact);

void main() {
    double E;
    while(1){
        Input(&E);
        if(Check(E)) {
            RowSum(E);
            printf("Press any button to restart\n");
            getch();
        }
        else {
            continue;
        }
        
    }
}

void Input(double *E) {
    printf("enter precision E\n");
    scanf("%lf", E);
}

int Check(double E) {
    if(E <= 0) {
        printf("Enter a number greater than zero\n");
        return 0;
    }
    return 1;
}

double Abs(double x1, double x2) {
    if(x1 - x2 < 0) {
        return (x1 - x2) * -1;
    }
    else {
        return (x1 - x2);
    }
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
    double sb = 0;
    double n = 2;
    while(Abs(sa, sb) >= E) {
        sb = sa;
        sa = RowElement(n, 1/sa);
        n += 1;
        S += sa;
    }
    printf("%.15lf\n", S);
}