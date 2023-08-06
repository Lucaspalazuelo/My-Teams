/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_use.c file.
*/

#include "core.h"

void handle_use(parameters_t *p, int i, char *buffer)
{
    char *prefix = "/use";
    str_to_args_t *args = NULL;

    if (strncmp(buffer, prefix, strlen(prefix)) != 0
        || p->is_cmd_executed == true)
        return;
    args = str_to_args(buffer);
    if (args == NULL)
        return;
    if (args->nb_args == 0)
        handle_use_no_context(p, i);
    if (args->nb_args == 1)
        handle_use_team_context(p, i, args);
    if (args->nb_args == 2)
        handle_use_channel_context(p, i, args);
    if (args->nb_args == 3)
        handle_use_thread_context(p, i, args);
    str_to_args_destroy(args);
}
