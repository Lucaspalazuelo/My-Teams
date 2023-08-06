/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** subscribe
*/

#include "cli.h"

void subscribe(parameters_t *p)
{
    str_to_args_t *args = str_to_args(p->argv[0]);

    if (args->nb_args == 0)
        client_error_unauthorized();
    else
        client_print_subscribed(p->uuid, args->args[0]);
    free_tab(p);
}
