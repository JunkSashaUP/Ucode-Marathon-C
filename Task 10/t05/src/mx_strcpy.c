char* mx_strcpy(char * dst, const char * src) {
    char *tempptr = dst;
    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return tempptr;
}
