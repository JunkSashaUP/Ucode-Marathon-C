#include "../inc/header.h"

char *mx_strnew(const int size) {
    if(size < 1) {
        return NULL;
    }
    char *result = (char *)malloc(size + 1);
    for(int i = 0; i <= size; i++) {
        result[i] = '\0';
    }
    return result;
}
