/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** team_context.c file.
*/

#include "core.h"

void handle_use_team_context(parameters_t *p, int i, str_to_args_t *args)
{
    char *uuid = NULL;

    if (is_team_validated(args->args[0]) == false) {
        return (invalid_team(p, i));
    }
    uuid = strdup(args->args[0]);
    if (uuid == NULL) {
        return;
    }
    my_free(p->team_uuids[i]);
    my_free(p->channel_uuids[i]);
    my_free(p->thread_uuids[i]);
    p->team_uuids[i] = uuid;
    valid_response(p, i);
}
