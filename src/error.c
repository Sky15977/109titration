/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** error
*/

#include "titration.h"

int isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
            return 1;
    return 0;
}

int manage_error(void)
{
    my_putstr("./countwords: bad arguments\n");
    my_putstr("retry with -h\n");
    exit(84);
}

int manage_usage(void)
{
    my_putstr("USAGE\n   ./109titration file\n\nDescription\n   ");
    my_putstr("file    a csv file containing \"vol;ph\" lines\n");
    exit(0);
}
