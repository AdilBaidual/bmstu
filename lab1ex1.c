#include <stdio.h>
#include <conio.h>

void Position(double x, double y);
void Input(double *x, double *y);

void main() {
    double x, y;
    Input(&x, &y);
    Position(x, y);
    getch();
    system("pause");
}

void Input(double *x, double *y) {
    printf("Line equation: y = 0.5x + 1\n");
    printf("Please insert coordinates of the point: \n");
    scanf("%lf %lf", x, y);
}

void Position(double x, double y) {
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