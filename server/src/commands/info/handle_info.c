/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_info.c file.
*/

#include "core.h"

void handle_info(parameters_t *p, int i, char *buffer)
{
    if (strcmp(buffer, "/info") != 0 || p->is_cmd_executed == true)
        return;
    if (p->team_uuids[i] != NULL
        && is_subscription_validated(p->uuids[i], p->team_uuids[i]) == false)
        return (invalid_subscription(p, i));
    if (p->team_uuids[i] == NULL && p->thread_uuids[i] == NULL
        && p->channel_uuids[i] == NULL)
        handle_info_no_context(p, i);
    if (p->team_uuids[i] != NULL && p->thread_uuids[i] == NULL
        && p->channel_uuids[i] == NULL)
        handle_info_team_context(p, i);
    if (p->team_uuids[i] != NULL && p->thread_uuids[i] == NULL
        && p->channel_uuids[i] != NULL)
        handle_info_channel_context(p, i);
    if (p->team_uuids[i] != NULL && p->thread_uuids[i] != NULL
        && p->channel_uuids[i] != NULL)
        handle_info_thread_context(p, i);
}
