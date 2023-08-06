/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** is_team_validated.c file.
*/

#include "core.h"

bool is_team_validated(char *uuid)
{
    char *line = search_file_line(DATA_TEAMS_PATH, uuid, 1, UUID_LENGTH);

    if (line == NULL) {
        return (false);
    }
    my_free(line);
    return (true);
}
