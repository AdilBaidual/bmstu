#include <stdio.h>
#include <math.h>
#include <conio.h>

void Cell(double a);

void main() {
    double x1, x2, iter, delt, x;
    printf("range:\n");
    scanf("%lf %lf", &x1, &x2);
    printf("iterations:\n");
    scanf("%lf", &iter);
    delt = (x2 - x1) / (iter - 1);
    printf("%lf\n", delt);
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

void Cell(double a) {
    printf("%-7.3lf|", a);
}