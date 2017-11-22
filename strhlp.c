//
// Created by cengiz on 22/11/17.
//
#include <stdio.h>
#include "strhlp.h"
#include <stdarg.h>

int printWarning(const char *format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    printf("%s", KYEL);
    result = vprintf(format, args);
    va_end(args);
    printf("%s", KNRM);
    return result;
}

int printSuccess(const char *format, ...) {

    int result = 0;
    va_list args;
    va_start(args, format);
    printf("%s", KGRN);
    result = vprintf(format, args);
    va_end(args);
    printf("%s", KNRM);
    return result;
}

int printDanger(const char *format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    printf("%s", KRED);
    result = vprintf(format, args);
    va_end(args);
    printf("%s", KNRM);
    return result;
};

int printText(const char *format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    printf("%s", KNRM);
    result = vprintf(format, args);
    va_end(args);

    return result;
}

int printInfo(const char *format, ...) {
    int result = 0;
    va_list args;
    va_start(args, format);
    printf("%s", KBLU);
    result = vprintf(format, args);
    va_end(args);
    printf("%s", KNRM);
    return result;
}