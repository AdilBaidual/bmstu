#include <stdio.h>
#include <conio.h>
#include <stdbool.h>


float Position(float x, float y);
int PosForFirstline(float x, float y);
int PosForSecondline(float x, float y);
int PosForThirdline(float x, float y);

void main() {
    float x, y;
    printf("y = 2x + 2\n");
    printf("y = 0.5x - 1\n");
    printf("y = -x + 2\n");
    printf("Please insert coordinates of the point: \n");
    scanf("%f %f", &x, &y);
    Position(x, y);
    getch();
}

int PosForFirsline(float x, float y) {
    int res;
    float y1;
    y1 = 2*x + 2;
    if (y > y1) res = 1;
    else if (y == y1) res = 0;
    else res = -1;
    return res;
}

int PosForSecondline(float x, float y) {
    int res;
    float y1;
    y1 = 0.5*x - 1;
    if (y > y1) res = 1;
    else if (y == y1) res = 0;
    else res = -1;
    return res;
}

int PosForThirdline(float x, float y) {
    int res;
    float y1;
    y1 = -x + 2;
    if (y > y1) res = 1;
    else if (y == y1) res = 0;
    else res = -1;
    return res;
}

float Position(float x, float y) {
    int pos1, pos2, pos3;
    pos1 = PosForFirsline(x, y);
    pos2 = PosForSecondline(x, y);
    pos2 = PosForThirdline(x, y);
    if(pos1 == -1 && pos2 == 1 && pos3 == 1)printf("area 1");
    else if(pos1 == -1 && pos2 == 1 && pos3 == -1) printf("area 2");
    else if(pos1 == -1 && pos2 == -1 && pos3 == -1) printf("area 3");
    else if(pos1 == 1 && pos2 == -1 && pos3 == -1) printf("area 4");
    else if(pos1 == 1 && pos2 == -1 && pos3 == 1) printf("area 5");
    else if(pos1 == 1 && pos2 == 1 && pos3 == 1) printf("area 6");
    else if(pos1 == -1 && pos2 == -1 && pos3 == 1) printf("area 7");
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