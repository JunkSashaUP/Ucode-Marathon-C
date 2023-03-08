#ifndef HEAD_H
#define HEAD_H

#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
int mx_strlen(const char * s);
char *mx_strnew(const int size);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printerr(const char *s);
void mx_printstr(const char *s);
int mx_count_words(const char *str);
void mx_printint(int n);

#endif
