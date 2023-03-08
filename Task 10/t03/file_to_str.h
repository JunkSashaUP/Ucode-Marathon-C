#ifndef HEAD_H
#define HEAD_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
int mx_strlen(const char * s);
char *mx_strnew(const int size);

char *mx_file_to_str(const char *filename);

#endif

