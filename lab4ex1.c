#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

void Input(double *a);
void ArraySize(double *n);
void Array(double *arr, double n);

void main() {
    double *arr;
    double n;
    ArraySize(&n);
    Array(arr, n);
    printf("%lf", arr);
    getch();
}

void Input(double *a) {
    scanf("%lf", a);
}

void ArraySize(double *n) {
    printf("Enter the size of the number of array elements\n");
    Input(n);
}

void Array(double *arr, double n) {
    arr = malloc(n * sizeof(double));
    for(int i = 0; i < n; i++) {
        double x;
        Input(&x);
        *(arr + i) = x;
    }
    for(int i = 0; i < n; i++) {
        printf("%lf\n", *(arr + i));
    }
}