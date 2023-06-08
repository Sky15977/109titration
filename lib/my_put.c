/*
** EPITECH PROJECT, 2022
** all_put
** File description:
** all_put
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

void put_tab(char **tab)
{
    for (int y = 0; tab[y] != NULL; y++) {
        my_putstr(tab[y]);
        write(1, "\n", 1);
    }
}

int my_putnbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        count++;
    }
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + 48);
        count++;
        return (count);
    }
    count++;
    count += my_putnbr(nb / 10);
    my_putchar ((nb % 10) + 48);
    return (count);
}

int my_putnbr_base(int nbr, char const *base)
{
    int count = 0;
    int nb_base = my_strlen(base);

    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
        count++;
    }
    if (nbr >= 0 && nbr < nb_base) {
        my_putchar(base[nbr]);
        count++;
        return (count);
    }
    count++;
    count += my_putnbr_base((nbr / nb_base), base);
    my_putchar (base[nbr % nb_base]);
    return (count);
}
