/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** char* in char**
*/

#include "my.h"

int len_word(char const *str, int i, char c)
{
    int a = 0;

    for (; str[i] != c && str[i]; i++)
        a++;
    return a;
}

int count(char const *str, char c)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
            a++;
    return a;
}

char **my_str_to_word_array(char const *str, char c)
{
    int nb_word = count(str, c);
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    int y = 0;
    int x = 0;
    int i = 0;

    for (; y < nb_word; y++) {
        for (; str[i] == c && str[i]; i++);
        tab[y] = malloc(sizeof(char) * (len_word(str, i, c) + 1));
        for (x = 0; str[i] != c && str[i]; x++) {
            tab[y][x] = str[i];
            i++;
        }
        tab[y][x] = '\0';
    }
    tab[y] = NULL;
    put_tab(tab);
    return tab;
}
