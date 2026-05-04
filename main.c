#include <stdio.h>

#include "include/my_string.h"

int main(void) {

    constexpr char DEFAULT_STR[13]= "Hello World!";

    const size_t n = my_strlen(DEFAULT_STR);
    char dest[5];

    printf("O tamanho da string e de %lu caracteres.\n", n);
    printf("%s\n", my_strcpy(DEFAULT_STR));
    printf("\"%c\" no indice %ld\n", my_strpbrk(DEFAULT_STR, "gW")[0], my_strpbrk(DEFAULT_STR, "gW") - DEFAULT_STR);
    printf("%s\n", my_strncpy(dest, sizeof(dest) / sizeof(dest[0]), DEFAULT_STR + 6, 5));

    return 0;
}