/*
** EPITECH PROJECT, 2023
** seconde_calculation.c
** File description:
** By Arthur M-D
*/

#include "titration.h"

static double calcul_center(titra_t *ti, int i, double backward, double forward)
{
    double alpha = ti->fir_deriv[i + 1][0] - ti->fir_deriv[i - 1][0];
    double alpha1 = ti->fir_deriv[i + 1][0] - ti->fir_deriv[i][0];
    double alpha2 = ti->fir_deriv[i][0] - ti->fir_deriv[i - 1][0];
    double diviseur = alpha1 * backward + alpha2 * forward;
    double res = diviseur / alpha;

    return res;
}

static double calcul_forward(titra_t *ti, int i)
{
    double taux = ti->fir_deriv[i + 1][1] - ti->fir_deriv[i][1];
    double dividende = ti->fir_deriv[i + 1][0] - ti->fir_deriv[i][0];
    double res = taux / dividende;

    return res;
}

static double calcul_backward(titra_t *ti, int i)
{
    double taux = ti->fir_deriv[i][1] - ti->fir_deriv[i - 1][1];
    double dividende = ti->fir_deriv[i][0] - ti->fir_deriv[i - 1][0];
    double res = taux / dividende;

    return res;
}

void sec_calcul(titra_t *ti)
{
    double backward = 0;
    double forward = 0;
    int y = 0;
    int length = 1;

    for (; ti->fir_deriv[length + 1] != NULL; length++);
    ti->sec_deriv = malloc(sizeof(double *) * (length));
    ti->sec_deriv[length - 1] = NULL;
    for (int x = 1; ti->fir_deriv[x + 1] != NULL; x++, y++)
        ti->sec_deriv[y] = malloc(sizeof(double) * 2);
    y = 0;
    for (int i = 1; ti->fir_deriv[i + 1] != NULL; i++, y++) {
        backward = calcul_backward(ti, i);
        forward = calcul_forward(ti, i);
        ti->sec_deriv[y][0] = ti->fir_deriv[i][0];
        ti->sec_deriv[y][1] = calcul_center(ti, i, backward, forward);
        printf("%.1f ml -> %.2f\n", ti->sec_deriv[y][0], ti->sec_deriv[y][1]);
    }
}
