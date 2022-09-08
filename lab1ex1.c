#include <stdio.h>
#include <conio.h>



float Position(float x, float y);
float Input(float *x, float *y);

void main() {
    float x, y;
    printf("Line equation: y = 0.5x + 1\n");
    Input(&x, &y);
    Position(x, y);
    getch();
}

float Input(float *x, float *y) {
    printf("Please insert coordinates of the point: \n");
    scanf("%f %f", x, y);
}

float Position(float x, float y) {
    float y1;
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