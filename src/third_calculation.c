/*
** EPITECH PROJECT, 2023
** third_calculation.c
** File description:
** third
*/

#include "titration.h"

void second_part(titra_t *ti, int small_center, int i)
{
    double delta_y = ti->sec_deriv[small_center + 1][1]
    - ti->sec_deriv[small_center][1];
    double delta_x = ti->sec_deriv[small_center + 1][0]
    - ti->sec_deriv[small_center][0];
    double alpha = delta_y / delta_x;
    double beta = ti->sec_deriv[small_center + 1][1]
    - (alpha * ti->sec_deriv[small_center + 1][0]);
    double f = 0;

    for (; ti->sec_deriv[small_center][0] + f < ti->sec_deriv[small_center + 1][0] + 0.1; f += 0.1, i++) {
        ti->esti[i][0] = ti->sec_deriv[small_center][0] + f;
        ti->esti[i][1] = alpha * (ti->sec_deriv[small_center][0] + f) + beta;
        printf("%.1f -> %.2f\n", ti->esti[i][0], ti->esti[i][1]);
    }
}

void third_calcul(titra_t *ti, int small_center)
{
    double delta_y = ti->sec_deriv[small_center][1] - ti->sec_deriv[small_center - 1][1];
    double delta_x = ti->sec_deriv[small_center][0] - ti->sec_deriv[small_center - 1][0];
    double alpha = delta_y / delta_x;
    double beta = ti->sec_deriv[small_center][1] - (alpha * ti->sec_deriv[small_center][0]);
    int counter = (ti->sec_deriv[small_center + 1][0] - ti->sec_deriv[small_center - 1][0]) * 10 + 1;
    double f = 0;
    int i = 0;

    ti->esti = malloc(sizeof(double *) * (counter + 1));
    ti->esti[counter] = NULL;
    for (int x = 0; x < counter; x++)
        ti->esti[x] = malloc(sizeof(double) * (2));
    for (; ti->sec_deriv[small_center - 1][0] + f < ti->sec_deriv[small_center][0]; f += 0.1, i++) {
        ti->esti[i][0] = ti->sec_deriv[small_center - 1][0] + f;
        ti->esti[i][1] = alpha * (ti->sec_deriv[small_center - 1][0] + f) + beta;
        printf("%.1f -> %.2f\n", ti->esti[i][0], ti->esti[i][1]);
    }
    second_part(ti, small_center, i);
}
