/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** counts and returns the number of characters found
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
