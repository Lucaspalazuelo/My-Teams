/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** is_subscription_validated.c file.
*/

#include "core.h"

bool is_subscription_validated(char *user_uuid, char *team_uuid)
{
    char *line = NULL;
    char *query = malloc(sizeof(char) * (UUID_LENGTH * 2 + 6));

    if (query == NULL) {
        return (false);
    }
    strcpy(query, "\"");
    strcat(query, user_uuid);
    strcat(query, "\" \"");
    strcat(query, team_uuid);
    strcat(query, "\"");
    line = search_file_line(DATA_SUBS_PATH, query, 0, (int)strlen(query));
    my_free(query);
    if (line == NULL) {
        return (false);
    }
    my_free(line);
    return (true);
}
