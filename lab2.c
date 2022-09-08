#include <stdio.h>
#include <math.h>
#include <conio.h>

void Cell(float a);

void main() {
    float x1, x2, iter, delt, x;
    printf("range:\n");
    scanf("%f %f", &x1, &x2);
    printf("iterations:\n");
    scanf("%f", &iter);
    delt = (x2 - x1) / (iter - 1);
    printf("%f\n", delt);
    printf("x    |");
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
            Cell(sin(x));
        }
        x += delt;
    }
    getch();
}

void Cell(float a) {
    printf("%-7.3f|", a);
}