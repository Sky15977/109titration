/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** this will return a number and as input get string
*/

#include "my.h"

static int check_str(char const *str, unsigned int i)
{
    unsigned int z = 0;

    for (z = i; str[z] != '\0';)
        if (str[z] >= '0' && str[z] <= '9')
            z++;
    z -= i;
    return z;
}

static int check_neg(char const *str, unsigned int *i, int compt)
{
    while (str[*i] == '-' || str[*i] == '+') {
        if (str[*i] == '-')
            compt *= -1;
        (*i)++;
    }
    return compt;
}

int my_getnbr(char const *str)
{
    unsigned int nb = 0;
    int	compt = 1;
    unsigned int	i = 0;
    unsigned int z = 0;

    compt = check_neg(str, &i, compt);
    z = check_str(str, i);
    if (z > 10)
        return 84;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - 48;
            i++;
        } else
            return (nb * compt);
    }
    return (nb * compt);
}
