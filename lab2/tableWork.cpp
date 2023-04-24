#include "tableWork.h"

int getHeaderLen(std::string line);
char **parseLine(std::string str, int headerLen);
bool checkLine(char **data, int headerLen, const char *region);
void cleareMatrix(char **data, int len);
void replaceDoubleCommas(char *str);

tableStruct getData(const char *path, const char *region, int colum) {
    //qDebug() << "REGION: " << region;
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
                qDebug() << "REGION 1: " << region;
                data[rowLen] = parseLine(line, headerLen);
                qDebug() << "REGION 2: " << region;
                if (data[rowLen] == NULL) {
                    //возвращать ошибку но выводить
                    table.error = true;
                    continue;
                }
//                if (checkLine(data[rowLen], headerLen, region) && rowLen != 0) {
//                    //очистка data[rowLen]
//                    free(data[rowLen]);
//                    continue;
//                } else {
//                    //qDebug() << data[rowLen][0] << data[rowLen][1] << data[rowLen][2] << data[rowLen][3] << data[rowLen][4] << data[rowLen][5] << data[rowLen][6];
//                    rowLen++;
//                    buf--;
//                }
                rowLen++;
                buf--;
                if (buf == 0) {
                    buf = 5;
                    data = (char ***)realloc(data, sizeof(char **) * (rowLen + buf));
                    if (data == NULL) {
                        break;
                    }
                }
            }
            //qDebug() << "DONE";
            data = (char ***)realloc(data, sizeof(char **) * rowLen);
            //qDebug() << "DONE2";
            in.close();
        }
    }
    table.data = data;
    table.rowLen = rowLen;
    table.collumLen = headerLen;
    //qDebug() << "DONE3";
    //qDebug() << "REGION: " << region;
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


//char **parseLine(std::string str, int headerLen) {
//    char *tmpStr = (char *)str.c_str();
//    char **data = (char **)malloc(sizeof(char *) * headerLen);
//    //replaceDoubleCommas(tmpStr);
//    //qDebug() << "DATA: " << tmpStr;
//    int start = 0;
//    int indx = 0;
//    int len = strlen(tmpStr);
//    char *tmp;
//    if (data != NULL) {
//        for (int i = 0; i < len; i++) {
//            if (tmpStr[i] == ',' || i == len - 1) {
//                int size = i-start;
//                if (i == len - 1) {
//                    size++;
//                }
//                //qDebug() << "SIZE: " << i << start << size;
//                //qDebug() << "SIZE: " << indx;
//                if (size != 0) {
//                    //tmp = (char *)calloc(size, sizeof(char));
//                    ////qDebug() << "SUB: " << tmp;
//                    //strncpy(tmp, tmpStr+start, size);
//                    tmp = "+";
//                } else {
//                    tmp = "-";
//                }

//                ////qDebug() << "SUB: " << tmp;
//                start = i + 1;
//                *(data + indx) = tmp;
//                indx++;
//            }
//        }
//    }
////    for (int i = 0; i < len; i++) {
////        //qDebug() << "DATA: " << data[i];
////    }
//    return data;
//}


char **parseLine(std::string str, int headerLen) {
    char **data = (char **)malloc(sizeof(char *) * headerLen);
    std::string delimiter = ",";
    size_t pos = 0;
    char *empty = "-";
    std::string token;
    int i = 0;
//    qDebug() << "LINE: " << str.c_str() << headerLen;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        if (token.empty()) {
            data[i] = strdup(empty);
        } else {
            char *tmp = (char *)token.c_str();
            data[i] = strdup(tmp);
        }
        str.erase(0, pos + delimiter.length());
        i++;
    }
    if (str.empty()) {
        data[i] = strdup(empty);
    } else {
        char *tmp = (char *)str.c_str();
        data[i] = strdup(tmp);
    }
    return data;
}


bool checkLine(char **data, int headerLen, const char *region) {
    bool res = true;
    //qDebug() << "REGION CHECK 1: " << region;
    for (int i = 0; i < headerLen; i++) {
        if (strcmp(region, *(data + i)) == 0) {
            //qDebug() << "REGION CHECK 2: " << region;
            res = false;
            break;
        } else {
            //qDebug() << "REGION CHECK 3: " << region;
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
