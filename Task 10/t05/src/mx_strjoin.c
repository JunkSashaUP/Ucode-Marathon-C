#include "../inc/header.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if(s1 == NULL && s2 == NULL) {
        return NULL;
    }
    if(s1 == NULL) {
        return mx_strdup(s2);
    }
    if(s2 == NULL) {
        return mx_strdup(s1);
    }
    char *result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    result = mx_strdup(mx_strcat(mx_strdup(s1), mx_strdup(s2)));
    return result;
}
