/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** m
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[a] != '\0'; a++) {
        dest[i] = src[a];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncat(char *dest, char const *src, int n)
{
    int length = my_strlen(dest);
    int i = 0;

    for (; src[i] != 0 && i < n - 1; i++)
        dest[i + length] = src[i];
    dest[i] = '\0';
    return (dest);
}
