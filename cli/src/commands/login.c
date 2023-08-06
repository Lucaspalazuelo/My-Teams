/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** login
*/

#include "cli.h"

void login(parameters_t *p)
{
    str_to_args_t *args = str_to_args(p->argv[0]);
    char *name = strdup(args->args[0]);
    char *uuid = strdup(args->args[1]);

    if (uuid == NULL || name == NULL)
        return;
    p->uuid = strdup(uuid);
    p->name = strdup(name);
    client_event_logged_in(uuid, name);
    free_tab(p);
}
