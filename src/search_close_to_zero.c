/*
** EPITECH PROJECT, 2023
** search_close_to_zero.c
** File description:
** By Arthur M-D
*/

#include "titration.h"

int search_close_to_zero(titra_t *ti)
{
    double buffer = 0 - ti->esti[0][1];
    int res = 0;

    if (ti->esti[0][1] < 0)
        buffer = 0 - ti->esti[0][1];
    if (ti->esti[0][1] > 0)
        buffer = 0 + ti->esti[0][1];
    for (int i = 1; ti->esti[i] != NULL; i++) {
        if (ti->esti[i][1] > 0 && 0 + ti->esti[i][1] < buffer) {
            res = i;
            buffer = 0 + ti->esti[i][1];
        }
        if (ti->esti[i][1] < 0 && 0 - ti->esti[i][1] < buffer) {
            res = i;
            buffer = 0 - ti->esti[i][1];
        }
    }
    return res;
}
