/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "titration.h"

int main(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0))
        manage_usage();
    if (ac != 2)
        manage_error();
    process_titration(av[1]);
    return 0;
}
