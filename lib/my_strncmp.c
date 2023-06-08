/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** Reproduce the behavior of the strncmp function.
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n < 1)
        return 0;
    for (; i < n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0' && s2[i] == '\0')
            return 0;
    }
    return 0;
}
