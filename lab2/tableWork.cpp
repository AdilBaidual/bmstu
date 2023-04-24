#include "tableWork.h"

int getHeaderLen(std::string line);
char **parseLine(std::string str, int headerLen);
bool checkLine(char **data, int headerLen, const char *region);
void cleareMatrix(char **data, int len);
void replaceDoubleCommas(char *str);

tableStruct getData(const char *path, const char *region, int colum) {
    tableStruct table;
    table.error = false;
    int buf = 5;
    char ***data = (char ***)malloc(sizeof(char **) * buf);
    int rowLen = 0;
    int headerLen = 0;
    if (data != NULL) {
        std::string line;
        std::ifstream in(path);
        if (in.is_open()) {
            while (getline(in, line)) {
                if (rowLen == 0) {
                    headerLen = getHeaderLen(line);
                    if (colum > headerLen) {
                        free(data);
                        table.error = true;
                        break;
                    }
                }
                data[rowLen] = parseLine(line, headerLen);
                if (data[rowLen] == NULL) {
                    //возвращать ошибку но выводить
                    table.error = true;
                    continue;
                }
                if (checkLine(data[rowLen], headerLen, region) && rowLen != 0) {
                    //очистка data[rowLen]
                    cleareMatrix(data[rowLen], headerLen);
                    continue;
                }
                if (buf == 0) {
                    buf = 5;
                    data = (char ***)realloc(data, sizeof(char **) * (rowLen + buf));
                    if (data == NULL) {
                        break;
                    }
                }
                buf--;
                rowLen++;
            }
            data = (char ***)realloc(data, sizeof(char **) * rowLen);
            in.close();
        }
    }
    table.data = data;
    table.rowLen = rowLen;
    table.collumLen = headerLen;
    return table;
}


int getHeaderLen(std::string line) {
    int headerLen = 1;
    for (int i = 0; i < (int)line.length(); i++) {
        if (line[i] == ',') {
            headerLen++;
        }
    }
    return headerLen;
}


char **parseLine(std::string str, int headerLen) {
    char *tmpStr = (char *)str.c_str();
    char **data = (char **)malloc(sizeof(char *) * headerLen);
    //replaceDoubleCommas(tmpStr);
    qDebug() << "DATA: " << tmpStr;
    int start = 0;
    int indx = 0;
    int len = strlen(tmpStr);
    char *tmp;
    if (data != NULL) {
        for (int i = 0; i < len; i++) {
            if (tmpStr[i] == ',' || i == len - 1) {
                int size = i-start;
                if (i == len - 1) {
                    size++;
                }
                qDebug() << "SIZE: " << i << start << size;
                qDebug() << "SIZE: " << indx;
                if (size != 0) {
                    //tmp = (char *)calloc(size, sizeof(char));
                    //qDebug() << "SUB: " << tmp;
                    //strncpy(tmp, tmpStr+start, size);
                    tmp = "+";
                } else {
                    tmp = "-";
                }

                //qDebug() << "SUB: " << tmp;
                start = i + 1;
                *(data + indx) = tmp;
                indx++;
            }
        }
    }
//    for (int i = 0; i < len; i++) {
//        qDebug() << "DATA: " << data[i];
//    }
    return data;
}

bool checkLine(char **data, int headerLen, const char *region) {
    bool res = true;
    for (int i = 0; i < headerLen; i++) {
        if (strcmp(region, *(data + i)) == 0) {
            res = false;
            break;
        }
    }
    return res;
}

void cleareMatrix(char **data, int len) {
    for (int i = 0; i < len; i++) {
        free(data[i]);
    }
    free(data);
    data = NULL;
}

void replaceDoubleCommas(char *str) {
    int len = strlen(str);
    int i = 0;
    while (i < len - 1) {
        if (str[i] == ',' && str[i + 1] == ',') {
            memmove(&str[i + 2], &str[i + 1], len - i - 1);
            str[i + 1] = ' ';
            len++;

        }
        i++;
    }
    if (str[len - 1] == ',') {
            str[len - 1] = ',';
            str[len] = ' ';
            str[len + 1] = '\0';
        }
}
