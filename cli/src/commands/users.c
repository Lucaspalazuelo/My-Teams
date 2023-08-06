/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** users
*/

#include "cli.h"

void users(parameters_t *p)
{
    char **temp = my_str_to_word_array(p->argv[p->count - 1], " \r\n\t");

    for (int i = 0; temp[i] != NULL; i++) {
        if (strncmp(temp[i], "OK", 2) == 0)
            print_loop_users(p);
    }
}

void print_loop_users(parameters_t *p)
{
    char *buffer = tab_to_str(p->argv, p->count);
    char **tab = my_str_to_word_array(buffer, "\n");
    str_to_args_t *args = NULL;
    int status = 0;
    int size = 0;

    for (int i = 0; tab[i] != NULL; i++)
        size++;
    for (int i = 0; i < size - 1; i++) {
        args = str_to_args(tab[i]);
        if (strcmp(args->args[0], "connected") == 0)
            status = 1;
        client_print_users(args->args[1], args->args[2], status);
        str_to_args_destroy(args);
        status = 0;
    }
    free_tab(p);
}
