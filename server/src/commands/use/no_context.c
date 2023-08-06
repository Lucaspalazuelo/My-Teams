/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** no_context.c file.
*/

#include "core.h"

void handle_use_no_context(parameters_t *p, int i)
{
    my_free(p->team_uuids[i]);
    my_free(p->channel_uuids[i]);
    my_free(p->thread_uuids[i]);
    valid_response(p, i);
}
