/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** user
*/

#include "cli.h"

void user(parameters_t *p)
{
    str_to_args_t *args = str_to_args(p->argv[0]);
    int status = 0;

    if (args->nb_args == 0 || p->uuid == NULL || p->name == NULL) {
        client_error_unknown_user(args->args[0]);
        return;
    }
    if (strcmp(args->args[0], "connected") == 0)
        status = 1;
    client_print_user(args->args[1], args->args[2], status);
    free_tab(p);
}
