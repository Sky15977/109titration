/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** free my alloc
*/

#include "my.h"

void free_tab(char **tab)
{
    for (unsigned int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
