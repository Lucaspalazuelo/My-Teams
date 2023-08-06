/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_create.c file.
*/

#include "core.h"

void handle_create(parameters_t *p, int i, char *buffer)
{
    char *prefix = "/create ";

    if (strncmp(buffer, prefix, strlen(prefix)) != 0
        || p->is_cmd_executed == true)
        return;
    if (p->team_uuids[i] != NULL
        && is_subscription_validated(p->uuids[i], p->team_uuids[i]) == false)
        return (invalid_subscription(p, i));
    if (p->team_uuids[i] == NULL && p->thread_uuids[i] == NULL
        && p->channel_uuids[i] == NULL)
        handle_create_no_context(p, i, buffer);
    if (p->team_uuids[i] != NULL && p->thread_uuids[i] == NULL
        && p->channel_uuids[i] == NULL)
        handle_create_team_context(p, i, buffer);
    if (p->team_uuids[i] != NULL && p->thread_uuids[i] == NULL
        && p->channel_uuids[i] != NULL)
        handle_create_channel_context(p, i, buffer);
    if (p->team_uuids[i] != NULL && p->thread_uuids[i] != NULL
        && p->channel_uuids[i] != NULL)
        handle_create_thread_context(p, i, buffer);
}
