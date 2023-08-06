/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** thread_context.c file.
*/

#include "core.h"

void handle_info_thread_context(parameters_t *p, int i)
{
    char *line = search_file_line(DATA_THREADS_PATH, p->thread_uuids[i], 1,
        UUID_LENGTH);

    if (line == NULL) {
        return;
    }
    my_write(p->client_sockets[i], "OK ThreadUUID/ChannelUUID/OwnerUUID/Title/"
        "Message/Timestamp: ");
    my_write(p->client_sockets[i], line);
    my_free(line);
    p->is_cmd_executed = true;
}
