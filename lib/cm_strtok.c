/*
** EPITECH PROJECT, 2023
** str_to_word_array_cm.c
** File description:
** str_to_word_array_cm
*/

#include "my.h"

int is_separator(char a, char c)
{
    if (a == c || (a > 6 && a < 14))
        return 1;
    else
        return 0;
}

int len_of_word(char *str, char c)
{
    int i = 0;

    for (; str[i]; i++)
        if (is_separator(str[i], c) != 0)
            return i;
    return i;
}

int nb_word(char *str, char c)
{
    int i = 0;
    int nb = 0;

    for (; str[i]; i++) {
        if (is_separator(str[i], c) == 0 && is_separator(str[i + 1], c))
            nb++;
    }
    return nb;
}

char **cm_strtok(char *str, char c)
{
    int nb = nb_word(str, c);
    int i = 0;
    int y = 0;
    int x = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (nb + 1));
    tab[nb] = NULL;
    for (; y < nb; i++) {
        for (; is_separator(str[i], c) != 0; i++);
        tab[y] = malloc(sizeof(char) * (len_of_word(&str[i], c) + 1));
        for (x = 0; is_separator(str[i], c) != 1; i++) {
            tab[y][x] = str[i];
            x++;
        }
        tab[y][x] = '\0';
        y++;
    }
    return tab;
}
