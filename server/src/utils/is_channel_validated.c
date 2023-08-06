/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** is_channel_validated.c file.
*/

#include "core.h"

bool is_channel_validated(char *uuid, char *team_uuid)
{
    char *line = NULL;
    char *query = malloc(sizeof(char) * (UUID_LENGTH * 2 + 6));

    if (query == NULL) {
        return (false);
    }
    strcpy(query, "\"");
    strcat(query, uuid);
    strcat(query, "\" \"");
    strcat(query, team_uuid);
    strcat(query, "\"");
    line = search_file_line(DATA_CHANNELS_PATH, query, 0, UUID_LENGTH * 2 + 5);
    if (line == NULL) {
        my_free(query);
        return (false);
    }
    my_free(query);
    my_free(line);
    return (true);
}
