/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** thread_context.c file.
*/

#include "core.h"

void handle_use_thread_context(parameters_t *p, int i, str_to_args_t *args)
{
    char *team_uuid = NULL;
    char *channel_uuid = NULL;
    char *thread_uuid = NULL;

    if (!is_thread_validated(args->args[2], args->args[0], args->args[1]))
        return (invalid_thread(p, i));
    if ((team_uuid = strdup(args->args[0])) == NULL
        || (channel_uuid = strdup(args->args[1])) == NULL
        || (thread_uuid = strdup(args->args[2])) == NULL) {
        my_free(team_uuid);
        my_free(channel_uuid);
        return (my_free(thread_uuid));
    }
    my_free(p->team_uuids[i]);
    my_free(p->channel_uuids[i]);
    my_free(p->thread_uuids[i]);
    p->team_uuids[i] = team_uuid;
    p->channel_uuids[i] = channel_uuid;
    p->thread_uuids[i] = thread_uuid;
    valid_response(p, i);
}
