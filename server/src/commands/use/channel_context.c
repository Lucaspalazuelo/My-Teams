/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** channel_context.c file.
*/

#include "core.h"

void handle_use_channel_context(parameters_t *p, int i, str_to_args_t *args)
{
    char *team_uuid = NULL;
    char *channel_uuid = NULL;

    if (is_channel_validated(args->args[1], args->args[0]) == false) {
        return (invalid_channel(p, i));
    }
    team_uuid = strdup(args->args[0]);
    channel_uuid = strdup(args->args[1]);
    if (team_uuid == NULL || channel_uuid == NULL) {
        my_free(team_uuid);
        my_free(channel_uuid);
        return;
    }
    my_free(p->team_uuids[i]);
    my_free(p->channel_uuids[i]);
    my_free(p->thread_uuids[i]);
    p->team_uuids[i] = team_uuid;
    p->channel_uuids[i] = channel_uuid;
    valid_response(p, i);
}
