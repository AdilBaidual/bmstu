#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <malloc.h>
//VAR 0
void Input(double *a);
void ArraySize(int *n);
int CheckInt(double n);
int Check(double n);
int CheckNULL(double *arr);
double *Array(int n, double *arr);
int FindMax(double *arr, int n);
int FindMin(double *arr, int n);
double Func(int mn, int mx, double *arr);
void Var0(double *arr, int n);

void main() {
    double *arr;
    int n;
    while(1) {
        ArraySize(&n);
        if(Check(n)) {
            arr = Array(n, arr);
            if(CheckNULL(arr)) {
                Var0(arr, n);
            }
            free(arr);
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

int Check(double n) {
    if(n <= 0) {
        printf("Numbers must be greater than zero\n");
        return 0;
    }
    else{

        return 1;
    }
}

int CheckInt(double n) {
    int a = n;
    return a;
}

int CheckNULL(double *arr) {
    if(arr == NULL) {
        return 0;
    }
    return 1;
}

double *Array(int n, double *arr) {
    double x;
    arr = (double *)malloc(n * sizeof(double));
    printf("Enter array values\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", i);
        Input(&x);
        *(arr + i) = x;
    }
    return arr;
}

int FindMax(double *arr, int n) {
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(*(arr + i) > *(arr + mx)) {
            mx = i;
        }
    }
    //printf(" Max: %d\n", mx);
    return mx;
}

int FindMin(double *arr, int n) {
    int mn = 0;
    for(int i = 0; i < n; i++) {
        if(*(arr + i) < *(arr + mn)) {
            mn = i;
        }
    }
    //printf("Min: %d\n", mn);
    return mn;
}

double Func(int mn, int mx, double *arr) {
    double f = (*(arr + mx) + *(arr + mn)) / 2;
    return f;
}

void Var0(double *arr, int n) {
    printf("%lf", (arr + 1));
    double sum = 0;
    int start = FindMax(arr, n);
    double f = Func(FindMin(arr, n), FindMax(arr, n), arr);
    for(int i = start + 1; i < n; i ++) {
        if(*(arr + i) > f) {
            sum += *(arr + i);
        }
    }
    printf("%lf\n", sum);
    
}