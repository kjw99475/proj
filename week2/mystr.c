#include "mystr.h"

size_t my_strlen(const char *s) {
    size_t n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

char *my_strcpy(char *dst, const char *src) {
    size_t i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

int my_strcmp(const char *a, const char *b) {
    while (*a != '\0' && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}
