#include <stdio.h>
#include <conio.h>



double Position(double x, double y);
double Input(double *x, double *y);

void main() {
    double x, y;
    printf("Line equation: y = 0.5x + 1\n");
    Input(&x, &y);
    Position(x, y);
    getch();
}

double Input(double *x, double *y) {
    printf("Please insert coordinates of the point: \n");
    scanf("%lf %lf", x, y);
}

double Position(double x, double y) {
    double y1;
    y1 = 0.5 * x + 1;
    if (y > y1) {
        printf("Point is below line");
    }
    else if (y == y1) {
        printf("Point is on the line");
    }
    else{
        printf("Point is above line");
    }
}