#include "my_string.h"
#include <stdlib.h>

size_t my_strlen(const char *s) {
    const char *p = s;

    while (*p) {
        p++;
    }

    return (size_t) (p - s);
}

char *my_strpbrk(const char *s, const char *s2) {
    if (!s || !s2) return nullptr;

    while (*s != '\0') {
        const char *a = s2;
        while (*a != '\0') {
            if (*s == *a)
                return (char *)s;
            a++;
        }
        s++;
    }

    return nullptr;
}


char *my_strcpy(const char *s) {
    if (!s) return nullptr;

    constexpr size_t TERMINATOR_SIZE = 1;

    const size_t len = my_strlen(s);
    char *const p = malloc(len + TERMINATOR_SIZE);

    if (!p) {
        free(p);
        return nullptr;
    }

    char *dst = p;

    while ((*dst++ = *s++)) {
    }

    return p;
}

char *my_strncpy(char *dst, const size_t dst_sz, const char *src, size_t n) {

    if (!dst || !src || dst_sz == 0) return nullptr;

    const size_t limit = n < dst_sz - 1 ? n : dst_sz - 1;

    size_t i = 0;

    while (i < limit && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }

    dst[i] = '\0';

    return dst;
}


