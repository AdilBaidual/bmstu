#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

void Input(double *a);
void ArraySize(double *n);
double Array(double *arr, double n);
int FindMax(double *arr, double n);
int FindMin(double *arr, double n);
double Func(double mn, double mx);
void Var0(double *arr, double n);

void main() {
    double arr;
    double n;
    ArraySize(&n);
    Array(&arr, n);
    Var0(&arr, n);
    getch();
}

void Input(double *a) {
    scanf("%lf", a);
}

void ArraySize(double *n) {
    printf("Enter the size of the number of array elements\n");
    Input(n);
}

double Array(double *arr, double n) {
    double *mas = malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        double x;
        Input(&x);
        *(arr + i) = x;
    }
    arr = mas;
}

int FindMax(double *arr, double n) {
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(*(arr + i) > *(arr + mx)) {
            mx = i;
        }
    }
    //printf("%d\n", mx);
    return mx;
}

int FindMin(double *arr, double n) {
    int mn = 0;
    for(int i = 0; i < n; i++) {
        if(*(arr + i) < *(arr + mn)) {
            mn = i;
        }
    }
    printf("%d\n", mn);
    return mn;
}

double Func(double mn, double mx) {
    double f = (mx + mn) / 2;
    return f;
}

void Var0(double *arr, double n) {
    double sum = 0;
    int start = FindMax(arr, n);
    double f = Func(FindMin(arr, n), FindMax(arr, n));
    for(int i = start + 1; i < n; i ++) {
        if(*(arr + i) > f) {
            sum += *(arr + i);
        }
    }
    printf("%lf", sum);
}