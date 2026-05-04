//
// Created by nono on 04/05/2026.
//

#ifndef STRING_PROJ_MY_STRING_H
#define STRING_PROJ_MY_STRING_H

#include "stddef.h"

size_t my_strlen(const char *s);
char *my_strpbrk(const char *s, const char *s2);
char *my_strcpy(const char *s);
char *my_strncpy(char *dst, size_t dst_sz, const char *src, size_t n);

#endif //STRING_PROJ_MY_STRING_H
