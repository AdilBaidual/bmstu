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
    //printf("factorial %lf ", fact);
    return fact;
}

double RowElement(double n, double lastfact) {
    double sn = 1.0 / Factorial(n, lastfact);
    return sn;
}

void RowSum(double E) {
    double S = 1;
    double s_new = 1;
    double s_old;
    double n = 2;
    do {
        s_old = s_new;
        s_new = RowElement(n, 1/s_old);
        n += 1;
        S += s_new;
        printf("%lf %lf\n", s_old, s_new);
        //getch();
    }while(Abs(S, S - s_old) >= E);
    printf("%.15lf", S);
}
//1.718281525573193 - старая
//1.718281828459046 - новая