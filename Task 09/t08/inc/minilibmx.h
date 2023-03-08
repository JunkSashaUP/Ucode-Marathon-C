#ifndef MINILIBMX_H
#define MINILIBMX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char * s);
void mx_printerr(const char *s);

int main(int argc, char *argv[]);
int calc(int argc, char *argv[]);

int mx_mod(int a, int b);
int mx_sub(int a, int b);
int mx_add(int a, int b);
int mx_mul(int a, int b);
int mx_div(int a, int b);

#endif

