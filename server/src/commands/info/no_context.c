/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** no_context.c file.
*/

#include "core.h"

void handle_info_no_context(parameters_t *p, int i)
{
    char *line = search_file_line(DATA_USERS_PATH, p->uuids[i], 1, UUID_LENGTH);

    if (line == NULL) {
        return;
    }
    my_write(p->client_sockets[i], "OK Status/UUID/Username: \"connected\" ");
    my_write(p->client_sockets[i], line);
    my_free(line);
    p->is_cmd_executed = true;
}
