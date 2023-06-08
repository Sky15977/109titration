/*
** EPITECH PROJECT, 2023
** calculation.c
** File description:
** By Arthur M-D
*/

#include "titration.h"

static double calcul_center(titra_t *ti, int i, double backward, double forward)
{
    double alpha = ti->infos[i + 1][0] - ti->infos[i - 1][0];
    double alpha1 = ti->infos[i + 1][0] - ti->infos[i][0];
    double alpha2 = ti->infos[i][0] - ti->infos[i - 1][0];
    double diviseur = alpha1 * backward + alpha2 * forward;
    double res = diviseur / alpha;

    return res;
}

static double calcul_forward(titra_t *ti, int i)
{
    double taux = ti->infos[i + 1][1] - ti->infos[i][1];
    double dividende = ti->infos[i + 1][0] - ti->infos[i][0];
    double res = taux / dividende;

    return res;
}

static double calcul_backward(titra_t *ti, int i)
{
    double taux = ti->infos[i][1] - ti->infos[i - 1][1];
    double dividende = ti->infos[i][0] - ti->infos[i - 1][0];
    double res = taux / dividende;

    return res;
}

void first_calcul(titra_t *ti)
{
    double backward = 0;
    double forward = 0;
    int y = 0;
    int length = 1;

    for (; ti->infos[length + 1] != NULL; length++);
    ti->fir_deriv = malloc(sizeof(double *) * (length));
    ti->fir_deriv[length - 1] = NULL;
    for (int x = 1; ti->infos[x + 1] != NULL; x++, y++)
        ti->fir_deriv[y] = malloc(sizeof(double) * 2);
    y = 0;
    for (int i = 1; ti->infos[i + 1] != NULL; i++, y++) {
        backward = calcul_backward(ti, i);
        forward = calcul_forward(ti, i);
        ti->fir_deriv[y][0] = ti->infos[i][0];
        ti->fir_deriv[y][1] = calcul_center(ti, i, backward, forward);
        printf("%.1f ml -> %.2f\n", ti->fir_deriv[y][0], ti->fir_deriv[y][1]);
    }
}
