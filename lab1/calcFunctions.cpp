#include "calcFunctions.h"
#include <string.h>

int strcount(const char *str, char val) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (*(str + i) == val) {
            count++;
        }
    }
    return count;
}

int rfind(const char *str) {
    int len = strlen(str);
    int result = -1;
    for (int i = len - 1; i >= 0; i--) {
        if (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == '*' || *(str + i) == '/') {
            result = i;
            break;
        }
    }
    return result;
}

int my_strstr(const char* str, const char* substr) {
    while (*str) {
        const char* p1 = str;
        const char* p2 = substr;
        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (!*p2) {
            return 1;
        }
        str++;
    }
    return 0;
}

int isNumber(char c) {
    int res = 0;
    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0')
        res = 1;
    return res;
}

int isSign(char c) {
    int res = 0;
    if (c == '+' || c == '-' || c == '*' || c == '/')
        res = 1;
    return res;
}

int checkE(const char *data) {
    int res = 0;
    if (strcount(data, 'e') != 0)
        res = 1;
    return res;
}
