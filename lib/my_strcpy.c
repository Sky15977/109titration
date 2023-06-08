/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Copy a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; i == 0 || src[i - 1] != '\0'; i++) {
        dest[i] = src[i];
    }
    return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n - 1; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';
    return (dest);
}
