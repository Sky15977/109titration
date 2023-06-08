/*
** EPITECH PROJECT, 2023
** init_struct.c
** File description:
** By Arthur M-D
*/

#include "titration.h"

double **init_titra_info(titra_t *ti)
{
    unsigned int i = 0;
    unsigned int y = 0;
    double **info = NULL;

    for (; ti->tab[y]; y++);
    info = malloc(sizeof(double *) * ((y / 2) + 1));
    if (y < 14 || y % 2 != 0)
        manage_error();
    y = 0;
    for (; ti->tab[i]; i++) {
        if (isnum(ti->tab[i]) != 0)
            manage_error();
        if (i % 2 != 0) {
            info[y][1] = atof(ti->tab[i]);
            y++;
        } else {
            info[y] = malloc(sizeof(double) * 2);
            info[y][0] = atof(ti->tab[i]);
        }
    }
    info[y] = NULL;
    return info;
}

void init_struct_titra(titra_t *ti)
{
    ti->file = NULL;
    ti->tab = NULL;
    ti->infos = NULL;
    ti->fir_deriv = NULL;
    ti->sec_deriv = NULL;
    ti->esti = NULL;
}
