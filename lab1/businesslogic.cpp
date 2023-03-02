#include "businesslogic.h"

double calc(arifmeticInput Input) {
    switch (Input.sign) {
    case '+':
        Input.result += Input.num;
        break;
    case '-':
        Input.result -= Input.num;
        break;
    case '*':
        Input.result *= Input.num;
        break;
    case '/':
        Input.result *= Input.num;
        break;
    }
    return Input.result;
}
