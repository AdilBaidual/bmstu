#ifndef TABLEWORK_H
#define TABLEWORK_H

#include <fstream>
#include "mainwindow.h"
#include "string.h"
#include <iostream>
#include <string>

typedef struct {
    char ***data;
    int rowLen;
    int collumLen;
    bool error;
} tableStruct;

tableStruct getData(const char *path, const char *region, int colum);

#endif // TABLEWORK_H
