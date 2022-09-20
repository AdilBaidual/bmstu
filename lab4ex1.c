#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

void Input(double *a);
void ArraySize(int *n);
bool Check(int n);
double Array(double *arr, int n);
int FindMax(double *arr, int n);
int FindMin(double *arr, int n);
double Func(double mn, double mx);
void Var0(double *arr, int n);

void main() {
    double arr;
    int n;
    while(true) {
        ArraySize(&n);
        if(Check(n)) {
            Array(&arr, n);
            Var0(&arr, n);
            getch();
        }
        else {
            continue;
        }
    }
}

void Input(double *a) {
    scanf("%lf", a);
}

void ArraySize(int *n) {
    printf("Enter the size of the number of array elements\n");
    scanf("%d", n);
}

bool Check(int n) {
    if(n <= 0) {
        printf("Numbers must be greater than zero\n");
        return false;
    }
    else{
        return true;
    }
}

double Array(double *arr, int n) {
    double *mas = malloc(n * sizeof(double));
    double x;
    printf("Enter array values\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", i);
        Input(&x);
        *(arr + i) = x;
    }
    arr = mas;
}

int FindMax(double *arr, int n) {
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(*(arr + i) > *(arr + mx)) {
            mx = i;
        }
    }
    printf(" Max: %d\n", mx);
    return mx;
}

int FindMin(double *arr, int n) {
    int mn = 0;
    for(int i = 0; i < n; i++) {
        if(*(arr + i) < *(arr + mn)) {
            mn = i;
        }
    }
    printf("Min: %d\n", mn);
    return mn;
}

double Func(double mn, double mx) {
    double f = (mx + mn) / 2;
    return f;
}

void Var0(double *arr, int n) {
    double sum = 0;
    int start = FindMax(arr, n);
    double f = Func(FindMin(arr, n), FindMax(arr, n));
    for(int i = start + 1; i < n; i ++) {
        if(*(arr + i) > f) {
            sum += *(arr + i);
        }
    }
    printf("%lf\n", sum);
}