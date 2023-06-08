/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** lib
*/

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef MY_SOKOBAN_H
    #define MY_SOKOBAN_H

    typedef struct list_node_s {
        void *value;
        struct list_node_s *next;
        struct list_node_s *prev;
    } list_node_t;

    typedef struct list_s {
        list_node_t *head;
        list_node_t *tail;
        unsigned int size;
    } list_t;

    char *my_strcpy(char *dest, char const *src);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_isneg(int nb);
    char *my_revstr(char *str);
    char *my_strdup(char const *src);
    char *my_strupcase(char *str);
    void my_swap(int *a, int *b);
    int my_strncmp(char const *s1, char const *s2, int n);
    void free_tab(char **tab);

//cm_strtok.c
    int is_separator(char a, char c);
    int len_of_word(char *str, char c);
    int nb_word(char *str, char c);
    char **cm_strtok(char *str, char c);

//my_put.c
    void my_putchar(char c);
    int my_putstr(char const *str);
    void put_tab(char **tab);
    int my_putnbr(int nb);
    int my_putnbr_base(int nbr, char const *base);

//my_getnbr.c
    int my_getnbr(char const *str);

//my_str.c
    int my_strlen(char const *str);
    char *my_strcat(char *dest, char const *src);

//my_strcat.c
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int n);

//my_str_is.c
    int my_str_isalpha(char const *str);
    int my_str_islower(char const *str);
    int my_str_isnum(char const *str);
    int my_str_isprintable(char const *str);
    int my_str_isupper(char const *str);

//my_str_to_word_array.c
    int len_word(char const *str, int i, char c);
    int count(char const *str, char c);
    char **my_str_to_word_array(char const *str, char c);

//list_add.c
    unsigned int list_add(list_t *list, void *value);
    list_t *list_create(void);

//list_get.c
    void *list_get_node(list_t *list, unsigned int index);
    void *list_get(list_t *list, unsigned int index);
    void list_remove(list_t *list, unsigned int index);

#endif
