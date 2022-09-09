#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
//ЗАЩИТА ОТ ДУРАКА

bool Check(double x1, double x2, double iter);
void Input(double *x1, double *x2, double *iter);
void Cell(double a);
double Delta(double x1, double x2, double iter);
void FirstTable(double x1, double x2, double iter);
void SecondTable(double x1, double x2, double iter);
void ThirdTable(double x1, double x2, double iter);


void main() {
    while(true) {
        double x1, x2, iter, x;
        Input(&x1, &x2, &iter);
        if(Check(x1, x2, iter)) {
            FirstTable(x1, x2, iter);
            SecondTable(x1, x2, iter);
            ThirdTable(x1, x2, iter);
            getch();
        }
        else {
            continue;
        }
    }
}

bool Check(double x1, double x2, double iter) {
    if(x1 < 0 || x2 < 0 || iter <= 0) {
        printf("Error, try again!\n");
        return false;
    }
    else return true;
}

void Input(double *x1, double *x2, double *iter) {
    printf("range:\n");
    scanf("%lf %lf", x1, x2);
    printf("iterations:\n");
    scanf("%lf", iter);

}

void Cell(double a) {
    printf("%-7.3g|", a);
}

double Delta(double x1, double x2, double iter) {
    double delt;
    delt = (x2 - x1) / (iter - 1);
    printf("\n%g\n", delt);
    return delt;
}

void FirstTable(double x1, double x2, double iter) {
    double delt, x;
    delt = Delta(x1, x2, iter);
    printf("for:\nx    |");
    x = x1;
    for(int i = 1; i < iter * 2 + 1; i++) {
        if(i <= iter) {
            Cell(x);
            if(i == iter) {
                printf("\nf(x) |");
                x = x1 - delt;
            }
        }
        else {
            Cell(tan(x) * sqrt(x));
        }
        x += delt;
    }
}

void SecondTable(double x1, double x2, double iter) {
    double delt, x, i;
    delt = Delta(x1, x2, iter);
    printf("while:\nx    |");
    x = x1;
    i = 1;
    while(i <= iter * 2) {
        if(i <= iter) {
            Cell(x);
            if(i == iter) {
                printf("\nf(x) |");
                x = x1 - delt;
            }
        }
        else {
            Cell(tan(x) * sqrt(x));
        }
        x += delt;
        i += 1;
    }
}

void ThirdTable(double x1, double x2, double iter) {
    double delt, x, i;
    delt = Delta(x1, x2, iter);
    printf("do while:\nx    |");
    x = x1;
    i = 1;
    do {
        if(i <= iter) {
            Cell(x);
            if(i == iter) {
                printf("\nf(x) |");
                x = x1 - delt;
            }
        }
        else {
            Cell(tan(x) * sqrt(x));
        }
        x += delt;
        i += 1;
    } while(i <= iter * 2);
}