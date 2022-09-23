#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

bool Check(double x1, double x2, int iter);
double Delta(double x1, double x2, int iter);
void Start(double x1, double x2, int iter);
void Input(double *x1, double *x2, int *iter);
void Cell(double a);
void FirstTable(double x1, double x2, int iter);
void SecondTable(double x1, double x2, int iter);
void ThirdTable(double x1, double x2, int iter);
void Restart();

void main() {
    while(true) {
        double x1, x2;
        int iter;
        Input(&x1, &x2, &iter);
        if(Check(x1, x2, iter)) {
            Start(x1, x2, iter);
            Restart();
        }
        else {
            continue;
        }
    }
}

void Start(double x1, double x2, int iter) {
    if(x1 < x2) {
        FirstTable(x1, x2, iter);
        SecondTable(x1, x2, iter);
        ThirdTable(x1, x2, iter);
    }
    else {
        FirstTable(x2, x1, iter);
        SecondTable(x2, x1, iter);
        ThirdTable(x2, x1, iter);
    }
}

void Restart() {
    printf("\nPress any button to start again\n");
    getch();
}

bool Check(double x1, double x2, int iter) {
    if(x1 < 0 || x2 < 0) {
        printf("Enter numbers(x1, x2) greater than or equal to zero\n");
        return false;
    }
    else if(iter <= 0) {
        printf("Enter the number of iterations greater than zero\n");
        return false;
    }
    else if(iter == 1 && x1 != x2) {
        printf("Numbers cannot be different in one iteration\n");
        return false;
    }
    else if(iter > 1 && x1 == x2) {
        printf("The left and right bounds cannot be the same for a large number of iterations\n");
        return false;
    }
    else {
        if(x1 > x2) {
            int x = x1;
            x1 = x2;
            x2 = x;
        }
        return true;
    }
}

void Input(double *x1, double *x2, int *iter) {
    printf("range:\n");
    scanf("%lf %lf", x1, x2);
    printf("iterations:\n");
    scanf("%d", iter);

}

void Cell(double a) {
    printf("%-7.3lf|", a);
}

double Delta(double x1, double x2, int iter) {
    double delt;
    delt = (x2 - x1) / (iter - 1);
    if(delt == 0 || iter == 1) {
        delt = 1;
    }
    printf("\n%g\n", delt);
    return delt;
}

void FirstTable(double x1, double x2, int iter) {
    double delt, x, f;
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
            f = tan(x) * sqrt(x);
            if(isnan(f)) {
                printf("Error  |");
            }
            else {
                Cell(f);
            }
        }
        x += delt;
    }
}

void SecondTable(double x1, double x2, int iter) {
    double delt, x, i, f;
    delt = Delta(x1, x2, iter);
    printf("while:\nx    |");
    x = x1;
    while(x < x2 + delt - 0.0000001) {
        Cell(x);
        x += delt;
    }
    printf("\nf(x) |");
    x = x1;
    while(x < x2 + delt - 0.0000001) {
        f = tan(x) * sqrt(x);
        if(isnan(f)) {
            printf("Error  |");
        }
        else {
            Cell(f);
        }
        x += delt;
    }
}

void ThirdTable(double x1, double x2, int iter) {
    double delt, x, i, f;
    delt = Delta(x1, x2, iter);
    printf("do while:\nx    |");
    x = x1;
    do{
        Cell(x);
        x += delt;
    }while(x < x2 + delt - 0.0000001);
    printf("\nf(x) |");
    x = x1;
    do{
        f = tan(x) * sqrt(x);
        if(isnan(f)) {
            printf("Error  |");
        }
        else {
            Cell(f);
        }
        x += delt;
    }while(x < x2 + delt - 0.0000001);
}