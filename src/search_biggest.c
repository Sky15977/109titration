/*
** EPITECH PROJECT, 2023
** search_biggest.c
** File description:
** By Arthur M-D
*/

#include "titration.h"

double search_biggest(titra_t *ti)
{
    double buffer = ti->fir_deriv[0][1];
    int res = 0;

    for (int i = 1; ti->fir_deriv[i] != NULL; i++) {
        if (ti->fir_deriv[i][1] > buffer) {
            res = i;
            buffer = ti->fir_deriv[i][1];
        }
    }
    return res;
}
