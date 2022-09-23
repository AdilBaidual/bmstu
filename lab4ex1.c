#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <malloc.h>
//VAR 0
void Input(double *a);
void ArraySize(double *n);
int CheckInt(double n);
bool Check(double n);
double *Array(int n);
int FindMax(double *arr, int n);
int FindMin(double *arr, int n);
double Func(int mn, int mx, double *arr);
void Var0(double *arr, int n);

void main() {
    double *arr;
    double n;
    while(true) {
        ArraySize(&n);
        if(Check(n)) {
            n = CheckInt(n);
            arr = Array(n);
            for(int i = 0; i < n; i++) {
                printf("%lf\n", *(arr + i));
            }   
            Var0(arr, n);
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

void ArraySize(double *n) {
    printf("Enter the size of the number of array elements\n");
    scanf("%lf", n);
}

bool Check(double n) {
    if(n <= 0) {
        printf("Numbers must be greater than zero\n");
        return false;
    }
    else{

        return true;
    }
}

int CheckInt(double n) {
    int a = n;
    return a;
}

double *Array(int n) {
    double x;
    double *mas = malloc(n * sizeof(double));
    printf("Enter array values\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", i);
        Input(&x);
        *(mas + i) = x;
    }
    return mas;
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

double Func(int mn, int mx, double *arr) {
    double f = (*(arr + mx) + *(arr + mn)) / 2;
    return f;
}

void Var0(double *arr, int n) {
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