/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** is_thread_validated.c file.
*/

#include "core.h"

bool is_thread_validated(char *uuid, char *team_uuid, char *channel_uuid)
{
    char *line = NULL;
    char *query = NULL;

    if (is_channel_validated(channel_uuid, team_uuid) == false)
        return (false);
    if ((query = malloc(sizeof(char) * (UUID_LENGTH * 2 + 6))) == NULL)
        return (false);
    strcpy(query, "\"");
    strcat(query, uuid);
    strcat(query, "\" \"");
    strcat(query, channel_uuid);
    strcat(query, "\"");
    line = search_file_line(DATA_THREADS_PATH, query, 0, UUID_LENGTH * 2 + 5);
    if (line == NULL) {
        my_free(query);
        return (false);
    }
    my_free(query);
    my_free(line);
    return (true);
}
