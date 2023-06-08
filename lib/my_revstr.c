/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** Write a function that reverses a string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char c = str[0];
    int nb = my_strlen(str) - 1;

    while (i <= nb / 2 + 1) {
        c = str[i];
        str[i] = str[nb];
        str[nb] = c;
        i++;
        nb--;
    }
    return (str);
}
