/*
** EPITECH PROJECT, 2023
** process.c
** File description:
** pro
*/

#include "titration.h"

char *fs_openfile(char *filepath)
{
    struct stat sb;
    int fd = open(filepath, O_RDONLY);
    char *str = NULL;

    if (fd == -1)
        exit(84);
    if (stat(filepath, &sb) == -1) {
        write(1, "DO NOT FIND THE FILE\n", 20);
        exit(84);
    }
    if (sb.st_size == 0) {
        write(1, "EMPTY FILE\n", 11);
        exit(84);
    }
    str = malloc(sizeof(char) * (sb.st_size + 1));
    read(fd, str, sb.st_size);
    str[sb.st_size] = '\0';
    close(fd);
    return str;
}

void call_calcul_func(titra_t *ti)
{
    int res = 0;

    printf("Derivative:\n");
    first_calcul(ti);
    ti->equi = search_biggest(ti);
    printf("\nEquivalence point at %.1f ml\n\n", ti->fir_deriv[ti->equi][0]);
    printf("Second derivative:\n");
    sec_calcul(ti);
    printf("\nSecond derivative estimated:\n");
    third_calcul(ti, ti->equi - 1);
    res = search_close_to_zero(ti);
    printf("\nEquivalence point at %.1f ml\n", ti->esti[res][0]);
}

int process_titration(char *file)
{
    titra_t *ti = malloc(sizeof(titra_t));

    init_struct_titra(ti);
    ti->file = fs_openfile(file);
    ti->tab = cm_strtok(ti->file, ';');
    free(ti->file);
    ti->infos = init_titra_info(ti);
    free_tab(ti->tab);
    call_calcul_func(ti);
    return 0;
}
