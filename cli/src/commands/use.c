/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** use
*/

#include "cli.h"

void use(parameters_t *p, char *buffer)
{
    str_to_args_t *args = str_to_args(buffer);

    if (args->nb_args == 0)
        p->context = TEAM;
    if (args->nb_args == 1)
        p->context = CHANNEL;
    if (args->nb_args == 2)
        p->context = THREAD;
    if (args->nb_args == 3)
        p->context = REPLY;
}
