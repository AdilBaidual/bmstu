#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

double Position(double x, double y);
int PosForFirstline(double x, double y);
int PosForSecondline(double x, double y);
int PosForThirdline(double x, double y);
void Input(double *x, double *y);

void main() {
    double x, y;
    Input(&x, &y);
    Position(x, y);
    getch();
}

void Input(double *x, double *y) {
    printf("y = 2x + 2\n");
    printf("y = 0.5x - 1\n");
    printf("y = -x + 2\n");
    printf("Please insert coordinates of the point: \n");
    scanf("%lf %lf", x, y);
}

int PosForFirsline(double x, double y) {
    int res;
    double y1;
    y1 = 2*x + 2;
    if (y > y1) res = 1;
    else if (y == y1) res = 0;
    else res = -1;
    return res;
}

int PosForSecondline(double x, double y) {
    int res;
    double y1;
    y1 = 0.5*x - 1;
    if (y > y1) res = 1;
    else if (y == y1) res = 0;
    else res = -1;
    return res;
}

int PosForThirdline(double x, double y) {
    int res;
    double y1;
    y1 = 2 - x;
    if (y > y1) res = 1;
    else if (y == y1) res = 0;
    else res = -1;
    return res;
}

double Position(double x, double y) {
    int pos1, pos2, pos3;
    pos1 = PosForFirsline(x, y);
    pos2 = PosForSecondline(x, y);
    pos3 = PosForThirdline(x, y);
    if(pos1 == -1 && pos2 == 1 && pos3 == 1)printf("area 1");
    else if(pos1 == -1 && pos2 == -1 && pos3 == 1) printf("area 2");
    else if(pos1 == -1 && pos2 == -1 && pos3 == -1) printf("area 3");
    else if(pos1 == 1 && pos2 == -1 && pos3 == -1) printf("area 4");
    else if(pos1 == 1 && pos2 == 1 && pos3 == -1) printf("area 5");
    else if(pos1 == 1 && pos2 == 1 && pos3 == 1) printf("area 6");
    else if(pos1 == -1 && pos2 == 1 && pos3 == -1) printf("area 7");
    else if(pos1 == 0) {
        if(pos2 == 0) printf("line 1 and line 2");
        else if(pos3 == 0) printf("line 1 and line 3");
        else printf("line 1");
    }
    else if(pos2 == 0) {
        if(pos3 == 0) printf("line 2 and line 3");
        else printf("line 2");
    }
    else if(pos3 == 0) printf("line 3");
    else printf("error");
}