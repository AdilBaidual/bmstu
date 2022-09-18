#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

void Position(double x, double y);
int PosForline(double y, double y1);
int Area(int pos1, int pos2, int pos3);
int Crossing(int pos1, int pos2, int pos3);
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

int PosForline(double y, double y1) {
    int res;
    if (y == y1)
        res = 0;
    else if (y > y1)
        res = 1;
    else
        res = -1;
    return res;
}

int Area(int pos1, int pos2, int pos3) {
    if(pos1 == -1 && pos2 == 1 && pos3 == 1)printf("area 1");
    else if(pos1 == -1 && pos2 == -1 && pos3 == 1) printf("area 2");
    else if(pos1 == -1 && pos2 == -1 && pos3 == -1) printf("area 3");
    else if(pos1 == 1 && pos2 == -1 && pos3 == -1) printf("area 4");
    else if(pos1 == 1 && pos2 == 1 && pos3 == -1) printf("area 5");
    else if(pos1 == 1 && pos2 == 1 && pos3 == 1) printf("area 6");
    else if(pos1 == -1 && pos2 == 1 && pos3 == -1) printf("area 7");
    else return 1;
    return 0;
}

int Crossing(int pos1, int pos2, int pos3) {
    if(pos1 == 0) {
        if(pos2 == 0) printf("line 1 and line 2");
        else if(pos3 == 0) printf("line 1 and line 3");
        else printf("line 1");
    }
    else if(pos2 == 0) {
        if(pos3 == 0)
         printf("line 2 and line 3");
        else
         printf("line 2");
    }
    else if(pos3 == 0)
     printf("line 3");
    else return 1;
    return 0;
}

void Position(double x, double y) {
    int pos1, pos2, pos3;
    pos1 = PosForline(y, 2*x + 2);
    pos2 = PosForline(y, 0.5*x - 1);
    pos3 = PosForline(y, 2 - x);
    if(Area(pos1, pos2, pos3) == 1) {
        if(Crossing(pos1, pos2, pos3) == 1){
            printf("Error");
        }
    }
}
