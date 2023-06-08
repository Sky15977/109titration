/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** dico func
*/

#include <stdio.h>

#include "my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef TITRATION_H
    #define TITRATION_H

    typedef struct titra_s {
        char *file;
        char **tab;
        double **infos;
        double **fir_deriv;
        double **sec_deriv;
        double **esti;
        int equi;
    } titra_t;

//error.c
    int isnum(char const *str);
    int manage_error(void);
    int manage_usage(void);

//init_struct.c
    double **init_titra_info(titra_t *ti);
    void init_struct_titra(titra_t *ti);

//process.c
    int process_titration(char *file);

//first_calculation.c
    void first_calcul(titra_t *titra);

//seconde_calculation.c
    void sec_calcul(titra_t *titra);

//search_biggest.c
    double search_biggest(titra_t *ti);

//search_close_to_zero.c
    int search_close_to_zero(titra_t *ti);

//third_calculation.c
    void third_calcul(titra_t *ti, int small_center);

#endif
