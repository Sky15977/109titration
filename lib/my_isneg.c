/*
** EPITECH PROJECT, 2023
** my_isneg.c
** File description:
**  write N for number <0, write P for number >=0
*/

#include "my.h"

int my_isneg(int nb)
{
    if (nb >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
