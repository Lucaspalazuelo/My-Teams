/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** unsubscribe
*/

#include "cli.h"

void unsubscribe(parameters_t *p)
{
    str_to_args_t *args = str_to_args(p->argv[0]);

    if (args->nb_args == 0)
        client_error_unauthorized();
    else
        client_print_unsubscribed(p->uuid, args->args[0]);
    free_tab(p);
}
