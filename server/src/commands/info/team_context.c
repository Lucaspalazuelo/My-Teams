/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** team_context.c file.
*/

#include "core.h"

void handle_info_team_context(parameters_t *p, int i)
{
    char *line = search_file_line(DATA_TEAMS_PATH, p->team_uuids[i], 1,
        UUID_LENGTH);

    if (line == NULL) {
        return;
    }
    my_write(p->client_sockets[i], "OK TeamUUID/OwnerUUID/Name/Description: ");
    my_write(p->client_sockets[i], line);
    my_free(line);
    p->is_cmd_executed = true;
}
